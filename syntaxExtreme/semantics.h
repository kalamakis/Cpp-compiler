#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "types.h"
#include "symbolTable.h"
#include <stdbool.h>

void sem_fatal(const char *fmt, ...);

Type *sem_use_variable(const char *name, int line);

int is_basic(TypeKind k);
int is_numeric(TypeKind k);
int is_enum(TypeKind k);
int is_list(TypeKind k);

//array/list/class/union
static int is_composite(TypeKind k);
bool types_compatible_for_assignment(Type *lhs, Type *rhs);

Type *sem_check_assignment(Type *left, Type *right, int line);

//expression
Type *sem_binary_arith(Type *lhs, Type *rhs, int line);
Type *sem_binary_relational(Type *lhs, Type *rhs, int line);
Type *sem_binary_equality(Type *lhs, Type *rhs, int line);
Type *sem_binary_logical(Type *lhs, Type *rhs, int line);
Type *sem_unary_arith(Type *t, int line);
Type *sem_unary_not(Type *t, int line);
Type *sem_unary_incdec(Type *t, int line);

//list
Type *sem_make_list_type(Type *elem_type, int line);
Type *sem_find_list_element_type(Type *acc, Type *elem, int line);

Type *sem_index(Type *arrayType, Type *indexType, int lineno);

//FUNCTIONS

Type *sem_check_function_return_type(Type *ret, int line);
Type *sem_check_return(Type *func_type, Type *ret_type, int line);
//Enums
void sem_define_enum_constant(Type *enum_type, const char *name, int value, int line);


#endif