#ifndef HASHTBL_H_INCLUDE_GUARD
#define HASHTBL_H_INCLUDE_GUARD

#include<stdlib.h>

typedef size_t hash_size;

struct hashnode_s {
    char *key;
    void *data;
    int scope;
    struct hashnode_s *next;
};

typedef struct hashtbl {
    hash_size size;
    struct hashnode_s **nodes;
    hash_size (*hashfunc)(const char *);
} HASHTBL;


HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc)(const char *));
void hashtbl_destroy(HASHTBL *hashtbl);
int  hashtbl_insert(HASHTBL *hashtbl, const char *key, void *data, int scope);
int  hashtbl_remove(HASHTBL *hashtbl, const char *key,int scope);

/* Βρες το data για ένα key, ψάχνοντας μέχρι και το δοσμένο scope
   (προτιμάει το πιο εσωτερικό scope ≤ scope). */
void *hashtbl_lookup(HASHTBL *hashtbl, const char *key, int scope);

/* Βγάλε ΟΛΑ τα στοιχεία ενός scope (π.χ. όταν κάνεις leave_scope).
   Αν free_data != NULL, την καλεί για να κάνει free το node->data. */
void hashtbl_remove_scope(HASHTBL *hashtbl, int scope, void (*free_data)(void*));

#endif
