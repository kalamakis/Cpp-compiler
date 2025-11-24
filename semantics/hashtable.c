/* The authors of this work have released all rights to it and placed it
in the public domain under the Creative Commons CC0 1.0 waiver
(http://creativecommons.org/publicdomain/zero/1.0/).

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Retrieved from: http://en.literateprograms.org/Hash_table_(C)?oldid=19638
*/

/*
    This Library has been modified slightly to allow some extra functions such as
    debug information and printing the hashtable as table.
*/

#include "hashtable.h"
#include "settings.h"

#include<string.h>
#include<stdio.h>

static const char *type_to_string(TypeKind t) {
    switch (t) {
        case TYPE_INT:    return "int";
        case TYPE_FLOAT:  return "float";
        case TYPE_CHAR:   return "char";
        case TYPE_STRING: return "string";
        case TYPE_VOID:   return "void";
        case TYPE_ERROR:  return "<error>";
        default:          return "<unknown>";
    }
}

static const char *symkind_to_string(SymbolKind k) {
    switch (k) {
        case SYM_VAR:   return "var";
        // case SYM_CONST: return "const";
        case SYM_FUNC:  return "func";
        case SYM_PARAM: return "param";
        case SYM_TYPEDEFF:  return "typedeff";
		case SYM_CLASS:  return "class";
		case SYM_ENUM:  return "enum";
		//case SYM_UNION:  return "union";
        case SYM_FIELD: return "field";
        default:        return "sym";
    }
}

static char *mystrdup(const char *s)
{
	char *b;
	if(!(b=malloc(strlen(s)+1))) return NULL;
	strcpy(b, s);
	return b;
}

static hash_size def_hashfunc(const char *key)
{
	hash_size hash=0;
	
	while(*key) hash+=(unsigned char)*key++;

	return hash;
}

HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc)(const char *))
{
	HASHTBL *hashtbl;

	if(!(hashtbl=malloc(sizeof(HASHTBL)))) return NULL;

	if(!(hashtbl->nodes=calloc(size, sizeof(struct hashnode_s*)))) {
		free(hashtbl);
		return NULL;
	}

	hashtbl->size=size;

	if(hashfunc) hashtbl->hashfunc=hashfunc;
	else hashtbl->hashfunc=def_hashfunc;

	return hashtbl;
}

void hashtbl_destroy(HASHTBL *hashtbl)
{
	hash_size n;
	struct hashnode_s *node, *oldnode;
	
	for(n=0; n<hashtbl->size; ++n) {
		node=hashtbl->nodes[n];
		while(node) {
			free(node->key);
			oldnode=node;
			node=node->next;
			free(oldnode);
		}
	}
	free(hashtbl->nodes);
	free(hashtbl);
}

//Return 0 success, return -1 error, return -2 double declaration in the same scope
int hashtbl_insert(HASHTBL *hashtbl, const char *key, SymbolInfo *data ,int scope)
{
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;

    if(HASHTBL_DEBUG && HASHTBL_SHOW_INSERT){
        printf("HASHTBL_INSERT(): KEY = %s, HASH = %lu, SCOPE = %d, KIND = %s, TYPE = %s\n",
               key, hash, scope,
               data ? symkind_to_string(data->kind) : "<null>",
               data ? type_to_string(data->type)   : "<null>");
    }

	node=hashtbl->nodes[hash];
	while(node) {
		if(!strcmp(node->key, key) && (node->scope == scope)) {
			node->data=data;
			//Found double decleration return -2 for error, and replace data
			return -2;
		}
		node=node->next;
	}

	if(!(node=malloc(sizeof(struct hashnode_s)))) return -1;
	if(!(node->key=mystrdup(key))) {
		free(node);
		return -1;
	}
	node->data=data;
	node->scope = scope;
	node->next=hashtbl->nodes[hash];
	hashtbl->nodes[hash]=node;

	return 0;
}

int hashtbl_remove(HASHTBL *hashtbl, const char *key, int scope)
{
    struct hashnode_s *node, *prevnode = NULL;
    hash_size hash = hashtbl->hashfunc(key) % hashtbl->size;

    node = hashtbl->nodes[hash];
    while (node) {
        if (!strcmp(node->key, key) && (node->scope == scope)) {
            free(node->key);
            if (node->data) free(node->data);  /* ελευθέρωσε το SymbolInfo */
            if (prevnode) prevnode->next = node->next;
            else hashtbl->nodes[hash] = node->next;
            free(node);
            return 0;
        }
        prevnode = node;
        node = node->next;
    }

    return -1;
}

void *hashtbl_get(HASHTBL *hashtbl, int scope)
{
    int rem = -1;
    hash_size n;
    struct hashnode_s *node, *oldnode;
    int found = 0;

    for (n = 0; n < hashtbl->size; ++n) {
        node = hashtbl->nodes[n];
        while (node) {
            if (node->scope == scope) {
                if (HASHTBL_DEBUG && HASHTBL_SHOW_GET) {
                    if (HASHTBL_SHOW_GET_AS_TABLE) {
                        if (!found) {
                            printf("-------------- Scope %-2d ---------------\n", scope);
                            printf("Name------------------ Kind------ Type-----\n");
                            found++;
                        }
                        SymbolInfo *info = node->data;
                        printf("%-22s %-9s %-8s\n",
                               node->key,
                               info ? symkind_to_string(info->kind) : "<null>",
                               info ? type_to_string(info->type)     : "<null>");
                    } else {
                        SymbolInfo *info = node->data;
                        printf("HASHTBL_GET(): SCOPE = %d, KEY = %s, KIND = %s, TYPE = %s\n",
                               node->scope, node->key,
                               info ? symkind_to_string(info->kind) : "<null>",
                               info ? type_to_string(info->type)     : "<null>");
                    }
                }
                oldnode = node;
                node = node->next;
                rem = hashtbl_remove(hashtbl, oldnode->key, scope);
            } else {
                node = node->next;
            }
        }
    }

    if (HASHTBL_DEBUG && HASHTBL_SHOW_GET && HASHTBL_SHOW_GET_AS_TABLE && found) {
        printf("---------- End of Scope %-2d ------------\n\n", scope);
    }

    if (rem == -1 && HASHTBL_DEBUG && HASHTBL_SHOW_GET && !HASHTBL_SHOW_GET_AS_TABLE) {
        printf("HASHTBL_GET(): There are no elements in the hash table with this scope! SCOPE = %d\n", scope);
    }

    return NULL;
}


SymbolInfo *hashtbl_lookup(HASHTBL *hashtbl, const char *key, int scope)
{
    hash_size hash = hashtbl->hashfunc(key) % hashtbl->size;
    struct hashnode_s *node;

    /* Αναζήτηση από inner προς outer scopes */
    for (int s = scope; s >= 0; --s) {
        node = hashtbl->nodes[hash];
        while (node) {
            if (!strcmp(node->key, key) && node->scope == s) {
                return node->data;
            }
            node = node->next;
        }
    }

    return NULL;
}