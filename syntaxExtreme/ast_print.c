/* ast_dot.c : emit AST as Graphviz DOT */

#include <stdio.h>
#include "ast.h"
#include "types.h"

/* Μπορείς να χρησιμοποιήσεις τα ίδια helpers με ast_print.c,
   εδώ βάζω μικρές εκδοχές για να είναι self-contained. */

static const char *astop_to_string(ASTOp op) {
    switch (op) {
    case OP_ADD:       return "+";
    case OP_SUB:       return "-";
    case OP_MUL:       return "*";
    case OP_DIV:       return "/";
    case OP_MOD:       return "%";
    case OP_LT:        return "<";
    case OP_LE:        return "<=";
    case OP_GT:        return ">";
    case OP_GE:        return ">=";
    case OP_EQ:        return "==";
    case OP_NE:        return "!=";
    case OP_AND:       return "&&";
    case OP_OR:        return "||";
    case OP_NOT:       return "!";
    case OP_PRE_INC:   return "++ (pre)";
    case OP_PRE_DEC:   return "-- (pre)";
    case OP_POST_INC:  return "++ (post)";
    case OP_POST_DEC:  return "-- (post)";
    case OP_SIZEOF:    return "sizeof";
    case OP_LENGTH:    return "length";
    default:           return "?op?";
    }
}

static const char *astkind_to_string(ASTKind k) {
    switch (k) {
    case AST_PROGRAM:   return "PROGRAM";
    case AST_FUNC_DECL: return "FUNC_DECL";
    case AST_BLOCK:     return "BLOCK";
    case AST_VAR_DECL:  return "VAR_DECL";
    case AST_ASSIGN:    return "ASSIGN";
    case AST_IF:        return "IF";
    case AST_WHILE:     return "WHILE";
    case AST_FOR:       return "FOR";
    case AST_RETURN:    return "RETURN";
    case AST_BINOP:     return "BINOP";
    case AST_UNOP:      return "UNOP";
    case AST_CALL:      return "CALL";
    case AST_VAR:       return "VAR";
    case AST_CONST:     return "CONST";
    case AST_LIST:      return "LIST";
    case AST_INDEX:     return "INDEX";
    default:            return "UNKNOWN";
    }
}

/* Για όνομα κόμβου στη DOT χρησιμοποιούμε pointer -> μοναδικό id */
static void node_id(char *buf, size_t sz, ASTNode *n) {
    snprintf(buf, sz, "n%p", (void*)n);
}

/* Δηλώνει κόμβο με label */
static void emit_node_decl(FILE *out, ASTNode *n) {
    if (!n) return;
    char id[64];
    node_id(id, sizeof id, n);

    const char *kind = astkind_to_string(n->kind);

    fprintf(out, "  %s [label=\"%s", id, kind);

    switch (n->kind) {
    case AST_BINOP:
        fprintf(out, "\\n%s", astop_to_string(n->u.binop.op));
        break;
    case AST_UNOP:
        fprintf(out, "\\n%s", astop_to_string(n->u.unop.op));
        break;
    case AST_VAR:
        if (n->u.var.name)
            fprintf(out, "\\n%s", n->u.var.name);
        break;
    case AST_CONST:
        if (n->type == type_int) {
            fprintf(out, "\\n%ld", n->u.constant.ival);
        } else if (n->type == type_float) {
            fprintf(out, "\\n%g", n->u.constant.fval);
        } else if (n->type == type_char) {
            fprintf(out, "\\n'%c'", n->u.constant.cval);
        } else if (n->type == type_string && n->u.constant.sval) {
            /* escape απλά τα " με ' */
            fprintf(out, "\\n\\\"%s\\\"", n->u.constant.sval);
        }
        break;
    default:
        /* τίποτα extra */
        break;
    }

    fprintf(out, "\"];\n");
}

/* Forward */
static void ast_emit_dot_rec(ASTNode *n, FILE *out);

/* Helper για edges */
static void emit_edge(FILE *out, ASTNode *from, ASTNode *to, const char *label) {
    if (!from || !to) return;
    char id_from[64], id_to[64];
    node_id(id_from, sizeof id_from, from);
    node_id(id_to, sizeof id_to, to);
    if (label)
        fprintf(out, "  %s -> %s [label=\"%s\"];\n", id_from, id_to, label);
    else
        fprintf(out, "  %s -> %s;\n", id_from, id_to);
}

static void emit_list(FILE *out, ASTNode *list) {
    /* Υποθέτουμε λίστα AST_LIST(head, tail) */
    while (list) {
        if (list->kind == AST_LIST) {
            if (list->u.list.head) {
                ast_emit_dot_rec(list->u.list.head, out);
            }
            list = list->u.list.tail;
        } else {
            ast_emit_dot_rec(list, out);
            break;
        }
    }
}

static void ast_emit_dot_rec(ASTNode *n, FILE *out) {
    if (!n) return;

    /* δήλωση κόμβου */
    emit_node_decl(out, n);

    switch (n->kind) {
    case AST_BINOP:
        if (n->u.binop.left) {
            emit_node_decl(out, n->u.binop.left);
            emit_edge(out, n, n->u.binop.left, "L");
            ast_emit_dot_rec(n->u.binop.left, out);
        }
        if (n->u.binop.right) {
            emit_node_decl(out, n->u.binop.right);
            emit_edge(out, n, n->u.binop.right, "R");
            ast_emit_dot_rec(n->u.binop.right, out);
        }
        break;

    case AST_UNOP:
        if (n->u.unop.expr) {
            emit_node_decl(out, n->u.unop.expr);
            emit_edge(out, n, n->u.unop.expr, "expr");
            ast_emit_dot_rec(n->u.unop.expr, out);
        }
        break;

    case AST_ASSIGN:
        if (n->u.assign.lhs) {
            emit_node_decl(out, n->u.assign.lhs);
            emit_edge(out, n, n->u.assign.lhs, "lhs");
            ast_emit_dot_rec(n->u.assign.lhs, out);
        }
        if (n->u.assign.rhs) {
            emit_node_decl(out, n->u.assign.rhs);
            emit_edge(out, n, n->u.assign.rhs, "rhs");
            ast_emit_dot_rec(n->u.assign.rhs, out);
        }
        break;

    case AST_VAR:
        if (n->u.var.index) {
            emit_node_decl(out, n->u.var.index);
            emit_edge(out, n, n->u.var.index, "index");
            ast_emit_dot_rec(n->u.var.index, out);
        }
        if (n->u.var.field) {
            emit_node_decl(out, n->u.var.field);
            emit_edge(out, n, n->u.var.field, "field");
            ast_emit_dot_rec(n->u.var.field, out);
        }
        break;

    case AST_CONST:
        /* φύλλο – τίποτα άλλο */
        break;

    case AST_IF:
        if (n->u.if_stmt.cond) {
            emit_node_decl(out, n->u.if_stmt.cond);
            emit_edge(out, n, n->u.if_stmt.cond, "cond");
            ast_emit_dot_rec(n->u.if_stmt.cond, out);
        }
        if (n->u.if_stmt.then_part) {
            emit_node_decl(out, n->u.if_stmt.then_part);
            emit_edge(out, n, n->u.if_stmt.then_part, "then");
            ast_emit_dot_rec(n->u.if_stmt.then_part, out);
        }
        if (n->u.if_stmt.else_part) {
            emit_node_decl(out, n->u.if_stmt.else_part);
            emit_edge(out, n, n->u.if_stmt.else_part, "else");
            ast_emit_dot_rec(n->u.if_stmt.else_part, out);
        }
        break;

    case AST_WHILE:
        if (n->u.while_stmt.cond) {
            emit_node_decl(out, n->u.while_stmt.cond);
            emit_edge(out, n, n->u.while_stmt.cond, "cond");
            ast_emit_dot_rec(n->u.while_stmt.cond, out);
        }
        if (n->u.while_stmt.body) {
            emit_node_decl(out, n->u.while_stmt.body);
            emit_edge(out, n, n->u.while_stmt.body, "body");
            ast_emit_dot_rec(n->u.while_stmt.body, out);
        }
        break;

    case AST_FOR:
        if (n->u.for_stmt.init) {
            emit_node_decl(out, n->u.for_stmt.init);
            emit_edge(out, n, n->u.for_stmt.init, "init");
            ast_emit_dot_rec(n->u.for_stmt.init, out);
        }
        if (n->u.for_stmt.cond) {
            emit_node_decl(out, n->u.for_stmt.cond);
            emit_edge(out, n, n->u.for_stmt.cond, "cond");
            ast_emit_dot_rec(n->u.for_stmt.cond, out);
        }
        if (n->u.for_stmt.step) {
            emit_node_decl(out, n->u.for_stmt.step);
            emit_edge(out, n, n->u.for_stmt.step, "step");
            ast_emit_dot_rec(n->u.for_stmt.step, out);
        }
        if (n->u.for_stmt.body) {
            emit_node_decl(out, n->u.for_stmt.body);
            emit_edge(out, n, n->u.for_stmt.body, "body");
            ast_emit_dot_rec(n->u.for_stmt.body, out);
        }
        break;

    case AST_RETURN:
        if (n->u.ret_stmt.expr) {
            emit_node_decl(out, n->u.ret_stmt.expr);
            emit_edge(out, n, n->u.ret_stmt.expr, "expr");
            ast_emit_dot_rec(n->u.ret_stmt.expr, out);
        }
        break;

    case AST_CALL:
        if (n->u.call.func) {
            emit_node_decl(out, n->u.call.func);
            emit_edge(out, n, n->u.call.func, "func");
            ast_emit_dot_rec(n->u.call.func, out);
        }
        if (n->u.call.args) {
            emit_node_decl(out, n->u.call.args);
            emit_edge(out, n, n->u.call.args, "args");
            ast_emit_dot_rec(n->u.call.args, out);
        }
        break;

    case AST_INDEX:
        if (n->u.index.array) {
            emit_node_decl(out, n->u.index.array);
            emit_edge(out, n, n->u.index.array, "array");
            ast_emit_dot_rec(n->u.index.array, out);
        }
        if (n->u.index.index) {
            emit_node_decl(out, n->u.index.index);
            emit_edge(out, n, n->u.index.index, "index");
            ast_emit_dot_rec(n->u.index.index, out);
        }
        break;

    case AST_BLOCK:
        if (n->u.block.decls) {
            emit_node_decl(out, n->u.block.decls);
            emit_edge(out, n, n->u.block.decls, "decls");
            ast_emit_dot_rec(n->u.block.decls, out);
        }
        if (n->u.block.stmts) {
            emit_node_decl(out, n->u.block.stmts);
            emit_edge(out, n, n->u.block.stmts, "stmts");
            ast_emit_dot_rec(n->u.block.stmts, out);
        }
        break;

    case AST_LIST:
        emit_list(out, n);
        break;

    default:
        /* άλλα είδη προς το παρόν δεν χρησιμοποιούνται */
        break;
    }
}

void ast_print(ASTNode *root, FILE *out) {
    if (!out) return;
    fprintf(out, "digraph AST {\n");
    fprintf(out, "  node [shape=box, fontsize=10];\n");
    if (root) {
        ast_emit_dot_rec(root, out);
    }
    fprintf(out, "}\n");
}
