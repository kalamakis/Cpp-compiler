#include "functions.h" 
#include "hashtable.h"
#include<stdlib.h>

SymbolInfo* create_info(SymbolKind kind, TypeKind type){
    SymbolInfo *info = malloc(sizeof(SymbolInfo));
    info->kind = kind;
    info->type = type;
    return info;
}