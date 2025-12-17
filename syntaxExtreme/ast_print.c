/* ast_print.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ast.h"
#include "types.h"
#include "symbol.h"

/* ---------------- DOT escaping ---------------- */

static void dot_fprint_escaped(FILE *out, const char *s) {
    if (!s) return;
    for (const unsigned char *p = (const unsigned char*)s; *p; ++p) {
        switch (*p) {
            case '\\': fputs("\\\\", out); break;
            case '\"': fputs("\\\"", out); break;
            case '\n': fputs("\\n", out); break;
            case '\r': break;
            case '\t': fputs(" ", out); break;
            default:
                if (*p >= 32 && *p < 127) fputc(*p, out);
                else fputc('?', out);
                break;
        }
    }
}

static const char *stor_to_string(StorageClass s) {
    switch (s) {
        case STOR_GLOBAL: return "GLOBAL";
        case STOR_LOCAL:  return "LOCAL";
        case STOR_PARAM:  return "PARAM";
        case STOR_FIELD:  return "FIELD";
        case STOR_TEMP:   return "TEMP";
        default:          return "?";
    }
}

/* ---------------- Type pretty print ---------------- */

static void type_to_string_rec(Type *t, char *buf, size_t cap) {
    if (!buf || cap == 0) return;
    buf[0] = '\0';

    if (!t) {
        snprintf(buf, cap, "<?>");
        return;
    }

    switch (t->kind) {
        case TYPE_INT:    snprintf(buf, cap, "int"); break;
        case TYPE_FLOAT:  snprintf(buf, cap, "float"); break;
        case TYPE_CHAR:   snprintf(buf, cap, "char"); break;
        case TYPE_STRING: snprintf(buf, cap, "string"); break;
        case TYPE_VOID:   snprintf(buf, cap, "void"); break;
        case TYPE_ERROR:  snprintf(buf, cap, "<error>"); break;

        case TYPE_ENUM:
            if (t->enum_name) snprintf(buf, cap, "enum %s", t->enum_name);
            else snprintf(buf, cap, "enum<?>");
            break;

        case TYPE_LIST: {
            char inner[256];
            type_to_string_rec(t->elem_type, inner, sizeof(inner));
            snprintf(buf, cap, "list<%s>", inner);
            break;
        }

        case TYPE_ARRAY: {
            char inner[256];
            type_to_string_rec(t->elem_type, inner, sizeof(inner));
            if (t->array_size > 0) snprintf(buf, cap, "%s[%d]", inner, t->array_size);
            else snprintf(buf, cap, "%s[]", inner);
            break;
        }

        case TYPE_CLASS:  snprintf(buf, cap, "class"); break;
        case TYPE_UNION:  snprintf(buf, cap, "union"); break;

        default:
            snprintf(buf, cap, "<?>");
            break;
    }
}

/* ---------------- Enum->string helpers ---------------- */

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

static const char *kind_to_string(ASTKind k) {
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
        default:            return "NODE";
    }
}

static const char *symkind_to_string(SymbolKind k) {
    switch (k) {
        case SYM_VAR:        return "VAR";
        case SYM_CONST:      return "CONST";
        case SYM_FUNC:       return "FUNC";
        case SYM_PARAM:      return "PARAM";
        case SYM_TYPE:       return "TYPE";
        case SYM_ENUM_CONST: return "ENUM_CONST";
        default:             return "?";
    }
}

/* ---------------- DOT printing core ---------------- */

static int g_next_id = 0;

static void edge(FILE *out, int from, int to, const char *label) {
    if (!label || !label[0]) {
        fprintf(out, "  n%d -> n%d;\n", from, to);
        return;
    }
    fprintf(out, "  n%d -> n%d [label=\"", from, to);
    dot_fprint_escaped(out, label);
    fprintf(out, "\"];\n");
}

static int ast_print_dot_rec(ASTNode *n, FILE *out) {
    if (!n) return -1;

    int my_id = g_next_id++;

    const char *kname = kind_to_string(n->kind);

    /* extra label lines */
    char extra[640];
    extra[0] = '\0';

    /* type label */
    char tbuf[256];
    tbuf[0] = '\0';
    if (n->type && n->type->kind != TYPE_ERROR) {
        type_to_string_rec(n->type, tbuf, sizeof(tbuf));
    }

    switch (n->kind) {
        case AST_FUNC_DECL:
            if (n->u.func_decl.name)
                snprintf(extra, sizeof(extra), "%s", n->u.func_decl.name);
            break;

        case AST_VAR:
            if (n->u.var.name) {
                if (n->u.var.sym) {
                    Symbol *s = n->u.var.sym;

                    char symt[256]; symt[0] = '\0';
                    if (s->type && s->type != type_error) type_to_string_rec(s->type, symt, sizeof(symt));

                    snprintf(extra, sizeof(extra),
                        "%s"
                        "\n[sym @%p]"
                        "\nkind:%s(%d) scope:%d"
                        "\nstor:%s(%d) off:%d ref:%d"
                        "\n%s%s",
                        n->u.var.name,
                        (void*)s,
                        symkind_to_string(s->kind), (int)s->kind, s->scope,
                        stor_to_string(s->storage), (int)s->storage, s->offset, s->is_ref_param,
                        symt[0] ? "\nsymtype:" : "",
                        symt[0] ? symt : ""
                    );
                } else {
                    snprintf(extra, sizeof(extra), "%s\\n[sym NULL]", n->u.var.name);
                }
            }
            break;

        case AST_VAR_DECL: {
            char declt[256]; declt[0] = '\0';
            type_to_string_rec(n->u.var_decl.decl_type, declt, sizeof(declt));
            if (n->u.var_decl.name && declt[0])
                snprintf(extra, sizeof(extra), "%s : %s", n->u.var_decl.name, declt);
            else if (n->u.var_decl.name)
                snprintf(extra, sizeof(extra), "%s", n->u.var_decl.name);
            else if (declt[0])
                snprintf(extra, sizeof(extra), ": %s", declt);
            break;
        }

        case AST_CONST:
            if (n->type) {
                switch (n->type->kind) {
                    case TYPE_INT:
                        snprintf(extra, sizeof(extra), "%ld", (long)n->u.constant.ival);
                        break;
                    case TYPE_FLOAT:
                        snprintf(extra, sizeof(extra), "%g", n->u.constant.fval);
                        break;
                    case TYPE_CHAR:
                        snprintf(extra, sizeof(extra), "'%c'", n->u.constant.cval);
                        break;
                    case TYPE_STRING: {
                        const char *s = n->u.constant.sval ? n->u.constant.sval : "";
                        char short_s[96];
                        if (strlen(s) > 70) {
                            snprintf(short_s, sizeof(short_s), "%.70s...", s);
                            s = short_s;
                        }
                        snprintf(extra, sizeof(extra), "\"%s\"", s);
                        break;
                    }
                    default:
                        snprintf(extra, sizeof(extra), "(const)");
                        break;
                }
            } else {
                snprintf(extra, sizeof(extra), "(const)");
            }
            break;

        case AST_BINOP:
            snprintf(extra, sizeof(extra), "%s", op_to_string(n->u.binop.op));
            break;

        case AST_UNOP:
            snprintf(extra, sizeof(extra), "%s", op_to_string(n->u.unop.op));
            break;

        case AST_CALL:
                if (n->u.call.func && n->u.call.func->kind == AST_VAR) {
                ASTNode *fv = n->u.call.func;
                const char *fname = fv->u.var.name ? fv->u.var.name : "<anon>";
                if (fv->u.var.sym) {
                    snprintf(extra, sizeof(extra), "%s()\\ncallee kind:%s(%d) scope:%d",
                            fname,
                            symkind_to_string(fv->u.var.sym->kind), (int)fv->u.var.sym->kind,
                            fv->u.var.sym->scope);
                } else {
                    snprintf(extra, sizeof(extra), "%s()\\ncallee sym NULL", fname);
                }
            } else {
                snprintf(extra, sizeof(extra), "call");
            }
            break;

        case AST_INDEX:
            snprintf(extra, sizeof(extra), "[]");
            break;

        default:
            break;
    }

    /* Emit node label */
    fprintf(out, "  n%d [label=\"", my_id);
    dot_fprint_escaped(out, kname);

    if (extra[0]) {
        fputs("\\n", out);
        dot_fprint_escaped(out, extra);
    }

    if (tbuf[0]) {
        fputs("\\n<", out);
        dot_fprint_escaped(out, tbuf);
        fputs(">", out);
    }

    fprintf(out, "\\n(line %d)", n->line);
    fprintf(out, "\"];\n");

    /* Children with labeled edges */
    #define CHILD(lbl, field) \
        do { \
            if ((field)) { \
                int cid = ast_print_dot_rec((field), out); \
                if (cid >= 0) edge(out, my_id, cid, (lbl)); \
            } \
        } while (0)

    switch (n->kind) {
        case AST_PROGRAM:
            CHILD("globals",  n->u.program.globals);
            CHILD("main",     n->u.program.main_func);
            break;

        case AST_BLOCK:
            CHILD("decls",    n->u.block.decls);
            CHILD("stmts",    n->u.block.stmts);
            break;

        case AST_FUNC_DECL:
            CHILD("params",   n->u.func_decl.params);
            CHILD("body",     n->u.func_decl.body);
            break;

        case AST_VAR_DECL:
            CHILD("init",     n->u.var_decl.init);
            break;

        case AST_ASSIGN:
            CHILD("lhs",      n->u.assign.lhs);
            CHILD("rhs",      n->u.assign.rhs);
            break;

        case AST_IF:
            CHILD("cond",     n->u.if_stmt.cond);
            CHILD("then",     n->u.if_stmt.then_part);
            CHILD("else",     n->u.if_stmt.else_part);
            break;

        case AST_WHILE:
            CHILD("cond",     n->u.while_stmt.cond);
            CHILD("body",     n->u.while_stmt.body);
            break;

        case AST_FOR:
            CHILD("init",     n->u.for_stmt.init);
            CHILD("cond",     n->u.for_stmt.cond);
            CHILD("step",     n->u.for_stmt.step);
            CHILD("body",     n->u.for_stmt.body);
            break;

        case AST_RETURN:
            CHILD("expr",     n->u.ret_stmt.expr);
            break;

        case AST_BINOP:
            CHILD("left",     n->u.binop.left);
            CHILD("right",    n->u.binop.right);
            break;

        case AST_UNOP:
            CHILD("expr",     n->u.unop.expr);
            break;

        case AST_CALL:
            CHILD("callee",   n->u.call.func);
            CHILD("args",     n->u.call.args);
            break;

        case AST_VAR:
            /* These exist in your AST for convenience */
            CHILD("index",    n->u.var.index);
            CHILD("field",    n->u.var.field);
            break;

        case AST_INDEX:
            CHILD("array",    n->u.index.array);
            CHILD("index",    n->u.index.index);
            break;

        case AST_LIST:
            CHILD("head",     n->u.list.head);
            CHILD("tail",     n->u.list.tail);
            break;

        default:
            break;
    }

    #undef CHILD
    return my_id;
}

/* ---------------- public API ---------------- */

static void make_png_name(const char *dotfile, char *pngfile, size_t cap) {
    if (!dotfile || !pngfile || cap == 0) return;
    pngfile[0] = '\0';

    size_t L = strlen(dotfile);
    if (L >= 4 && strcmp(dotfile + (L - 4), ".dot") == 0) {
        snprintf(pngfile, cap, "%.*s.png", (int)(L - 4), dotfile);
    } else {
        snprintf(pngfile, cap, "%s.png", dotfile);
    }
}

void ast_print(ASTNode *root, const char *filename) {
    if (!root) {
        fprintf(stderr, "AST is empty, nothing to print.\n");
        return;
    }
    if (!filename || !filename[0]) {
        fprintf(stderr, "ast_print: missing output filename.\n");
        return;
    }

    FILE *out = fopen(filename, "w");
    if (!out) {
        perror("fopen");
        return;
    }

    g_next_id = 0;

    fprintf(out, "digraph AST {\n");
    fprintf(out, "  node [shape=box, fontname=\"Courier\"];\n");
    fprintf(out, "  edge [fontname=\"Courier\"];\n");

    (void)ast_print_dot_rec(root, out);

    fprintf(out, "}\n");
    fclose(out);

    printf("AST DOT written to %s\n", filename);

    /* Optional PNG via graphviz */
    char pngfile[1024];
    make_png_name(filename, pngfile, sizeof(pngfile));

    char cmd[2048];
    snprintf(cmd, sizeof(cmd), "dot -Tpng \"%s\" -o \"%s\"", filename, pngfile);

    int rc = system(cmd);
    if (rc == 0) {
        printf("AST PNG written to %s\n", pngfile);
    } else {
        printf("(note) Could not run Graphviz 'dot' to create PNG. DOT is still OK.\n");
    }
}
