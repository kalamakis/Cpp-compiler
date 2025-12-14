#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "types.h"
#include <stdbool.h>
#include "ast.h"
#include "symbol.h"

#include "semantics.h"

#define MAX_PARAMS 64

static ParamInfo current_params[MAX_PARAMS];
static int       current_param_count = 0;
static Symbol *current_function_symbol = NULL;
static int collecting_signature = 0;  // 1 = χτίζουμε, 0 = ελέγχουμε
static int current_param_index = 0;

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

    if (s->kind != SYM_VAR && s->kind != SYM_CONST && s->kind != SYM_PARAM && s->kind != SYM_ENUM_CONST && s->kind != SYM_FUNC) {
        sem_fatal("'%s' is not a variable/function at line %d", name, line);
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
        if (left->kind != TYPE_ENUM || right->kind != TYPE_ENUM) {
            sem_fatal("assignment between enum and non-enum at line %d", line);
        }
        const char *ln = left->enum_name;
        const char *rn = right->enum_name;
        if (!ln || !rn || strcmp(ln, rn) != 0) {
            sem_fatal("assignment between different enum types at line %d", line);
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
    if (!is_numeric(left->kind) || !is_numeric(right->kind)) {
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
    /* Επιτρέπεται:
       - numeric vs numeric,
       - char vs char,
       - string vs string,
       - enum vs ίδιο enum.
    */
    if (is_numeric(left->kind) && is_numeric(right->kind)) {
        return type_int;
    }
    if (left->kind == TYPE_CHAR && right->kind == TYPE_CHAR) {
        return type_int;
    }
    if (left->kind == TYPE_STRING && right->kind == TYPE_STRING) {
        return type_int;
    }
    if (left->kind == TYPE_ENUM && right->kind == TYPE_ENUM) {
        if (left != right) {
            sem_fatal("relational comparison between different enum types (line %d)", line);
        }
        return type_int;
    }
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

    /* enums: πρέπει να είναι ίδιο enum type */
    if (left->kind == TYPE_ENUM || right->kind == TYPE_ENUM) {
        if (left->kind != TYPE_ENUM || right->kind != TYPE_ENUM) {
            sem_fatal("comparison between enum and non-enum (line %d)", line);
        }
        const char *ln = left->enum_name;
        const char *rn = right->enum_name;
        if (!ln || !rn || strcmp(ln, rn) != 0) {
            sem_fatal("incompatible enum types (line %d)", line);
        }
        return type_int;
    }
    /* strings: string == string */
    if (left->kind == TYPE_STRING || right->kind == TYPE_STRING) {
        if (left->kind != TYPE_STRING || right->kind != TYPE_STRING) {
            sem_fatal("comparison string and non-string (line %d)", line);
        }
        return type_int;
    }
    /* char: char == char */
    if (left->kind == TYPE_CHAR || right->kind == TYPE_CHAR) {
        if (left->kind != TYPE_CHAR || right->kind != TYPE_CHAR) {
            sem_fatal("comparison char and non-char (line %d)", line);
        }
        return type_int;
    }
    /* numeric: int/float μεταξύ τους, ακόμα κι αν διαφορετικός */
    if (is_numeric(left->kind) && is_numeric(right->kind)) {
        return type_int;
    }
    sem_fatal("incompatible types at line %d", line);
    return type_error;
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
    if (indexType->kind != TYPE_INT) {
        sem_fatal("array index must be of type int at line %d", line);
    }
    /* επιστρέφουμε το στοιχειακό τύπο (μπορεί να είναι άλλο array για multi-dim) */
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
        sem_fatal("function cannot return this type (line %d)", line); /* κλάσεις, ενώσεις, πίνακες, κτλ. */

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
    Symbol *s = symtab_lookup(name);
    if (!s) {
        /* Πρώτο prototype*/
        s = symtab_insert(name, SYM_FUNC, ret_type);
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





//ENUMS
void sem_define_enum_constant(Type *enum_type, const char *name, int value, int line) {
    if (!enum_type || enum_type->kind != TYPE_ENUM) {
        sem_fatal("internal: sem_define_enum_constant called with non-enum (line %d)", line);
    }

    Symbol *s = symtab_insert(name, SYM_ENUM_CONST, enum_type);
    if (!s) {
        sem_fatal("Redeclaration of enum const '%s' (line %d)", name, line);
    }
    s->u.enum_const.value = value;
}


Type *sem_use_enum_constant(Type *enum_type, const char *const_name, int line) {
    if (!enum_type || enum_type->kind != TYPE_ENUM) {
        sem_fatal("internal: sem_use_enum_constant called with non-enum (line %d)", line);
    }

    Symbol *s = symtab_lookup(const_name); // Αναζητούμε απευθείας με το όνομα της σταθεράς
    if (!s || s->kind != SYM_ENUM_CONST || s->type != enum_type) {
        sem_fatal("unknown enum constant '%s' (line %d)", const_name, line);
        return type_error;
    }

    return s->type;
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
