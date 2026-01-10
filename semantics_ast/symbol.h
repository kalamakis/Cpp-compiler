/* symbol.h */
#ifndef SYMBOL_H
#define SYMBOL_H

#include "types.h"

typedef enum {
    SYM_VAR,        // μεταβλητή
    SYM_CONST,      // σταθερά
    SYM_FUNC,       // συνάρτηση
    SYM_PARAM,      // παράμετρος
    SYM_TYPE,       // όνομα τύπου (π.χ. enum, class, union)
    SYM_ENUM_CONST, // σταθερά απαρίθμησης
} SymbolKind;

typedef enum {
    STOR_GLOBAL,
    STOR_LOCAL,
    STOR_PARAM,
    STOR_FIELD,
    STOR_TEMP
} StorageClass;

typedef struct Symbol {
    char        *name;
    SymbolKind   kind;
    Type        *type;
    int          scope;

    int          is_ref_param;   // για παραμέτρους συναρτησεων

    StorageClass storage;
    int          offset;     // θέση στο χώρο δεδομένων / frame

    union {
        struct {             // για σταθερές
            long   ival;
            double fval;
            char   cval;
            char  *sval;
        } c;

        struct {             // για συναρτήσεις
            int     param_count;
            struct Symbol **params;
            int     is_forward_decl;
        } func;

        struct {             // για enum constants
            int value;
        } enum_const;
    } u;
} Symbol;

#endif
