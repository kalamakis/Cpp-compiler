#ifndef TYPES_H
#define TYPES_H

#include "hashtable.h" 
struct Symbol;

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_ENUM,
    TYPE_ARRAY,
    TYPE_LIST,
    TYPE_CLASS,
    TYPE_UNION,
    TYPE_VOID,
    TYPE_ERROR
} TypeKind;

//NOTE when adding stuff here update make simple type
typedef struct Type {
    TypeKind kind;
    struct Type * elem_type;
    int array_size;           // μόνο για TYPE_ARRAY, μία διάσταση
    /* Για TYPE_CLASS και TYPE_UNION αργότερα θα μπει λίστα από fields */
    char *enum_name;

    char   *tag_name;         // "C"
    struct Type *base_type;   // base class ή NULL
    HASHTBL *members;         // key=name -> (Symbol*) fields/methods
    int      size;
    int      align;
} Type;

typedef struct EnumBuilder {
    Type *enum_type;   // το TYPE_ENUM που δημιουργείται
    int next_value;    // η επόμενη default τιμή (0,1,2,...)
} EnumBuilder;

/* Global pointers για βασικούς τύπους (θα τα κάνουμε init στο symtab_init) */
extern Type *type_int;
extern Type *type_float;
extern Type *type_char;
extern Type *type_string;
extern Type *type_void;
extern Type *type_error;

Type *make_list_type(Type *elem);

void init_types(void);

Type *make_simple_type(TypeKind kind);

Type *make_array_type(Type *elem_type, int size);
Type *attach_nested_array(Type *left, Type *right); /* left may be NULL */
Type *attach_array_to_base(Type *base, Type *dims); /* επιστρέφει τον τελικό τύπο */

//Enums for now
Type *make_enum_type(const char *name);
EnumBuilder *start_enum(const char *name);
int add_enum_constant(EnumBuilder *eb, const char *name, int value, int has_explicit);
Type *end_enum(EnumBuilder *eb);


//classes
Type *make_class_type(const char *name, Type *base_type);

Type *make_union_type(const char *name);
#endif
