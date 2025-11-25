/* types.h */
#ifndef TYPES_H
#define TYPES_H

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

typedef struct Type {
    TypeKind kind;
    struct Type * elem_type;
    int array_size;           // μόνο για TYPE_ARRAY, μία διάσταση
                              // 0 αν είναι άγνωστο / [] (open array)

    // αν θες multi-dimensional array, κάνεις nested arrays:
    // int A[3][5] =>
    //   TYPE_ARRAY (size=3)
    //       elem_type -> TYPE_ARRAY (size=5)
    //           elem_type -> TYPE_INT

    /* Για TYPE_CLASS και TYPE_UNION αργότερα θα μπει λίστα από fields */
} Type;


/* Global pointers για βασικούς τύπους (θα τα κάνουμε init στο symtab_init) */
extern Type *type_int;
extern Type *type_float;
extern Type *type_char;
extern Type *type_string;
extern Type *type_void;
extern Type *type_error;

// Type *make_simple_type(TypeKind kind);

Type *make_list_type(Type *elem);

void init_types(void);

Type *make_type(TypeKind kind);

Type *make_array_type(Type *elem_type, int size);
Type *attach_nested_array(Type *left, Type *right); /* left may be NULL */
Type *attach_array_to_base(Type *base, Type *dims); /* επιστρέφει τον τελικό τύπο */

#endif
