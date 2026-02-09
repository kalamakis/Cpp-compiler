#include "types.h"
#include "symbol.h"
#include "symbolTable.h"
#include "error.h"
#include <stdlib.h>

Type *type_int = NULL;
Type *type_float = NULL;
Type *type_char = NULL;
Type *type_string = NULL;
Type *type_void = NULL;
Type *type_error = NULL;

Type *make_simple_type(TypeKind kind){
    Type *t = calloc(1, sizeof(Type));
    t->kind = kind;
    return t;
}

Type *make_list_type(Type *elem_type){
    Type *t = make_simple_type(TYPE_LIST);
    if (!t) return NULL;

    t->elem_type = elem_type;
    return t;
}

void init_types(void){
    if (!type_int)    type_int    = make_simple_type(TYPE_INT);
    if (!type_float)  type_float  = make_simple_type(TYPE_FLOAT);
    if (!type_char)   type_char   = make_simple_type(TYPE_CHAR);
    if (!type_string) type_string = make_simple_type(TYPE_STRING);
    if (!type_void)   type_void   = make_simple_type(TYPE_VOID);
    if (!type_error)  type_error  = make_simple_type(TYPE_ERROR);
}

Type *make_array_type(Type *elem_type, int size)
{
    Type *t=make_simple_type(TYPE_ARRAY);
    t->elem_type = elem_type;
    t->array_size = size;   // 0 -> open array []
    return t;
}

/* Στο dims: left = προηγούμενα dims, right = νέο dim node.
   Θέλουμε nested arrays: αναρτούμε το right στο τέλος του left. */
Type *attach_nested_array(Type *left, Type *right) {
    if (!left) return right;
    Type *t = left;
    while (t->elem_type) t = t->elem_type;
    t->elem_type = right;
    return left;
}

/* Στο variabledef: θέλουμε να gεμίσουμε τα elem_type των dims με το base type.*/
Type *attach_array_to_base(Type *base, Type *dims) {
    if (!dims) return base;
    Type *t = dims;
    while (t->elem_type) t = t->elem_type;
    t->elem_type = base;
    return dims;
}

Type *make_enum_type(const char *name){
    Type *t = make_simple_type(TYPE_ENUM);
    if (!t) return NULL;
    if (name) {
        t->enum_name = strdup(name);
    } else {
        t->enum_name = NULL;
    }
    return t;
}

/* Ξεκινά η κατασκευή ενός enum */
EnumBuilder *start_enum(const char *name)
{
    EnumBuilder *eb = malloc(sizeof(EnumBuilder));
    if (!eb) return NULL;

    eb->enum_type = make_enum_type(name); 
    eb->next_value = 0;

    return eb;
}

/* Προσθέτει ένα enum constant και το καταχωρεί στη symbol table με fullname */
int add_enum_constant(EnumBuilder *eb, const char *name, int explicit_value, int has_explicit) {
    if (!eb || !eb->enum_type) return 0;

    // Έλεγχος αν η σταθερά υπάρχει ήδη στον πίνακα συμβόλων για τον ίδιο enum τύπο
    Symbol *sym = symtab_lookup(name);
    if (sym && sym->kind == SYM_ENUM_CONST && sym->type == eb->enum_type) {
        return 0; // redeclaration
    }

    // Δημιουργία συμβόλου για τη σταθερά με απλό όνομα
    Symbol *new_sym = symtab_insert(name, SYM_ENUM_CONST, eb->enum_type);
    if (!new_sym) return 0;

    // Ορισμός της τιμής
    if (has_explicit) {
        new_sym->u.enum_const.value = explicit_value;
        eb->next_value = explicit_value + 1;
    } else {
        new_sym->u.enum_const.value = eb->next_value;
        eb->next_value += 1;
    }

    return 1; // επιτυχία
}

/* Τέλος enum → επιστρέφει τον τελικό τύπο */
Type *end_enum(EnumBuilder *eb)
{
    Type *t = eb->enum_type;
    free(eb);
    return t;
}


Type *make_class_type(const char *name, Type *base_type){
    Type *t = make_simple_type(TYPE_CLASS);
    if (!t) return NULL;
    t->tag_name = name ? strdup(name) : NULL;
    t->base_type = base_type;

    /* members table: θα γεμίσει στο semantics */
    t->members = hashtbl_create(211, NULL);
    t->field_order = NULL;
    t->field_count = 0;
    t->field_cap = 0;
    return t;
}

Type *make_union_type(const char *name){
    Type *t = make_simple_type(TYPE_UNION);
    if (!t) return NULL;
    t->tag_name = name ? strdup(name) : NULL;
    t->members = hashtbl_create(211, NULL);
    return t;
}