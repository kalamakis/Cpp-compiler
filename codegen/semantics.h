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

Symbol *sem_lookup_field_symbol(Type *base, const char *field_name, int line);

//int sem_begin_qualified_method_def(Type *ret_candidate, Type *class_type, const char *class_name, const char *method_unqual_name, int line);

void sem_end_function_def(void);

static char *mk_qname(const char *cls, const char *meth);

/*begin out-of-class method definition (C::f ...).
 * enters the function scope and starts frame tracking.
 */
void sem_begin_qualified_method_def(Type *ret_candidate,
                                    Type *class_type,
                                    const char *class_name,
                                    const char *method_unqual,
                                    int line,
                                    Type **p_current_function_type,
                                    char **p_current_function_name,
                                    const char **p_current_function_unqual,
                                    int *p_current_function_name_owned,
                                    int *p_in_param_context);

/* Common cleanup for function parsing context (frees qualified name if owned). */
void sem_end_function_context(Type **p_current_function_type,
                              char **p_current_function_name,
                              const char **p_current_function_unqual,
                              int *p_current_function_name_owned,
                              int *p_in_param_context);

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

// Frame / offsets (MIPS32)
static long sem_sizeof_rec(Type *t, int line);

void sem_frame_begin(const char *func_name, int line);
void sem_frame_end(const char *func_name, int line);

void sem_scope_push_offsets(void);
void sem_scope_pop_offsets(void);

void sem_bind_param_symbol(Symbol *s, int line);
void sem_bind_var_symbol(Symbol *s, int line);


#endif