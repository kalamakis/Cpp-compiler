#include "types.h"
#include <stdlib.h>

Type *type_int = NULL;
Type *type_float = NULL;
Type *type_char = NULL;
Type *type_string = NULL;
Type *type_void = NULL;
Type *type_error = NULL;

Type *make_type(TypeKind kind)
{
    Type *t = malloc(sizeof(Type));
    t->kind = kind;
    return t;
}

Type *make_array_type(Type *elem_type, int size)
{
    Type *t = (Type*)malloc(sizeof(Type));
    t->kind = TYPE_ARRAY;
    t->elem_type = elem_type;
    t->array_size = size;   // 0 -> open array []
    return t;
}

/* Στο dims: left = προηγούμενα dims, right = νέο dim node.
   Θέλουμε nested arrays: αναρτούμε το right στο τέλος του left. */
Type *attach_nested_array(Type *left, Type *right) {
    if (!left) return right;
    Type *t = left;
    while (t->elem_type) t = t->elem_type;
    t->elem_type = right;
    return left;
}

/* Στο variabledef: θέλουμε να "γεμίσουμε" τα elem_type των dims με το base type.
   dims μπορεί να είναι NULL. Επιστρέφει τον ολοκληρωμένο τύπο. */
Type *attach_array_to_base(Type *base, Type *dims) {
    if (!dims) return base;
    Type *t = dims;
    while (t->elem_type) t = t->elem_type;
    t->elem_type = base;
    return dims;
}