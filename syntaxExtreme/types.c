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
