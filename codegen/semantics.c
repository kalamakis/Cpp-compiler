#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "types.h"
#include <stdbool.h>
#include "ast.h"
#include "symbol.h"
#include "symbolTable.h"
#include "hashtable.h"
#include "string.h"

#include "semantics.h"

#define MAX_PARAMS 64

static ParamInfo current_params[MAX_PARAMS];
static int       current_param_count = 0;
static Symbol *current_function_symbol = NULL;
static int collecting_signature = 0;
static int current_param_index = 0;

//Loop scope
static int loop_nesting_level = 0;

//ENUMS
static Type *current_enum_processing_type = NULL;
static int   current_enum_counter = 0;
static int  sem_in_function = 0;

static long sem_param_next_off = 0;  // positive offsets from $fp
static long sem_local_bytes    = 0;  // grows positive, stored as negative offsets
static long sem_max_local      = 0;  // maximum local usage

#define SEM_MAX_SCOPE_DEPTH 1024
static long sem_scope_saved[SEM_MAX_SCOPE_DEPTH];
static int  sem_scope_sp = 0;

static const long SEM_PARAM_BASE_FP = 8; // MIPS32 (saved fp/ra above)

void sem_fatal(const char *fmt, ...){
    va_list ap;
    fprintf(stderr, "Semantic error: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}

Type *sem_use_variable(const char *name, int line){
    Symbol *s = symtab_lookup(name);
    if (!s) {
        sem_fatal("undeclared identifier '%s' at line %d", name, line);
    }
    
    int is_valid = 0;
    
    if (s->kind == SYM_VAR || s->kind == SYM_CONST || 
        s->kind == SYM_PARAM || s->kind == SYM_ENUM_CONST || 
        s->kind == SYM_FUNC) {
        is_valid = 1;
    } 
    else if (s->kind == SYM_TYPE && s->type && s->type->kind == TYPE_ENUM) {
        is_valid = 1;
    }

    if (!is_valid) {
        sem_fatal("'%s' is not a variable, function, or enum type at line %d", name, line);
    }

    if (!s->type) {
        sem_fatal("identifier '%s' has no type information (line %d)", name, line);
    }

    return s->type;
}

int is_basic(TypeKind k){
    return (k == TYPE_INT || k == TYPE_FLOAT ||k == TYPE_CHAR ||k == TYPE_STRING);
}
int is_numeric(TypeKind k){
    return (k == TYPE_INT || k == TYPE_FLOAT);
}
int is_enum(TypeKind k){
    return (k == TYPE_ENUM);
}

int is_list(TypeKind k){
    return (k == TYPE_LIST);
}

//array/list/class/union
static int is_composite(TypeKind k){
    return (k == TYPE_ARRAY ||k == TYPE_LIST || k == TYPE_CLASS || k == TYPE_UNION);
}

//class field lookup
Symbol *sem_lookup_field_symbol(Type *base, const char *field_name, int line)
{
    if (!base || base == type_error) {
        sem_fatal("invalid base in field access '.%s' at line %d", field_name, line);
    }

    Type *t = base;
    while (t) {
        if (t->kind != TYPE_CLASS && t->kind != TYPE_UNION) {
            sem_fatal("type is not a class/union for field '.%s' at line %d", field_name, line);
        }

        if (!t->members) {
            sem_fatal("class/union has no members table for '.%s' at line %d", field_name, line);
        }

        Symbol *m = (Symbol*)hashtbl_lookup(t->members, field_name, 0);
        if (m) {
            if (m->kind != SYM_VAR && m->kind != SYM_CONST && m->kind != SYM_FUNC) {
                sem_fatal("member '%s' is not a field at line %d", field_name, line);
            }
            return m;
        }

        /* inheritance only for classes */
        if (t->kind == TYPE_CLASS) t = t->base_type;
        else break;
    }

    sem_fatal("unknown field '%s' at line %d", field_name, line);
    return NULL;
}

//breaks down qualified names like "Class::method"
static char *mk_qname(const char *cls, const char *meth) {
    if (!cls || !meth) return NULL;
    size_t n = strlen(cls) + 2 + strlen(meth) + 1; /* "::" */
    char *s = (char*)malloc(n);
    if (!s) return NULL;
    snprintf(s, n, "%s::%s", cls, meth);
    return s;
}

void sem_begin_qualified_method_def(Type *ret_candidate,
                                    Type *class_type,
                                    const char *class_name,
                                    const char *method_unqual,
                                    int line,
                                    Type **p_current_function_type,
                                    char **p_current_function_name,
                                    const char **p_current_function_unqual,
                                    int *p_current_function_name_owned,
                                    int *p_in_param_context)
{
    if (!class_type || class_type == type_error || class_type->kind != TYPE_CLASS) {
        sem_fatal("line %d: missing/invalid class qualifier for method '%s'",
                  line, method_unqual ? method_unqual : "<null>");
    }
    if (!class_name || !method_unqual) {
        sem_fatal("line %d: internal missing class/method name", line);
    }

    Type *ret = sem_check_function_return_type(ret_candidate, line);

    if (!class_type->members || !hashtbl_lookup(class_type->members, method_unqual, 0)) {
        sem_fatal("line %d: definition of undeclared method '%s::%s'", line, class_name, method_unqual);
    }

    /* Reset params collection (if you use a temp list) */
    sem_param_list_reset();

    char *qname = mk_qname(class_name, method_unqual);
    if (!qname) {
        sem_fatal("line %d: out of memory building qualified method name", line);
    }

    /* Fill parser-owned state via pointers */
    if (p_current_function_type)       *p_current_function_type = ret;
    if (p_current_function_unqual)     *p_current_function_unqual = method_unqual;
    if (p_current_function_name)       *p_current_function_name = qname;
    if (p_current_function_name_owned) *p_current_function_name_owned = 1;
    if (p_in_param_context)            *p_in_param_context = 1;

    /* Reuse existing prototype symbol instead of inserting again */
    Symbol *existing = symtab_lookup_in_scope(qname, 0);
    if (!existing) {
        sem_fatal("line %d: definition of undeclared method '%s'", line, qname);
    }
    if (existing->kind != SYM_FUNC) {
        sem_fatal("line %d: '%s' already declared as non-function", line, qname);
    }
    if (existing->u.func.is_forward_decl == 0) {
        sem_fatal("line %d: redefinition of method '%s'", line, qname);
    }
    existing->u.func.is_forward_decl = 0;

    /* Enter function scope + start frame accounting */
    symtab_enter_scope();
    sem_frame_begin(qname, line);

    //adds "this" as parameter  
    sem_declare_param("this", class_type, 1, line);
}

void sem_end_function_context(Type **p_current_function_type,
                              char **p_current_function_name,
                              const char **p_current_function_unqual,
                              int *p_current_function_name_owned,
                              int *p_in_param_context)
{
    /* English comments: Reset function parsing context safely */
    if (p_in_param_context) *p_in_param_context = 0;

    if (p_current_function_name_owned && *p_current_function_name_owned) {
        if (p_current_function_name && *p_current_function_name) {
            free(*p_current_function_name);
        }
    }

    if (p_current_function_name_owned) *p_current_function_name_owned = 0;
    if (p_current_function_type) *p_current_function_type = NULL;
    if (p_current_function_name) *p_current_function_name = NULL;
    if (p_current_function_unqual) *p_current_function_unqual = NULL;
}

int sem_try_rewrite_method_call(ASTNode *callee_expr,ASTNode *args,int line,Type **out_type,ASTNode **out_call){
    if (!callee_expr || callee_expr->kind != AST_FIELD) return 0;

    ASTNode *base = callee_expr->u.field.base;
    Symbol  *mem  = callee_expr->u.field.member;

    if (!mem || mem->kind != SYM_FUNC) return 0;

    /* Build callee as a normal function variable using qualified name (e.g., A::doo) */
    ASTNode *callee = ast_make_var(mem->name, mem->type, line);

    /* Prepend the object as hidden first argument (this) */
    ASTNode *args2 = ast_make_list(base, args, line);

    Type *t = sem_call_check(callee, args2, line);

    if (out_type) *out_type = t;
    if (out_call) *out_call = ast_make_call(callee, args2, t, line);

    return 1;
}

void sem_class_add_field(Type *cls, Symbol *field)
{
    if (!cls || cls == type_error || cls->kind != TYPE_CLASS) return;
    if (!field) return;
    if (!(field->kind == SYM_VAR && field->storage == STOR_FIELD)) return;

    if (cls->field_cap == 0) {
        cls->field_cap = 8;
        cls->field_order = (Symbol**)malloc(sizeof(Symbol*) * cls->field_cap);
        if (!cls->field_order) sem_fatal("out of memory in sem_class_add_field");
    } else if (cls->field_count >= cls->field_cap) {
        cls->field_cap *= 2;
        cls->field_order = (Symbol**)realloc(cls->field_order, sizeof(Symbol*) * cls->field_cap);
        if (!cls->field_order) sem_fatal("out of memory in sem_class_add_field");
    }

    cls->field_order[cls->field_count++] = field;
}



bool types_compatible_for_assignment(Type *lhs, Type *rhs) {
    if (!lhs || !rhs) return false;
    if (lhs == type_error || rhs == type_error) return false;

    if (lhs == rhs) return true;

    /* 3. Enums: μόνο αν είναι ο ίδιος enum τύπος */
    if (lhs->kind == TYPE_ENUM || rhs->kind == TYPE_ENUM) {
        return (lhs->kind == TYPE_ENUM && rhs->kind == TYPE_ENUM && lhs == rhs);
    }

        /* 2. Αριθμητικοί τύποι: int ↔ float επιτρέπεται */
    if (is_numeric(lhs->kind) && is_numeric(rhs->kind)) {
        return true;
    }

    /* 4. String: μόνο string = string */
    if (lhs->kind == TYPE_STRING || rhs->kind == TYPE_STRING) {
        return (lhs->kind == TYPE_STRING && rhs->kind == TYPE_STRING);
    }

    /* 5. Οτιδήποτε άλλο → όχι συμβατό */
    return false;
}


static ASTNode *strip_indexes(ASTNode *n){
    while (n && n->kind == AST_INDEX) {
        n = n->u.index.array;
    }
    return n;
}

/* γυρνάει το object root (π.χ. για x.a -> x, για x.a[i] -> x) */
static Symbol *lvalue_owner_symbol(ASTNode *n){
    n = strip_indexes(n);

    // αν είναι field, κατέβα στο base
    while (n && n->kind == AST_FIELD) {
        n = n->u.field.base;
        n = strip_indexes(n);
    }

    if (n && n->kind == AST_VAR) return n->u.var.sym;
    return NULL;
}

/* γυρνάει το symbol που ΠΡΑΓΜΑΤΙΚΑ γράφεις (π.χ. x.a -> symbol του a) */
static Symbol *lvalue_target_symbol(ASTNode *n){
    n = strip_indexes(n);

    if (n && n->kind == AST_FIELD) return n->u.field.member;
    if (n && n->kind == AST_VAR)   return n->u.var.sym;

    // array πάνω σε field: x.arr[i] => n είναι INDEX, strip -> FIELD => handled above
    return NULL;
}

void sem_check_writable_lvalue(ASTNode *n, int line){
    if (!n) {
        sem_fatal("invalid assigment (line %d)", line);
    }

    // lvalue επιτρέπουμε μόνο VAR ή INDEX
    if (n->kind != AST_VAR && n->kind != AST_INDEX && n->kind != AST_FIELD) {
        sem_fatal("not compatible lvalue (line %d)", line);
    }

    Symbol *target = lvalue_target_symbol(n);
    if (!target) sem_fatal("internal: lvalue without target symbol (line %d)", line);

    if (target->kind == SYM_CONST || target->kind == SYM_ENUM_CONST) {
        sem_fatal("cannot modify constant '%s' at line %d", target->name, line);
    }
    if (target->kind == SYM_FUNC) {
        sem_fatal("cannot assign to function '%s' at line %d", target->name, line);
    }

    //αν το object είναι const, δεν αλλαζει τπ field του
    Symbol *owner = lvalue_owner_symbol(n);
    if (owner && (owner->kind == SYM_CONST || owner->kind == SYM_ENUM_CONST)) {
        sem_fatal("cannot modify field of constant object '%s' at line %d", owner->name, line);
    }
}


Type *sem_check_assignment(Type *left, Type *right, int line){
    if (!left || left == type_error || !right || right == type_error) {
        return type_error;
    }//asn den exoun type

    //lists
    if (left->kind == TYPE_LIST || right->kind == TYPE_LIST) {
        if (left->kind != TYPE_LIST || right->kind != TYPE_LIST) {
            sem_fatal("cannot assign non-list to list or vice versa (line %d)", line);
        }
        if (!types_compatible_for_assignment(left->elem_type, right->elem_type)) {
            sem_fatal("incompatible list element types in assignment (line %d)", line);
        }
        return left;
    }

    //enums
    if (left->kind == TYPE_ENUM || right->kind == TYPE_ENUM) {
        // 1. Επιτρέπουμε ελεύθερα την ανάθεση μεταξύ Enum και Int (και αντίστροφα)
        if ((left->kind == TYPE_ENUM && right->kind == TYPE_INT) ||
            (left->kind == TYPE_INT && right->kind == TYPE_ENUM)) {
            return left;
        }

        // 2. Αν και τα δύο είναι Enums, πρέπει να είναι του ίδιου τύπου (ίδιο όνομα)
        if (left->kind == TYPE_ENUM && right->kind == TYPE_ENUM) {
            const char *ln = left->enum_name;
            const char *rn = right->enum_name;
            if (ln && rn && strcmp(ln, rn) != 0) {
                sem_fatal("assignment between different enum types '%s' and '%s' (line %d)", ln, rn, line);
            }
            return left;
        }

        // 3. Οτιδήποτε άλλο (π.χ. enum = float) παραμένει σφάλμα
        sem_fatal("assignment between enum and non-compatible type at line %d", line);
    }
    // arrays
    if (left->kind == TYPE_ARRAY || right->kind == TYPE_ARRAY) {
        if (left->kind != TYPE_ARRAY || right->kind != TYPE_ARRAY) {
            sem_fatal("cannot assign non-array to array or vice versa (line %d)", line);
        }
        
        // Αναδρομικός έλεγχος των στοιχείων (π.χ. int == int)
        sem_check_assignment(left->elem_type, right->elem_type, line);

        // Έλεγχος μεγέθους: Το 0 (open array []) είναι συμβατό με οποιοδήποτε μέγεθος
        // Το πεδίο array_size ορίζεται στο types.c (0 -> open array)
        if (left->array_size != 0 && right->array_size != 0 && left->array_size != right->array_size) {
            sem_fatal("incompatible array sizes in assignment (line %d)", line);
        }
        return left;
    }

    if (left->kind == TYPE_CLASS || right->kind == TYPE_CLASS) {
        if (left->kind != TYPE_CLASS || right->kind != TYPE_CLASS) {
            sem_fatal("assignment between class and non-class at line %d", line);
        }

        if (left != right) {
            /* optional: if you create duplicate Type objects, compare tag_name instead */
            const char *ln = left->tag_name;
            const char *rn = right->tag_name;
            if (!ln || !rn || strcmp(ln, rn) != 0) {
                sem_fatal("assignment between different class types at line %d", line);
            }
        }
        return left;
    }

    if (!is_basic(left->kind) || !is_basic(right->kind)) {
        sem_fatal("assignment between unsupported types at line %d", line);
    }

    //a) tautizontai
    if (left->kind == right->kind) {
        return left;
    }

    //b) arithmitikoi
    if (is_numeric(left->kind) && is_numeric(right->kind)) {
        return left;
    }

    /* 5. string: επιτρέπουμε μόνο string := string στην ανάθεση.
       Το θέμα με το μήκος <= 255 για string literal είναι θέμα
       ελέγχου της σταθεράς (π.χ. στη δημιουργία του node για T_SCONST),
       όχι της ανάθεσης αυτής καθαυτής. */
    sem_fatal("incompatible basic types in assignment at line %d", line);
    return type_error;
}


//+ - * / %
Type *sem_binary_arith(Type *left, Type *right, int line){
    if (!left || left == type_error || !right || right == type_error)
        return type_error;

    //Ένωση string + string (ADDOP '+'):
    if (left->kind == TYPE_STRING || right->kind == TYPE_STRING) {
        if (left->kind != TYPE_STRING || right->kind != TYPE_STRING) {
            sem_fatal("string concatenation requires both operands of type string (line %d)",line);
        }
        return type_string;
    }
    // Ένωση λιστών (ADDOP '+'):
    if (is_list(left->kind) || is_list(right->kind)) {
        if (!is_list(left->kind) || !is_list(right->kind)) {
            sem_fatal("list concatenation requires both operands of list type (line %d)",line);
        }
        /* TODO: όταν επεκτείνεις τη struct Type για LIST να έχει elem_type,
           έλεγξε ότι elem_type(left) συμβατό με elem_type(right). */
        return left; /* ή right, είναι ίδιος τύπος λίστας */
    }
    int left_is_ok = is_numeric(left->kind) || left->kind == TYPE_ENUM;
    int right_is_ok = is_numeric(right->kind) || right->kind == TYPE_ENUM;

    if (!left_is_ok || !right_is_ok) {
        sem_fatal("non-numeric operands in arithmetic expression at line %d", line);
    }
    
    //αποτέλεσμα int ή float,
    if (left->kind == TYPE_FLOAT || right->kind == TYPE_FLOAT)
        return type_float;
    return type_int;
}


//< > <= >=
Type *sem_binary_relational(Type *left, Type *right, int line){
    if (!left || left == type_error || !right || right == type_error)
        return type_error;

    if (left->kind == TYPE_ENUM && right->kind == TYPE_ENUM) {
        if (left != right) {
             if (left->enum_name && right->enum_name && 
                 strcmp(left->enum_name, right->enum_name) == 0) {
                 return type_int; 
             }
            sem_fatal("relational comparison between different enum types (line %d)", line);
        }
        return type_int;
    }

    if ((left->kind == TYPE_ENUM && right->kind == TYPE_INT) ||
        (left->kind == TYPE_INT && right->kind == TYPE_ENUM)) {
        return type_int;
    }

    if (is_numeric(left->kind) && is_numeric(right->kind)) {
        return type_int;
    }

    if (left->kind == TYPE_CHAR && right->kind == TYPE_CHAR) return type_int;
    if (left->kind == TYPE_STRING && right->kind == TYPE_STRING) return type_int;

    sem_fatal("incompatible types in relational expression at line %d", line);
    return type_error;
}

// ++ --
Type *sem_unary_incdec(Type *t, int line){
    if (!t || t == type_error)
        return type_error;

    if (t->kind != TYPE_INT) {
        sem_fatal("INC/DEC operand must be of type int (line %d)", line);
    }
    return type_int;
}

Type *sem_unary_sign(Type *t, int line){
    if (!t || t == type_error)
        return type_error;

    if (!is_numeric(t->kind)) {
        sem_fatal("unary +/- operand must be numeric (line %d)", line);
    }
    return t;
}

//! && ||
Type *sem_unary_not(Type *t, int line){
    if (!t || t == type_error)
        return type_error;

    if (t->kind != TYPE_INT) {
        sem_fatal("logical not operand must be of type int (line %d)", line);
    }
    return type_int;
}

Type *sem_binary_logical(Type *left, Type *right, int line){
    if (!left || left == type_error || !right || right == type_error)
        return type_error;
    if (left->kind != TYPE_INT || right->kind != TYPE_INT) {
        sem_fatal("logical operands must both be of type int (line %d)", line);
    }
    return type_int;
}

Type *sem_binary_equality(Type *left, Type *right, int line){
    if (!left || left == type_error || !right || right == type_error)
        return type_error;

    if (left->kind == TYPE_ENUM && right->kind == TYPE_ENUM) {
        if (left != right) { 
             if (left->enum_name && right->enum_name && 
                 strcmp(left->enum_name, right->enum_name) == 0) {
                 return type_int;
             }
             sem_fatal("comparison between different enum types (line %d)", line);
        }
        return type_int;
    }

    if ((left->kind == TYPE_ENUM && right->kind == TYPE_INT) ||
        (left->kind == TYPE_INT && right->kind == TYPE_ENUM)) {
        return type_int;
    }

    if (left->kind == TYPE_STRING || right->kind == TYPE_STRING) {
        if (left->kind != TYPE_STRING || right->kind != TYPE_STRING) {
            sem_fatal("comparison string and non-string (line %d)", line);
        }
        return type_int;
    }

    if (left->kind == TYPE_CHAR || right->kind == TYPE_CHAR) {
        if (left->kind != TYPE_CHAR || right->kind != TYPE_CHAR) {
            sem_fatal("comparison char and non-char (line %d)", line);
        }
        return type_int;
    }

    if (is_numeric(left->kind) && is_numeric(right->kind)) {
        return type_int;
    }

    sem_fatal("incompatible types in equality comparison (line %d)", line);
    return type_error;
}

static long sem_align4(long n) { 
    return (n + 3) & ~3L;
}

static void sem_layout_union(Type *t, int line);
static void sem_layout_class(Type *t, int line);

static void sem_layout_union(Type *t, int line) {
    if (!t || t == type_error) return;
    if (t->kind != TYPE_UNION) return;
    if (t->size > 0) return;

    if (!t->members) {
        sem_fatal("union has no members table (line %d)", line);
        return;
    }

    long maxSize = 0;

    for (hash_size i = 0; i < t->members->size; i++) {
        struct hashnode_s *n = t->members->nodes[i];
        while (n) {
            Symbol *m = (Symbol*)n->data;
            if (m && m->kind == SYM_VAR && m->storage == STOR_FIELD) {
                long s = sem_sizeof_rec(m->type, line);
                if (s < 0) s = 0;
                m->offset = 0;
                if (s > maxSize) maxSize = s;
            }
            n = n->next;
        }
    }

    t->size = (int)sem_align4(maxSize);
}

static void sem_layout_class(Type *t, int line) {
    if (!t || t == type_error) return;
    if (t->kind != TYPE_CLASS) return;
    if (t->size > 0) return;

    if (!t->members) {
        sem_fatal("internal: class has no members table ine %d)", line);
        return;
    }

    long off = 0;

    /* base first */
    if (t->base_type) {
        if (t->base_type->kind != TYPE_CLASS) {
            sem_fatal("base not a class (line %d)", line);
        }
        if (t->base_type->size <= 0) {
            sem_layout_class(t->base_type, line);
        }
        off = t->base_type->size;
    }

    //fields
    for (int k = 0; k < t->field_count; k++) {
        Symbol *m = t->field_order[k];
        if (!m) continue;

        long s = sem_sizeof_rec(m->type, line);
        if (s < 0) s = 0;

        off = sem_align4(off);
        m->offset = (int)off;
        off += s;
    }

    t->size = (int)sem_align4(off);
}


static long sem_sizeof_rec(Type *t, int line) {
    if (!t || t == type_error) return 0;

    switch (t->kind) {
        case TYPE_CHAR:   return 1;
        case TYPE_INT:    return 4;
        case TYPE_FLOAT:  return 4;
        case TYPE_ENUM:   return 4;

        case TYPE_STRING: return 256;

        case TYPE_LIST:   return 4; // pointer to first node

        case TYPE_ARRAY: {
            if (t->array_size <= 0) return 4; // unsized => treat as address
            long elem = sem_sizeof_rec(t->elem_type, line);
            if (elem <= 0) elem = 1;
            return (long)t->array_size * elem;
        }

        case TYPE_VOID:
            sem_fatal("sizeof(void) is not allowed (line %d)", line);
            return 0;

        case TYPE_CLASS:
            sem_layout_class(t, line);
            return t->size;
        case TYPE_UNION:
            sem_layout_union(t, line);
            return t->size;

        default:
            return 0;
    }
}

long sem_sizeof_bytes(Type *t, int line) {
    return sem_sizeof_rec(t, line);
}


Symbol *sem_define_const(Type *t, const char *name, ASTNode *init_expr, int line)
{
    if (!t || t == type_error) {
        sem_fatal("invalid type for const '%s' (line %d)", name, line);
    }

    if (!init_expr || !init_expr->type || init_expr->type == type_error) {
        sem_fatal("invalid initializer for const '%s' (line %d)", name, line);
    }

    /* έλεγχος συμβατότητας τύπων: const T x = expr; */
    sem_check_assignment(t, init_expr->type, line);

    Symbol *s = symtab_insert(name, SYM_CONST, t);
    if (!s) {
        sem_fatal("Redeclaration of const '%s' (line %d)", name, line);
    }

    /* Προαιρετικά: αν είναι literal, αποθήκευσε την τιμή στο symbol */
    if (init_expr->kind == AST_CONST) {
        switch (t->kind) {
        case TYPE_INT:
            s->u.c.ival = init_expr->u.constant.ival;
            break;
        case TYPE_FLOAT:
            s->u.c.fval = init_expr->u.constant.fval;
            break;
        case TYPE_CHAR:
            s->u.c.cval = init_expr->u.constant.cval;
            break;
        case TYPE_STRING:
            s->u.c.sval = init_expr->u.constant.sval;
            break;
        default:
            /* για άλλους τύπους μην κάνεις κάτι ειδικό τώρα */
            break;
        }
    }

    return s;
}


//LISTS

Type *sem_make_list_type(Type *elem_type, int line){
    if (!elem_type || elem_type == type_error) {
        sem_fatal("invalid element type for list (line %d)", line);
    }

    if (is_composite(elem_type->kind) || elem_type->kind == TYPE_STRING) {
        sem_fatal("list element type cannot be composite or string (line %d)", line);
    }

    return make_list_type(elem_type);
}

Type *sem_length(Type *exprr,int line){
    if (exprr && exprr != type_error && exprr->kind != TYPE_LIST && exprr->kind != TYPE_STRING) {
        sem_fatal("length() applies only to lists or strings (line %d)", line);
    }
    return type_int;
}

Type *sem_index(Type *arrayType, Type *indexType, int line) {
    if (!arrayType || arrayType == type_error) return type_error;
    if (arrayType->kind != TYPE_ARRAY) {
        sem_fatal("attempt to index non-array type at line %d", line);
    }
    if (!indexType || indexType == type_error) return type_error;
    
    if (indexType->kind != TYPE_INT && indexType->kind != TYPE_ENUM) {
        sem_fatal("array index must be of type int or enum at line %d", line);
    }
    return arrayType->elem_type;
}

Type *sem_find_list_element_type(Type *acc, Type *elem, int line){
    if (!acc || acc == type_error) return elem;
    if (!elem || elem == type_error) return acc;

    if (is_composite(acc->kind) || acc->kind == TYPE_STRING || is_composite(elem->kind) || elem->kind == TYPE_STRING) {
        sem_fatal("list elements cannot be composite or string (line %d)", line);
    }

    if (acc->kind != elem->kind) {
        sem_fatal("all list elements must have the same type (line %d)", line);
    }

    if (acc->kind == TYPE_ENUM && acc != elem) {
        sem_fatal("all enum list elements must be of the same enum type (line %d)", line);
    }

    return acc;
}

//FUNCTIONS

Type *sem_call_check(ASTNode *func_node, ASTNode *args, int line)
{
    if (!func_node || func_node->kind != AST_VAR) {
        sem_fatal("invalid function call at line %d", line);
    }

    Symbol *s = func_node->u.var.sym;
    if (!s) {
        sem_fatal("internal: call without symbol at line %d", line);
    }
    if (s->kind != SYM_FUNC) {
        sem_fatal("'%s' is not a function (line %d)", s->name, line);
    }

    int argc = count_args(args);
    int paramc = s->u.func.param_count;

    if (argc != paramc) {
        sem_fatal("function '%s' expects %d arguments but %d given (line %d)",s->name, paramc, argc, line);
    }

    int idx = 0;
    check_args_rec(args, s, &idx, line);

    if (!s->type) {
        sem_fatal("function '%s' has no return type (line %d)", s->name, line);
    }

    return s->type;
}

static int count_args(ASTNode *args)
{
    if (!args) return 0;
    if (args->kind == AST_LIST) {
        return count_args(args->u.list.head) + count_args(args->u.list.tail);
    }
    return 1;
}

static void check_args_rec(ASTNode *args, Symbol *func, int *index, int line)
{
    if (!args) return;

    if (args->kind == AST_LIST) {
        check_args_rec(args->u.list.head, func, index, line);
        check_args_rec(args->u.list.tail, func, index, line);
        return;
    }

    int i = *index;
    if (i >= func->u.func.param_count) {
        sem_fatal("too many arguments in call to '%s' (line %d)",func->name, line);
    }

    Symbol *p = func->u.func.params[i];
    Type   *expected = p->type;
    Type   *actual   = args->type;   // τα expression nodes σου έχουν type

    if (p->is_ref_param) {
        // ref param => πρέπει να είναι lvalue: VAR ή INDEX
        if (args->kind != AST_VAR && args->kind != AST_INDEX) {
            sem_fatal("argument %d of '%s' must be an lvalue (line %d)",i+1, func->name, line);
        }
        sem_check_assignment(expected, actual, line);
    } else {
        sem_check_assignment(expected, actual, line);
    }

    (*index)++;
}


Type *sem_check_function_return_type(Type *ret, int line) {
    if (!ret || ret == type_error) {
        sem_fatal("invalid function return type (line %d)", line);
    }

    if(ret->kind == TYPE_STRING)
        sem_fatal("function cannot return string (line %d)", line);
    else if(is_basic(ret->kind)||ret->kind == TYPE_VOID || ret->kind==TYPE_ENUM)
        return ret;
    else if(ret->kind == TYPE_LIST) // PREPEI NA EPISTREFETAI H DIEYUHNSH TOU PRVTOU STOIXEIOU
        return ret;
    else
        sem_fatal("function cannot return this type (line %d)", line);

    return type_error;
}


Type *sem_check_return(Type *func_type, Type *ret_type, int line) {
    if (!func_type) {
        sem_fatal("return statement outside of function (line %d)", line);
    }

    /* void function */
    if (func_type == type_void) {
        if (ret_type != type_void) {
            sem_fatal("void function cannot return a value (line %d)", line);
        }
        return type_void;
    }

    /* non-void function: πρέπει να επιστρέφει value */
    if (ret_type == type_void) {
        sem_fatal("non-void function must return a value (line %d)", line);
    }

    //check compatibility
    sem_check_assignment(func_type, ret_type, line);

    return func_type;
}

Symbol *sem_declare_function(const char *name, Type *ret_type, int line){
    Symbol *s = symtab_lookup_in_scope(name, 0);
    if (!s) {
        /* Πρώτο prototype*/
        s = symtab_insert_scoped(name, SYM_FUNC, ret_type, 0);
        if (!s) {
            fprintf(stderr, "Semantic error: cannot insert function '%s' (line %d)\n",
                    name, line);
            return NULL;
        }

        s->u.func.param_count = current_param_count;
        s->u.func.params = NULL;
        if (current_param_count > 0) {
            s->u.func.params = malloc(current_param_count * sizeof(Symbol *));
            for (int i = 0; i < current_param_count; ++i) {
                Symbol *psym = malloc(sizeof(Symbol));
                memset(psym, 0, sizeof(Symbol));
                psym->kind          = SYM_PARAM;
                psym->type          = current_params[i].type;
                psym->storage       = STOR_PARAM;
                psym->is_ref_param  = current_params[i].is_ref;
                /* name  NULL για prototype */
                s->u.func.params[i] = psym;
            }
        }
        s->u.func.is_forward_decl = 1; /* prototype */
        return s;
    }
    if (s->kind != SYM_FUNC) {
        fprintf(stderr, "Semantic error: '%s' already declared as non-function (line %d)\n",name, line);
        return s;
    }
    if (s->type != ret_type) {
        fprintf(stderr, "Semantic error: conflicting return type for function '%s' (line %d)\n",name, line);
        return s;
    }

    /* Έλεγχος συμβατότητας παραμέτρων */
    if (s->u.func.param_count != current_param_count) {
        fprintf(stderr, "Semantic error: conflicting number of parameters for '%s' (line %d)\n",name, line);
        return s;
    }

    for (int i = 0; i < current_param_count; ++i) {
        Type *old_t = s->u.func.params[i]->type;
        int   old_ref = s->u.func.params[i]->is_ref_param;
        Type *new_t = current_params[i].type;
        int   new_ref = current_params[i].is_ref;

        if (old_t != new_t || old_ref != new_ref) {
            fprintf(stderr, "Semantic error: conflicting type of parameter %d of '%s' (line %d)\n",
                    i + 1, name, line);
            return s;
        }
    }
    return s;
}


Symbol *sem_define_function(const char *name, Type *ret_type, int line)
{
    Symbol *s = sem_declare_function(name, ret_type, line);
    if (!s) return NULL;

    if (!s->u.func.is_forward_decl) {
        if (strstr(name, "::") != NULL) {
            return s; /* do NOT error */
        }
        fprintf(stderr, "Semantic error: redefinition of function '%s' (line %d)\n",name, line);
        return s;
    }

    s->u.func.is_forward_decl = 0;
    return s;
}


Symbol *sem_begin_function(const char *name, Type *ret, int line){
    Symbol *f = symtab_lookup(name);   // εδώ είμαστε ακόμα στο global scope

    if (!f) {
        f = symtab_insert(name, SYM_FUNC, ret);
        if (!f) {
            sem_fatal("cannot insert function '%s' (line %d)", name, line);
        }
        f->u.func.param_count   = 0;
        f->u.func.params        = NULL;
        f->u.func.is_forward_decl = 1;   // by default: prototype μέχρι να δούμε σώμα
    } else {
        if (f->kind != SYM_FUNC) {
            sem_fatal("'%s' is not a function (line %d)", name, line);
        }
        if (f->type != ret) {
            sem_fatal("conflicting return type for function '%s' (line %d)", name, line);
        }
        // εδώ μπορείς αργότερα να ελέγχεις αν η λίστα παραμέτρων ταιριάζει με προηγούμενο prototype
    }

    // reset param list για το τρέχον header (απλό approach: κρατάμε την τελευταία)
    f->u.func.param_count = 0;
    free(f->u.func.params);
    f->u.func.params = NULL;

    return f;
}

void sem_add_param_to_func(Symbol *func, Symbol *param)
{
    if (!func || func->kind != SYM_FUNC) return;

    int n = func->u.func.param_count;
    Symbol **new_params = realloc(func->u.func.params,(n + 1) * sizeof(Symbol*));
    if (!new_params) {
        sem_fatal("out of memory while adding parameter to function '%s'",func->name);
    }

    func->u.func.params = new_params;
    func->u.func.params[n] = param;
    func->u.func.param_count = n + 1;
}

Symbol *sem_declare_param(const char *name, Type *type, int is_ref, int line)
{
    Symbol *s = symtab_insert(name, SYM_PARAM, type);
    if (!s) {
        fprintf(stderr, "Semantic error: redeclaration of parameter '%s' (line %d)\n",
                name, line);
        return NULL;
    }

    s->storage      = STOR_PARAM;
    s->is_ref_param = is_ref;

    sem_param_list_add(type, is_ref);

    //for memory
    sem_bind_param_symbol(s, line);

    return s;
}

void sem_param_list_reset(void)
{
    current_param_count = 0;
}

/* Προσθέτει έναν (type, is_ref) στη λίστα του τρέχοντος function header */
void sem_param_list_add(Type *t, int is_ref)
{
    if (!t || t == type_error)
        return;

    if (current_param_count >= MAX_PARAMS) {
        fprintf(stderr, "Semantic error: too many parameters (max=%d)\n", MAX_PARAMS);
        return;
    }

    current_params[current_param_count].type  = t;
    current_params[current_param_count].is_ref = is_ref;
    current_param_count++;
}

void sem_check_undefined_prototypes(void)
{
    int err = 0;
    if (!g_symtab) return;

    for (hash_size i = 0; i < g_symtab->size; ++i) {
        struct hashnode_s *n = g_symtab->nodes[i];
        while (n) {
            Symbol *s = (Symbol *)n->data;

            // μόνο global scope funcs (π.χ. scope==0)
            if (s && s->kind == SYM_FUNC && n->scope == 0 &&
                s->u.func.is_forward_decl &&
                s->name && strcmp(s->name, "main") != 0)
            {
                fprintf(stderr,"Semantic error: function '%s' declared but not defined/used\n",s->name);
                err++;
            }
            n = n->next;
        }
    }

    if (err) exit(EXIT_FAILURE);
}


//ENUMS
void sem_enum_start(const char *name, int line) {
    Type *t = malloc(sizeof(Type)); 
    t->kind = TYPE_ENUM;
    t->enum_name = strdup(name);
    
    Symbol *s = symtab_insert(name, SYM_TYPE, t);
    if (!s) {
        sem_fatal("Redeclaration of enum type '%s' (line %d)", name, line);
    }

    current_enum_processing_type = t;
    current_enum_counter = 0;
}

void sem_enum_add_const(const char *name, int has_explicit_val, int explicit_val, int line) {
    if (!current_enum_processing_type) {
        sem_fatal("Internal: Attempt to add enum constant '%s' outside of enum decl (line %d)", name, line);
    }

    int value;
    if (has_explicit_val) {
        value = explicit_val;
    } else {
        value = current_enum_counter;
    }

    Symbol *s = symtab_insert(name, SYM_ENUM_CONST, current_enum_processing_type);
    if (!s) {
        sem_fatal("Redeclaration of enum constant '%s' (line %d)", name, line);
    }
    
    s->u.enum_const.value = value;

    current_enum_counter = value + 1;
}

/* semantics.c */

Type *sem_use_enum_constant(Type *enum_type, const char *const_name, int line) {
    if (!enum_type || enum_type->kind != TYPE_ENUM) {
        sem_fatal("Type '%s' is not an enum (line %d)", 
                  (enum_type && enum_type->enum_name) ? enum_type->enum_name : "unknown", 
                  line);
    }

    Symbol *s = symtab_lookup(const_name);
    
    if (!s || s->kind != SYM_ENUM_CONST) {
        sem_fatal("Enum constant '%s' not found (line %d)", const_name, line);
    }

    if (s->type != enum_type) {
        if (s->type->enum_name && enum_type->enum_name && 
            strcmp(s->type->enum_name, enum_type->enum_name) != 0) {
            
            sem_fatal("Constant '%s' belongs to enum '%s', not '%s' (line %d)", 
                      const_name, s->type->enum_name, enum_type->enum_name, line);
        }
    }

    return s->type; 
}

void sem_enum_end(void) {
    current_enum_processing_type = NULL;
    current_enum_counter = 0;
}

//STATEMENTS

Type *sem_check_condition(Type *cond, int line) {
    if (!cond || cond == type_error)
        return type_error;
    if (cond->kind != TYPE_INT) {
        sem_fatal("condition in if/while/for must be of type int (line %d)", line);
    }
    return type_int;
}

//COUT 
void sem_check_printable(Type *t, int line) {
    if (!t || t == type_error) return;

    if (is_basic(t->kind)) {
        return;
    }

    if (t->kind == TYPE_ENUM) {
        return;
    }

    sem_fatal("Type is not printable, only basic types (line %d)", line);
}

void sem_enter_loop(void) {
    loop_nesting_level++;
}

void sem_leave_loop(void) {
    if (loop_nesting_level > 0) {
        loop_nesting_level--;
    } else {
        sem_fatal("Internal compiler error: loop");
    }
}

void sem_check_break_continue(const char *op_name, int line) {
    if (loop_nesting_level <= 0) {
        sem_fatal("Statement '%s' not allowed outside of loop (line %d)", op_name, line);
    }
}

// Frame / offsets (MIPS32)

static Symbol *sem_lookup_global_func(const char *name) {
    return symtab_lookup_in_scope(name, 0);
}

void sem_frame_begin(const char *func_name, int line) {
    (void)func_name; (void)line;
    sem_in_function = 1;

    sem_param_next_off = SEM_PARAM_BASE_FP;
    sem_local_bytes = 0;
    sem_max_local = 0;

    sem_scope_sp = 0;
    sem_scope_saved[sem_scope_sp++] = 0; // baseline for function scope
}

void sem_frame_end(const char *func_name, int line) {
    (void)line;
    Symbol *f = sem_lookup_global_func(func_name);

    if (f && f->kind == SYM_FUNC) {
        // store locals frame size in bytes (aligned) in f->offset
        f->offset = (int)sem_align4(sem_max_local);
    }

    sem_in_function = 0;
    sem_param_next_off = 0;
    sem_local_bytes = 0;
    sem_max_local = 0;
    sem_scope_sp = 0;
}

void sem_scope_push_offsets(void) {
    if (!sem_in_function) return;
    if (sem_scope_sp >= SEM_MAX_SCOPE_DEPTH) sem_fatal("internal: too deep scopes");
    sem_scope_saved[sem_scope_sp++] = sem_local_bytes;
}

void sem_scope_pop_offsets(void) {
    if (!sem_in_function) return;
    if (sem_scope_sp <= 0) sem_fatal("internal: scope pop underflow");
    sem_local_bytes = sem_scope_saved[--sem_scope_sp];
}

void sem_bind_param_symbol(Symbol *s, int line) {
    if (!sem_in_function || !s || s->kind != SYM_PARAM) return;

    long sz = s->is_ref_param ? 4 : sem_sizeof_bytes(s->type, line);
    sz = sem_align4(sz);

    s->storage = STOR_PARAM;
    s->offset  = (int)sem_param_next_off;

    sem_param_next_off += sz;
}

void sem_bind_var_symbol(Symbol *s, int line) {
    if (!sem_in_function || !s || s->kind != SYM_VAR) return;

    long sz = sem_sizeof_bytes(s->type, line);
    sz = sem_align4(sz);

    sem_local_bytes += sz;
    if (sem_local_bytes > sem_max_local) sem_max_local = sem_local_bytes;

    s->storage = STOR_LOCAL;
    s->offset  = (int)(-sem_local_bytes);
}   
