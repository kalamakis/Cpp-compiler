#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "types.h"

#include "semantics.h"

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

    if (s->kind != SYM_VAR && s->kind != SYM_CONST && s->kind != SYM_PARAM) {
        sem_fatal("'%s' is not a variable at line %d", name, line);
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

Type *sem_check_assignment(Type *left, Type *right, int line){
    if (!left || left == type_error || !right || right == type_error) {
        return type_error;
    }//asn den exoun type

    //lists
    if (left->kind == TYPE_LIST || right->kind == TYPE_LIST) {
        if (left->kind != TYPE_LIST || right->kind != TYPE_LIST) {
            sem_fatal("assignment between list and non-list at line %d", line);
        }
        /* TODO: όταν υλοποιήσεις πλήρως Type για λίστες, έλεγξε εδώ
           ότι τα element types είναι συμβατά, σύμφωνα με τους ίδιους
           κανόνες ανάθεσης (βασικοί/enum κλπ). Προς το παρόν,
           απλά θεωρούμε ότι είναι ΟΚ αν είναι και οι δύο TYPE_LIST. */

        return left;
    }

    //enums
    if (left->kind == TYPE_ENUM || right->kind == TYPE_ENUM) {
        /* Πρέπει και οι δύο να είναι enums */
        if (left->kind != TYPE_ENUM || right->kind != TYPE_ENUM) {
            sem_fatal("assignment between enum and non-enum at line %d", line);
        }
        //Δύο enums είναι συμβατά ΜΟΝΟ αν ταυτίζονται.
        if (left != right) {
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
Type *sem_binary_arith(Type *lhs, Type *rhs, int line){
    if (!lhs || lhs == type_error || !rhs || rhs == type_error)
        return type_error;

    //Ένωση string + string (ADDOP '+'):
    if (lhs->kind == TYPE_STRING || rhs->kind == TYPE_STRING) {
        if (lhs->kind != TYPE_STRING || rhs->kind != TYPE_STRING) {
            sem_fatal("string concatenation requires both operands of type string (line %d)",line);
        }
        return type_string;
    }
    // Ένωση λιστών (ADDOP '+'):
    if (is_list(lhs->kind) || is_list(rhs->kind)) {
        if (!is_list(lhs->kind) || !is_list(rhs->kind)) {
            sem_fatal("list concatenation requires both operands of list type (line %d)",line);
        }
        /* TODO: όταν επεκτείνεις τη struct Type για LIST να έχει elem_type,
           έλεγξε ότι elem_type(lhs) συμβατό με elem_type(rhs). */
        return lhs; /* ή rhs, είναι ίδιος τύπος λίστας */
    }
    if (!is_numeric(lhs->kind) || !is_numeric(rhs->kind)) {
        sem_fatal("non-numeric operands in arithmetic expression at line %d", line);
    }
    //αποτέλεσμα int ή float,
    if (lhs->kind == TYPE_FLOAT || rhs->kind == TYPE_FLOAT)
        return type_float;
    return type_int;
}


//< > <= >=
Type *sem_binary_relational(Type *lhs, Type *rhs, int line){
    if (!lhs || lhs == type_error || !rhs || rhs == type_error)
        return type_error;
    /* Επιτρέπεται:
       - numeric vs numeric,
       - char vs char,
       - string vs string,
       - enum vs ίδιο enum.
    */
    if (is_numeric(lhs->kind) && is_numeric(rhs->kind)) {
        return type_int;
    }
    if (lhs->kind == TYPE_CHAR && rhs->kind == TYPE_CHAR) {
        return type_int;
    }
    if (lhs->kind == TYPE_STRING && rhs->kind == TYPE_STRING) {
        return type_int;
    }
    if (lhs->kind == TYPE_ENUM && rhs->kind == TYPE_ENUM) {
        if (lhs != rhs) {
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

//! && ||
Type *sem_unary_not(Type *t, int line){
    if (!t || t == type_error)
        return type_error;

    if (t->kind != TYPE_INT) {
        sem_fatal("logical not operand must be of type int (line %d)", line);
    }
    return type_int;
}

Type *sem_binary_logical(Type *lhs, Type *rhs, int line){
    if (!lhs || lhs == type_error || !rhs || rhs == type_error)
        return type_error;
    if (lhs->kind != TYPE_INT || rhs->kind != TYPE_INT) {
        sem_fatal("logical operands must both be of type int (line %d)", line);
    }
    return type_int;
}

Type *sem_binary_equality(Type *lhs, Type *rhs, int line){
    if (!lhs || lhs == type_error || !rhs || rhs == type_error)
        return type_error;

    /* enums: πρέπει να είναι ίδιο enum type */
    if (lhs->kind == TYPE_ENUM || rhs->kind == TYPE_ENUM) {
        if (lhs->kind != TYPE_ENUM || rhs->kind != TYPE_ENUM || lhs != rhs) {
            sem_fatal("incompatible enum types (line %d)", line);
        }
        return type_int;
    }
    /* strings: string == string */
    if (lhs->kind == TYPE_STRING || rhs->kind == TYPE_STRING) {
        if (lhs->kind != TYPE_STRING || rhs->kind != TYPE_STRING) {
            sem_fatal("comparison string and non-string (line %d)", line);
        }
        return type_int;
    }
    /* char: char == char */
    if (lhs->kind == TYPE_CHAR || rhs->kind == TYPE_CHAR) {
        if (lhs->kind != TYPE_CHAR || rhs->kind != TYPE_CHAR) {
            sem_fatal("comparison char and non-char (line %d)", line);
        }
        return type_int;
    }
    /* numeric: int/float μεταξύ τους, ακόμα κι αν διαφορετικός */
    if (is_numeric(lhs->kind) && is_numeric(rhs->kind)) {
        return type_int;
    }
    sem_fatal("incompatible types at line %d", line);
    return type_error;
}

Type *sem_make_list_type(Type *elem_type, int line){
    if (!elem_type || elem_type == type_error) {
        sem_fatal("invalid element type for list (line %d)", line);
    }

    if (is_composite(elem_type->kind) || elem_type->kind == TYPE_STRING) {
        sem_fatal("list element type cannot be composite or string (line %d)", line);
    }

    return make_list_type(elem_type);
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
