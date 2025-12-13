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
// typedef struct {
//     char    *name;
//     Type    *decl_type;   // ο τύπος της μεταβλητής (π.χ. int, float[], list<int>...)
//     ASTNode *init;        // optional initializer expr, ή NULL
// } ASTVarDecl;

/* === AST node structure === */
struct ASTNode {
    ASTKind kind;
    int     line;
    Type   *type;   /* result type for expressions, or NULL for statements */

    union {
        /* expressions */
        struct { ASTOp op; struct ASTNode *left, *right; } binop;
        struct { ASTOp op; struct ASTNode *expr; } unop;
        struct {struct ASTNode *func; struct ASTNode *args;} call;
        struct {char *name; struct ASTNode *params; struct ASTNode *body;} func_decl;
        struct {
            char           *name;
            struct ASTNode *index;  /* για a[i] */
            struct ASTNode *field;  /* obj.field */
            Symbol         *sym;
        } var;
        struct { char *name; Type *decl_type; struct ASTNode *init; } var_decl;
        struct { 
            long   ival;
            double fval;
            char   cval;
            char  *sval;
        } constant;

        /* program / blocks / statements */
        struct { struct ASTNode *globals; struct ASTNode *main_func; } program;
        struct { struct ASTNode *decls; struct ASTNode *stmts; } block;
        struct { struct ASTNode *lhs; struct ASTNode *rhs; } assign;
        struct { struct ASTNode *cond; struct ASTNode *then_part; struct ASTNode *else_part; } if_stmt;
        struct { struct ASTNode *cond; struct ASTNode *body; } while_stmt;
        struct { struct ASTNode *init; struct ASTNode *cond; struct ASTNode *step; struct ASTNode *body; } for_stmt;
        struct { struct ASTNode *expr; } ret_stmt;

        /* index κόμβος */
        struct { struct ASTNode *array; struct ASTNode *index;} index;

        /* λίστα */
        struct { struct ASTNode *head; struct ASTNode *tail; } list;
    } u;


};

ASTNode *ast_make_list(ASTNode *head, ASTNode *tail, int line);
ASTNode *ast_list_append(ASTNode *list, ASTNode *elem, int line);

/* Global root of AST */
extern ASTNode *ast_root;

//debug  print
void ast_print(ASTNode *root, const char *filename);

/* Constructors */
ASTNode *ast_make_program(ASTNode *globals, ASTNode *main_func, int line);

ASTNode *ast_make_var(char *name, Type *t, int line);
ASTNode *ast_make_var_decl(char *name, Type *t, ASTNode *init, int line);

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
ASTNode *ast_make_func_decl(char *name, ASTNode *body, int line);
ASTNode *ast_make_index(ASTNode *array, ASTNode *index, Type *t, int line);




#endif
