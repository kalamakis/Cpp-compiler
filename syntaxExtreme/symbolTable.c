/* symtab.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "settings.h"

#include "symbolTable.h"
#include "types.h"

HASHTBL *g_symtab = NULL;
int current_scope = 0;

/* destructor για τα data (Symbol*) όταν βγαίνουμε από ένα scope */
static void free_symbol(void *data)
{
    Symbol *sym = (Symbol*)data;
    if (!sym) return;

    /* Αν θες, εδώ free(sym->name), free(sym->u.func.params) κλπ */
    free(sym->name);
    if (sym->kind == SYM_FUNC && sym->u.func.params) {
        free(sym->u.func.params);
    }
    free(sym);
}

void symtab_init(void)
{
    g_symtab = hashtbl_create(211, NULL);
    current_scope = 0;

    type_int    = make_simple_type(TYPE_INT);
    type_float  = make_simple_type(TYPE_FLOAT);
    type_char   = make_simple_type(TYPE_CHAR);
    type_string = make_simple_type(TYPE_STRING);
    type_void   = make_simple_type(TYPE_VOID);
    type_error  = make_simple_type(TYPE_ERROR);
}

void symtab_enter_scope(void)
{
    current_scope++;
}

void symtab_leave_scope(void)
{
    if(HASHTBL_SHOW_GET&&HASHTBL_DEBUG) symtab_print();
    hashtbl_remove_scope(g_symtab, current_scope, free_symbol);
    current_scope--;
}

Symbol *symtab_insert(const char *name, SymbolKind kind, Type *type){
    return symtab_insert_scoped(name, kind, type, current_scope);
}

Symbol *symtab_insert_scoped(const char *name, SymbolKind kind, Type *type, int scope){
    Symbol *sym;

    // Έλεγχος για redeclaration στο ίδιο scope 
    sym = (Symbol*)hashtbl_lookup(g_symtab, name, scope);
    if (sym && sym->scope == scope) {

        return NULL;
    }

    sym = malloc(sizeof(Symbol));
    memset(sym, 0, sizeof(Symbol));

    sym->name   = strdup(name);
    sym->kind   = kind;
    sym->type   = type;
    sym->scope  = scope;
    //parameters
    sym->is_ref_param = 0;
    sym->u.func.param_count   = 0;
    sym->u.func.params        = NULL;
    sym->u.func.is_forward_decl = 0;

    sym->storage = (scope == 0) ? STOR_GLOBAL : STOR_LOCAL;
    sym->offset = -1;

    if (hashtbl_insert(g_symtab, name, sym, scope) != 0) {
        free_symbol(sym);
        return NULL;
    }

    return sym;
}

//search in all scopes
Symbol *symtab_lookup(const char *name)
{
    return (Symbol*)hashtbl_lookup(g_symtab, name, current_scope);
}

Symbol *symtab_lookup_in_scope(const char *name, int scope){
    return (Symbol*)hashtbl_lookup(g_symtab, name, scope);
}

//search in curr scope
Symbol *symtab_lookup_current(const char *name)
{
    Symbol *sym = (Symbol*)hashtbl_lookup(g_symtab, name, current_scope);
    if (sym && sym->scope == current_scope)
        return sym;
    return NULL;
}

void func_add_param(Symbol *func, Symbol *param) {
    if (!func || func->kind != SYM_FUNC || !param) return;

    int n = func->u.func.param_count;
    Symbol **new_arr = realloc(func->u.func.params, (n + 1) * sizeof(Symbol*));
    if (!new_arr) {
        fprintf(stderr, "Out of memory while adding parameter '%s'\n", param->name);
        exit(EXIT_FAILURE);
    }

    func->u.func.params = new_arr;
    func->u.func.params[n] = param;
    func->u.func.param_count++;
}

void symtab_print(void)
{
    printf("----- Symbol Table (up to scope %d) -----\n", current_scope);

    if (!g_symtab) {
        printf("(symbol table not initialized)\n");
        printf("----------------------------------------\n");
        return;
    }

    for (int s = 0; s <= current_scope; ++s) {
        printf("Scope %d:\n", s);

        for (hash_size i = 0; i < g_symtab->size; ++i) {
            struct hashnode_s *node = g_symtab->nodes[i];
            while (node) {
                Symbol *sym = (Symbol*)node->data;
                if (!sym) {
                    node = node->next;
                    continue;
                }

                if (sym->scope == s) {
                    const char *kind_str =
                        (sym->kind == SYM_VAR)        ? "VAR" :
                        (sym->kind == SYM_CONST)      ? "CONST" :
                        (sym->kind == SYM_FUNC)       ? "FUNC" :
                        (sym->kind == SYM_PARAM)      ? "PARAM" :
                        (sym->kind == SYM_TYPE)       ? "TYPE" :
                        (sym->kind == SYM_ENUM_CONST) ? "ENUM_CONST" : "UNKNOWN";
                                                         

                    const char *type_str;

                    if (!sym->type) {
                        type_str = "(null)";
                    } else {
                        switch (sym->type->kind) {
                            case TYPE_INT:    type_str = "int";    break;
                            case TYPE_FLOAT:  type_str = "float";  break;
                            case TYPE_CHAR:   type_str = "char";   break;
                            case TYPE_STRING: type_str = "string"; break;
                            case TYPE_ENUM:   type_str = "enum";   break;
                            case TYPE_ARRAY:  type_str = "array";  break;
                            case TYPE_LIST:   type_str = "list";   break;
                            case TYPE_CLASS:  type_str = "class";  break;
                            case TYPE_UNION:  type_str = "union";  break;
                            case TYPE_VOID:   type_str = "void";   break;
                            case TYPE_ERROR:  type_str = "error";  break;
                            default:          type_str = "?";      break;
                        }
                    }

                    printf("  %-12s %-10s type=%-8s scope=%d\n",
                           sym->name ? sym->name : "(noname)",
                           kind_str,
                           type_str,
                           sym->scope);
                }

                node = node->next;
            }
        }
    }

    printf("----------------------------------------\n");
}

