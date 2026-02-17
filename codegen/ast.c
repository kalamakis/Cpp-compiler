/* ast.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "types.h"
#include "symbolTable.h"   /* symtab_lookup */


ASTNode *ast_root = NULL;
/* Small helper for all constructors */
static ASTNode *ast_new(ASTKind kind, Type *t, int line)
{
    ASTNode *n = malloc(sizeof *n);
    if (!n) {
        fprintf(stderr, "Out of memory while creating AST node\n");
        exit(EXIT_FAILURE);
    }

    n->kind = kind;
    n->type = t;
    n->line = line;

    memset(&n->u, 0, sizeof n->u);
    return n;
}

ASTNode *ast_make_list(ASTNode *head, ASTNode *tail, int line)
{
    ASTNode *n = ast_new(AST_LIST, NULL, line);
    n->u.list.head = head;
    n->u.list.tail = tail;
    return n;
}

ASTNode *ast_list_append(ASTNode *list, ASTNode *elem, int line)
{
    if (!list) return elem;
    if (list->kind != AST_LIST) {
        // γύρνα το μόνο στοιχείο σε λίστα [list, elem]
        return ast_make_list(list, ast_make_list(elem, NULL, line), line);
    }

    ASTNode *cur = list;
    while (cur->u.list.tail && cur->u.list.tail->kind == AST_LIST) {
        cur = cur->u.list.tail;
    }
    cur->u.list.tail = ast_make_list(elem, NULL, line);
    return list;
}


ASTNode *ast_make_program(ASTNode *globals, ASTNode *main_func, int line)
{
    ASTNode *n = ast_new(AST_PROGRAM, NULL, line);
    n->u.program.globals   = globals;
    n->u.program.main_func = main_func;
    return n;
}


/* ====================  EXPRESSIONS  ==================== */

ASTNode *ast_make_binop(ASTOp op, ASTNode *l, ASTNode *r, Type *t, int line)
{
    ASTNode *n = ast_new(AST_BINOP, t, line);
    n->u.binop.op    = op;
    n->u.binop.left  = l;
    n->u.binop.right = r;
    return n;
}

ASTNode *ast_make_unop(ASTOp op, ASTNode *e, Type *t, int line)
{
    ASTNode *n = ast_new(AST_UNOP, t, line);
    n->u.unop.op   = op;
    n->u.unop.expr = e;
    return n;
}

/* ---- constants ---- */

ASTNode *ast_make_const_int(long v, int line)
{
    ASTNode *n = ast_new(AST_CONST, type_int, line);
    n->u.constant.ival = v;
    return n;
}

ASTNode *ast_make_const_char(char c, int line)
{
    ASTNode *n = ast_new(AST_CONST, type_char, line);
    n->u.constant.cval = c;
    return n;
}

ASTNode *ast_make_const_float(double f, int line)
{
    ASTNode *n = ast_new(AST_CONST, type_float, line);
    n->u.constant.fval = f;
    return n;
}

ASTNode *ast_make_const_string(const char *s, int line)
{
    /* assume type_string is something like "char *" or a dedicated string type */
    ASTNode *n = ast_new(AST_CONST, type_string, line);

    if (s) {
        char *copy = strdup(s);
        if (!copy) {
            fprintf(stderr, "Out of memory duplicating string literal\n");
            exit(EXIT_FAILURE);
        }
        n->u.constant.sval = copy;
    } else {
        n->u.constant.sval = NULL;
    }

    return n;
}

/* ---- variable reference ---- */

ASTNode *ast_make_var(char *name, Type *t, int line)
{
    ASTNode *n = ast_new(AST_VAR, t, line);

    n->u.var.name  = name;
    n->u.var.index = NULL;
    n->u.var.field = NULL;

    Symbol *s = symtab_lookup(name);
    if (!s) {
        fprintf(stderr,
                "Internal error: ast_make_var: symbol '%s' not found (line %d)\n",
                name, line);
        /* you can call sem_fatal here instead of just printing */
    }
    n->u.var.sym = s;

    return n;
}

ASTNode *ast_make_var_decl(char *name, Type *t, ASTNode *init, int line)
{
    ASTNode *n = ast_new(AST_VAR_DECL, t, line);
    n->u.var_decl.name      = name;
    n->u.var_decl.decl_type = t;
    n->u.var_decl.init      = init;   // μπορεί να είναι NULL
    return n;
}

/* ====================  STATEMENTS  ==================== */

/* assignment: lhs = rhs; 
 * t is the resulting expression type after sem_check_assignment.
 */
ASTNode *ast_make_assign(ASTNode *lhs, ASTNode *rhs, Type *t, int line)
{
    ASTNode *n = ast_new(AST_ASSIGN, t, line);
    n->u.assign.lhs = lhs;
    n->u.assign.rhs = rhs;
    return n;
}

/* if (cond) then_part else else_part; (else_part can be NULL) */
ASTNode *ast_make_if(ASTNode *cond, ASTNode *then_part, ASTNode *else_part, int line)
{
    ASTNode *n = ast_new(AST_IF, NULL, line);
    n->u.if_stmt.cond      = cond;
    n->u.if_stmt.then_part = then_part;
    n->u.if_stmt.else_part = else_part;
    return n;
}

/* while (cond) body; */
ASTNode *ast_make_while(ASTNode *cond, ASTNode *body, int line)
{
    ASTNode *n = ast_new(AST_WHILE, NULL, line);
    n->u.while_stmt.cond = cond;
    n->u.while_stmt.body = body;
    return n;
}

/* for (init; cond; step) body; 
 * any of init/cond/step can be NULL depending on syntax (e.g., for (;;)).
 */
ASTNode *ast_make_for(ASTNode *init, ASTNode *cond, ASTNode *step, ASTNode *body, int line)
{
    ASTNode *n = ast_new(AST_FOR, NULL, line);
    n->u.for_stmt.init = init;
    n->u.for_stmt.cond = cond;
    n->u.for_stmt.step = step;
    n->u.for_stmt.body = body;
    return n;
}

/* Optional: return node if you want it now */
ASTNode *ast_make_return(ASTNode *expr, int line)
{
    ASTNode *n = ast_new(AST_RETURN, NULL, line);
    n->u.ret_stmt.expr = expr;
    return n;
}

ASTNode *ast_make_call(ASTNode *func, ASTNode *args, Type *t, int line)
{
    ASTNode *n = ast_new(AST_CALL, t, line);
    n->u.call.func = func;
    n->u.call.args = args;   // usually a list node or NULL
    return n;
}

ASTNode *ast_make_func_decl(char *name, ASTNode *body, int line)
{
    ASTNode *n = ast_new(AST_FUNC_DECL, NULL, line);
    n->u.func_decl.name   = name;
    n->u.func_decl.params = NULL;   // προς το παρόν
    n->u.func_decl.body   = body;
    return n;
}

ASTNode *ast_make_index(ASTNode *array, ASTNode *index, Type *t, int line)
{
    ASTNode *n = ast_new(AST_INDEX, t, line);
    n->u.index.array = array;
    n->u.index.index = index;
    return n;
}

ASTNode *ast_make_cin(ASTNode *vars, int line)
{
    ASTNode *n = ast_new(AST_CIN, NULL, line);
    
    /* Αποθηκεύουμε τη λίστα των μεταβλητών εισόδου */
    n->u.io_stmt.io_list = vars;
    
    return n;
}

ASTNode *ast_make_cout(ASTNode *exprs, int line)
{
    ASTNode *n = ast_new(AST_COUT, NULL, line);
    
    /* Αποθηκεύουμε τη λίστα των εκφράσεων εξόδου */
    n->u.io_stmt.io_list = exprs;
    
    return n;
}

/* ast.c */

ASTNode *ast_make_enum_decl(char *name, ASTNode *constants, int line) {
    ASTNode *n = ast_new(AST_ENUM_DECL, NULL, line);
    n->u.enum_decl.name = name;
    n->u.enum_decl.constants = constants; // Λίστα με AST_ENUM_CONST
    return n;
}

ASTNode *ast_make_enum_const(char *name, int value, int line) {
    ASTNode *n = ast_new(AST_ENUM_CONST, type_int, line);
    n->u.enum_const.name = name;
    n->u.enum_const.value = value;
    return n;
}

//classes

ASTNode *ast_make_field(ASTNode *base, Symbol *member, Type *t, int line)
{
    ASTNode *n = ast_new(AST_FIELD, t, line);
    n->u.field.base = base;
    n->u.field.member = member;
    return n;
}

ASTNode *ast_make_break(int line) {
    return ast_new(AST_BREAK, NULL, line);
}

ASTNode *ast_make_continue(int line) {
    return ast_new(AST_CONTINUE, NULL, line);
}

ASTNode *ast_make_list_func(char *name, ASTNode *arg, Type *type, int line) {
    ASTNode *n = ast_new(AST_LIST_FUNC, type, line);
    n->u.list_func.name = strdup(name);
    n->u.list_func.arg = arg;
    return n;
}