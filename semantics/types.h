/* types.h ή στην αρχή του hashtable.h, πριν από το SymbolInfo */

#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_VOID,
    TYPE_ENUM,
    TYPE_ARRAY,
    TYPE_LIST,
    TYPE_CLASS,
    TYPE_UNION,
    TYPE_ERROR
} TypeKind;

typedef enum {
    SYM_VAR,
    SYM_FUNC,
    SYM_PARAM,
    SYM_TYPEDEFF,   /* typedef, class, enum κλπ. */
    SYM_TYPE,
    SYM_CLASS,
    SYM_ENUM,
    SYM_FIELD
} SymbolKind;

/* forward declaration για να το χρησιμοποιήσουμε μέσα στο Type */
struct SymbolInfo;

#define MAX_DIMS 8

typedef struct Type {
    TypeKind kind;

    /* Για ARRAY και LIST: στοιχειώδης τύπος (element type) */
    struct Type *elem;
    int ndims;
    int dims[MAX_DIMS];  /* προαιρετικά, αλλιώς δυναμικός πίνακας */

    /* Για ENUM / CLASS / UNION / TYPEDEFF:
       ποιο σύμβολο τα ορίζει (ή απλά το όνομά τους) */
    struct SymbolInfo *ref_symbol;
    /* ή απλά: char *tag_name; */

} Type;

typedef struct ParamInfo ParamInfo;
struct ParamInfo {
    char     *name;    /* όνομα παραμέτρου (προαιρετικό για semantic μόνο) */
    Type     *type;    /* τύπος παραμέτρου */
    ParamInfo *next;
};

typedef struct SymbolInfo {
    SymbolKind kind;
    Type      *type;      /* ΠΛΗΡΗΣ τύπος, όχι μόνο TypeKind */
    int        isConst;   /* για const μεταβλητές / πεδία */
    ParamInfo *params;    /* για συναρτήσεις: λίστα παραμέτρων (μπορεί να είναι NULL) */

    /* Προαιρετικά:
       - int scope_id_of_class;   // για κλάσεις
       - struct SymbolInfo *owner; // για πεδία/μεθόδους
    */
} SymbolInfo;



#endif
