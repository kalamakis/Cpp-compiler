#ifndef AST_H
#define AST_H

#include "types.h"   // for Type*

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

    // ... later: classes, enums, etc.
} ASTKind;

typedef enum {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
    OP_LT, OP_LE, OP_GT, OP_GE,
    OP_EQ, OP_NE,
    OP_AND, OP_OR,
    OP_NOT,
    OP_PRE_INC, OP_PRE_DEC,
    OP_POST_INC, OP_POST_DEC,
} ASTOp;

typedef struct ASTNode {
    ASTKind kind;
    int line;

    Type *type;   // result type for expressions, or NULL for pure statements

    union {
        /* expressions */
        struct { ASTOp op; struct ASTNode *left, *right; } binop;
        struct { ASTOp op; struct ASTNode *expr; } unop;
        struct { char *name; struct ASTNode *args; } call; // args as list/linked list
        struct {
            char           *name;
            struct ASTNode *index;  /* for arrays, or NULL */
            struct ASTNode *field;  /* for obj.field, or NULL */
            Symbol         *sym;    /* symbol table entry */
        } var;
        struct { /* literal */ 
            long   ival;
            double fval;
            char   cval;
            char  *sval;
        } constant;

        /* statements */
        struct { struct ASTNode *decls; struct ASTNode *stmts; } block;
        struct { struct ASTNode *lhs; struct ASTNode *rhs; } assign;
        struct { struct ASTNode *cond; struct ASTNode *then_part; struct ASTNode *else_part; } if_stmt;
        struct { struct ASTNode *cond; struct ASTNode *body; } while_stmt;
        struct { struct ASTNode *init; struct ASTNode *cond; struct ASTNode *step; struct ASTNode *body; } for_stmt;
        struct { struct ASTNode *expr; } ret_stmt;

        /* simple list chaining (for arg lists, stmt lists, etc.) */
        struct { struct ASTNode *head; struct ASTNode *tail; } list;
    } u;
} ASTNode;

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

#endif
