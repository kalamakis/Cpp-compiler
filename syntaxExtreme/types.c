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
    t->elem_type = NULL;
    return t;
}

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
