/* symtab.h */
#ifndef SYMTAB_H
#define SYMTAB_H

#include "hashtable.h"
#include "symbol.h"

extern HASHTBL *g_symtab;
extern int current_scope;

void symtab_init(void);
void symtab_enter_scope(void);
void symtab_leave_scope(void);

Symbol *symtab_insert(const char *name, SymbolKind kind, Type *type);

Symbol *symtab_lookup(const char *name);          // for all scopes
Symbol *symtab_lookup_current(const char *name);  // μόνο current_scope

/* Για debug / εκτύπωση ΧΔ */
void symtab_print(void);

#endif
