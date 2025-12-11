#ifndef AST_H
#define AST_H

#include "types.h"   // for Type*
#include "symbol.h"  // for Symbol*

typedef struct ASTNode ASTNode;

/* === Kinds of AST nodes === */
typedef enum {
    AST_PROGRAM,
    AST_FUNC_DECL,
    AST_BLOCK,
    AST_VAR_DECL,
    AST_ASSIGN,

    AST_IF,
    AST_WHILE,
    AST_FOR,
    AST_RETURN,

    AST_BINOP,
    AST_UNOP,
    AST_CALL,
    AST_VAR,
    AST_CONST,
    AST_LIST,

    AST_INDEX,   /* array[index] */
    // ... later: classes, enums, etc.
} ASTKind;

/* === Operators === */
typedef enum {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
    OP_LT, OP_LE, OP_GT, OP_GE,
    OP_EQ, OP_NE,
    OP_AND, OP_OR,
    OP_NOT,
    OP_PRE_INC, OP_PRE_DEC,
    OP_POST_INC, OP_POST_DEC,
    OP_SIZEOF,
    OP_LENGTH
} ASTOp;

/* === AST node structure === */
struct ASTNode {
    ASTKind kind;
    int     line;
    Type   *type;   /* result type for expressions, or NULL for statements */

    union {
        /* expressions */
        struct { ASTOp op; ASTNode *left, *right; } binop;
        struct { ASTOp op; ASTNode *expr;        } unop;

        /* function call: func(args) – func είναι expression node (π.χ. VAR) */
        struct { ASTNode *func; ASTNode *args; } call;

        /* variable reference */
        struct {
            char    *name;
            ASTNode *index;  /* for arrays, or NULL */
            ASTNode *field;  /* for obj.field, or NULL (future) */
            Symbol  *sym;    /* symbol table entry */
        } var;

        /* constants */
        struct {
            long   ival;
            double fval;
            char   cval;
            char  *sval;
        } constant;

        /* block: declarations + statements */
        struct { ASTNode *decls; ASTNode *stmts; } block;
        /* assignment: lhs = rhs */
        struct { ASTNode *lhs; ASTNode *rhs; } assign;
        /* if (cond) then_part else else_part */
        struct { ASTNode *cond; ASTNode *then_part; ASTNode *else_part; } if_stmt;
        /* while (cond) body */
        struct { ASTNode *cond; ASTNode *body; } while_stmt;
        /* for (init; cond; step) body */
        struct { ASTNode *init; ASTNode *cond; ASTNode *step; ASTNode *body; } for_stmt;
        /* return expr; */
        struct { ASTNode *expr; } ret_stmt;
        /* simple list (για λίστες expr/stmt, args, κτλ) – αν το θες */
        struct { ASTNode *head; ASTNode *tail; } list;
        /* array indexing: array[index] */
        struct { ASTNode *array; ASTNode *index; } index;
    } u;
};

/* Global root of AST */
extern ASTNode *ast_root;

//debug  print
void ast_print(ASTNode *root, FILE *out);

/* Constructors */

ASTNode *ast_make_var(char *name, Type *t, int line);

ASTNode *ast_make_binop(ASTOp op, ASTNode *l, ASTNode *r, Type *t, int line);
ASTNode *ast_make_unop(ASTOp op, ASTNode *e, Type *t, int line);

ASTNode *ast_make_const_int(long v, int line);
ASTNode *ast_make_const_char(char c, int line);
ASTNode *ast_make_const_float(double f, int line);
ASTNode *ast_make_const_string(const char *s, int line);

ASTNode *ast_make_assign(ASTNode *lhs, ASTNode *rhs, Type *t, int line);
ASTNode *ast_make_if(ASTNode *cond, ASTNode *then_part, ASTNode *else_part, int line);
ASTNode *ast_make_while(ASTNode *cond, ASTNode *body, int line);
ASTNode *ast_make_for(ASTNode *init, ASTNode *cond, ASTNode *step, ASTNode *body, int line);
ASTNode *ast_make_return(ASTNode *expr, int line);

ASTNode *ast_make_call(ASTNode *func, ASTNode *args, Type *t, int line);
ASTNode *ast_make_index(ASTNode *array, ASTNode *index, Type *t, int line);

#endif
