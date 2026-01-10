#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "types.h"
#include "symbolTable.h"
#include <stdbool.h>
#include "ast.h"
#include "symbol.h"

typedef struct {
    Type *type;   /* τύπος παραμέτρου */
    int   is_ref; /* 0 = by value, 1 = by reference (&) */
} ParamInfo;

void sem_fatal(const char *fmt, ...);

Type *sem_use_variable(const char *name, int line);

int is_basic(TypeKind k);
int is_numeric(TypeKind k);
int is_enum(TypeKind k);
int is_list(TypeKind k);

//array/list/class/union
static int is_composite(TypeKind k);
bool types_compatible_for_assignment(Type *lhs, Type *rhs);

void sem_check_writable_lvalue(ASTNode *n, int line);

Type *sem_check_assignment(Type *left, Type *right, int line);

//expression
Type *sem_binary_arith(Type *lhs, Type *rhs, int line);
Type *sem_binary_relational(Type *lhs, Type *rhs, int line);
Type *sem_binary_equality(Type *lhs, Type *rhs, int line);
Type *sem_binary_logical(Type *lhs, Type *rhs, int line);
Type *sem_unary_arith(Type *t, int line);
Type *sem_unary_not(Type *t, int line);
Type *sem_unary_incdec(Type *t, int line);
Type *sem_unary_sign(Type *t, int line);
long sem_sizeof_bytes(Type *t, int line);

Symbol *sem_define_const(Type *t, const char *name, ASTNode *init_expr, int line);

//list
Type *sem_make_list_type(Type *elem_type, int line);
Type *sem_find_list_element_type(Type *acc, Type *elem, int line);

Type *sem_index(Type *arrayType, Type *indexType, int lineno);

Type *sem_length(Type *exprr,int line);

//FUNCTIONS

Symbol *sem_begin_function(const char *name, Type *ret, int line);
void sem_add_param(Symbol *func, Symbol *param);
Type *sem_call_check(ASTNode *func_node, ASTNode *args, int line);
Type *sem_check_function_return_type(Type *ret, int line);
Type *sem_check_return(Type *func_type, Type *ret_type, int line);

Symbol *sem_declare_function(const char *name, Type *ret_type, int line);
Symbol *sem_define_function (const char *name, Type *ret_type, int line);
Symbol *sem_declare_param   (const char *name, Type *type, int is_ref, int line);

static int count_args(ASTNode *args);
static void check_args_rec(ASTNode *args, Symbol *func, int *index, int line);

void   sem_param_list_reset(void);
void   sem_param_list_add(Type *t, int is_ref);

void sem_check_undefined_prototypes(void);

//Enums
void sem_enum_start(const char *name, int line);
void sem_enum_add_const(const char *name, int has_explicit_val, int explicit_val, int line);
Type *sem_use_enum_constant(Type *enum_type, const char *const_name, int line);
void sem_enum_end(void);

//STATEMENTS
Type *sem_check_condition(Type *cond, int line);

//COUT
void sem_check_printable(Type *t, int line);

//Loop specific commands
void sem_enter_loop(void);
void sem_leave_loop(void);
void sem_check_break_continue(const char *op_name, int line);

#endif