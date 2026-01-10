// astinfo.h
#ifndef ASTINFO_H
#define ASTINFO_H

#include "types.h"
#include "ast.h"

typedef struct ExprInfo {
    Type    *type;
    ASTNode *node;
} ExprInfo;

typedef struct StmtInfo {
    ASTNode *node;
} StmtInfo;

#endif
