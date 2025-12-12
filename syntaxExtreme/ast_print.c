/* ast_print.c */
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

static void ast_print_dot_rec(ASTNode *n, FILE *out, int *id);

/* Η “δημόσια” συνάρτηση */
void ast_print(ASTNode *root, const char *filename)
{
    if (!root) {
        fprintf(stderr, "AST is empty, nothing to print.\n");
        return;
    }

    FILE *out = fopen(filename, "w");
    if (!out) {
        perror("fopen ast.dot");
        return;
    }
    printf("writing AST dot file to %s\n", filename);
    fprintf(out, "digraph AST {\n");
    fprintf(out, "  node [shape=box];\n");

    int id = 0;
    ast_print_dot_rec(root, out, &id);

    fprintf(out, "}\n");
    fclose(out);

    printf("creating png\n");
    /* προαιρετικά: τρέξε dot για εικόνα */
    system("dot -Tpng ast.dot -o ast.png");
}

static const char *op_to_string(ASTOp op) {
    switch (op) {
    case OP_ADD:  return "+";
    case OP_SUB:  return "-";
    case OP_MUL:  return "*";
    case OP_DIV:  return "/";
    case OP_MOD:  return "%";
    case OP_LT:   return "<";
    case OP_LE:   return "<=";
    case OP_GT:   return ">";
    case OP_GE:   return ">=";
    case OP_EQ:   return "==";
    case OP_NE:   return "!=";
    case OP_AND:  return "&&";
    case OP_OR:   return "||";
    case OP_NOT:  return "!";
    case OP_PRE_INC:  return "++ (pre)";
    case OP_PRE_DEC:  return "-- (pre)";
    case OP_POST_INC: return "++ (post)";
    case OP_POST_DEC: return "-- (post)";
    case OP_SIZEOF:   return "sizeof";
    case OP_LENGTH:   return "length";
    default:          return "?";
    }
}


/* Εδώ κάνεις DFS στο δέντρο και τυπώνεις κόμβους + ακμές */
static void ast_print_dot_rec(ASTNode *n, FILE *out, int *id)
{
    if (!n) return;

    int my_id = (*id)++;

    const char *kind = "NODE";
    char extra[128];
    extra[0] = '\0';

    switch (n->kind) {
        case AST_PROGRAM:  kind = "PROGRAM"; break;
        case AST_IF:       kind = "IF";      break;
        case AST_WHILE:    kind = "WHILE";   break;
        case AST_FOR:      kind = "FOR";     break;
        case AST_ASSIGN:   kind = "ASSIGN";  break;
        case AST_BINOP:    kind = "BINOP";   break;
        case AST_UNOP:     kind = "UNOP";    break;
        case AST_CONST:    kind = "CONST";   break;
        case AST_VAR:      kind = "VAR";     break;
        case AST_CALL:     kind = "CALL";    break;
        case AST_LIST:     kind = "LIST";    break;
        case AST_RETURN:   kind = "RETURN";  break;
        case AST_INDEX:    kind = "INDEX";   break;
        case AST_FUNC_DECL: kind = "FUNC";    break;
        case AST_VAR_DECL:  kind = "VARDECL"; break;
        default:           kind = "NODE";    break;
    }

    /* extra πληροφορίες ανά είδος κόμβου */
    switch (n->kind) {
    case AST_FUNC_DECL:
        kind = "FUNC";
        if (n->u.func_decl.name) {
            snprintf(extra, sizeof(extra), "\\n%s", n->u.func_decl.name);
        }
        break;
    case AST_VAR:
        if (n->u.var.name) {
            snprintf(extra, sizeof(extra), "\\n%s", n->u.var.name);
        }
        break;

    case AST_CONST:
        /* πολύ χοντρικά: αποφασίζεις από το type τι θα τυπώσεις */
        if (n->type == type_int) {
            snprintf(extra, sizeof(extra), "\\n%d", (int)n->u.constant.ival);
        } else if (n->type == type_float) {
            snprintf(extra, sizeof(extra), "\\n%g", n->u.constant.fval);
        } else if (n->type == type_char) {
            snprintf(extra, sizeof(extra), "\\n'%c'", n->u.constant.cval);
        } else if (n->type == type_string) {
            snprintf(extra, sizeof(extra), "\\n\"%s\"", n->u.constant.sval ? n->u.constant.sval : "");
        }
        break;

    case AST_BINOP:
        snprintf(extra, sizeof(extra), "\\n%s", op_to_string(n->u.binop.op));
        break;

    case AST_UNOP:
        snprintf(extra, sizeof(extra), "\\n%s", op_to_string(n->u.unop.op));
        break;

    case AST_CALL:
        /* αν η func είναι VAR, δείξε το όνομα της συνάρτησης */
        if (n->u.call.func &&
            n->u.call.func->kind == AST_VAR &&
            n->u.call.func->u.var.name) {
            snprintf(extra, sizeof(extra), "\\n%s()", n->u.call.func->u.var.name);
        }
        break;

    case AST_INDEX:
        snprintf(extra, sizeof(extra), "\\n[array index]");
        break;
    case AST_VAR_DECL: {
        if (n->u.var_decl.name) {
            snprintf(extra, sizeof(extra), "\\nVARDECL %s", n->u.var_decl.name);
        }
        break;
    }

    default:
        break;
    }

    fprintf(out, "  n%d [label=\"%s%s\\n(line %d)\"];\n",
            my_id, kind, extra, n->line);


    /* μικρό macro για παιδιά */
    #define CHILD(field) \
        do { \
            if ((field)) { \
                int child_id = *id; \
                ast_print_dot_rec((field), out, id); \
                fprintf(out, "  n%d -> n%d;\n", my_id, child_id); \
            } \
        } while (0)

        switch (n->kind) {
        case AST_IF:
            CHILD(n->u.if_stmt.cond);
            CHILD(n->u.if_stmt.then_part);
            CHILD(n->u.if_stmt.else_part);
            break;

        case AST_WHILE:
            CHILD(n->u.while_stmt.cond);
            CHILD(n->u.while_stmt.body);
            break;

        case AST_FOR:
            CHILD(n->u.for_stmt.init);
            CHILD(n->u.for_stmt.cond);
            CHILD(n->u.for_stmt.step);
            CHILD(n->u.for_stmt.body);
            break;

        case AST_ASSIGN:
            CHILD(n->u.assign.lhs);
            CHILD(n->u.assign.rhs);
            break;

        case AST_BINOP:
            CHILD(n->u.binop.left);
            CHILD(n->u.binop.right);
            break;

        case AST_UNOP:
            CHILD(n->u.unop.expr);
            break;

        case AST_VAR:
            CHILD(n->u.var.index);
            CHILD(n->u.var.field);
            break;

        case AST_LIST:
            CHILD(n->u.list.head);
            CHILD(n->u.list.tail);
            break;

        case AST_RETURN:
            CHILD(n->u.ret_stmt.expr);
            break;
        case AST_PROGRAM:
            CHILD(n->u.block.decls);
            CHILD(n->u.block.stmts);
            break;
        case AST_FUNC_DECL:
            CHILD(n->u.func_decl.body);
            break;
        

        default:
            break;
        }

#undef CHILD
}

