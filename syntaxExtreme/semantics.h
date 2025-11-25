#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "types.h"
#include "symbolTable.h"

void sem_fatal(const char *fmt, ...);

Type *sem_use_variable(const char *name, int line);

int is_basic(TypeKind k);
int is_numeric(TypeKind k);
int is_enum(TypeKind k);
int is_list(TypeKind k);
//array/list/class/union
static int is_composite(TypeKind k);

Type *sem_check_assignment(Type *left, Type *right, int line);

//expression
Type *sem_binary_arith(Type *lhs, Type *rhs, int line);
Type *sem_binary_relational(Type *lhs, Type *rhs, int line);
Type *sem_binary_equality(Type *lhs, Type *rhs, int line);
Type *sem_binary_logical(Type *lhs, Type *rhs, int line);
Type *sem_unary_arith(Type *t, int line);
Type *sem_unary_not(Type *t, int line);
Type *sem_unary_incdec(Type *t, int line);
<<<<<<< HEAD

//list
Type *sem_make_list_type(Type *elem_type, int line);
=======
Type *sem_index(Type *arrayType, Type *indexType, int lineno);
>>>>>>> c84b9f2cc1dbbebb561d6beacda23619a30966d8
#endif