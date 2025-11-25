#include "types.h"
#include <stdlib.h>

Type *type_int = NULL;
Type *type_float = NULL;
Type *type_char = NULL;
Type *type_string = NULL;
Type *type_void = NULL;
Type *type_error = NULL;

Type *make_simple_type(TypeKind kind){
    Type *t = malloc(sizeof(Type));
    t->kind = kind;
    return t;
}

<<<<<<< HEAD
Type *make_list_type(Type *elem_type){
    Type *t = make_simple_type(TYPE_LIST);
    if (!t) return NULL;

    t->elem_type = elem_type;
    return t;
}

void init_types(void){
    if (!type_int)    type_int    = make_simple_type(TYPE_INT);
    if (!type_float)  type_float  = make_simple_type(TYPE_FLOAT);
    if (!type_char)   type_char   = make_simple_type(TYPE_CHAR);
    if (!type_string) type_string = make_simple_type(TYPE_STRING);
    if (!type_void)   type_void   = make_simple_type(TYPE_VOID);
    if (!type_error)  type_error  = make_simple_type(TYPE_ERROR);
}
=======
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
>>>>>>> c84b9f2cc1dbbebb561d6beacda23619a30966d8
