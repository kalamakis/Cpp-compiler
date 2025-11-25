/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    T_EOF = 0,                     /* "eof"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_TYPEDEF = 258,               /* "typedef"  */
    T_CHAR = 259,                  /* "char"  */
    T_INT = 260,                   /* "int"  */
    T_FLOAT = 261,                 /* "float"  */
    T_STRING = 262,                /* "string"  */
    T_CONST = 263,                 /* "const"  */
    T_CLASS = 264,                 /* "class"  */
    T_PRIVATE = 265,               /* "private"  */
    T_PROTECTED = 266,             /* "protected"  */
    T_PUBLIC = 267,                /* "public"  */
    T_VOID = 268,                  /* "void"  */
    T_STATIC = 269,                /* "static"  */
    T_UNION = 270,                 /* "union"  */
    T_ENUM = 271,                  /* "enum"  */
    T_LIST = 272,                  /* "list"  */
    T_CONTINUE = 273,              /* "continue"  */
    T_BREAK = 274,                 /* "break"  */
    T_IF = 275,                    /* "if"  */
    T_ELSE = 276,                  /* "else"  */
    T_WHILE = 277,                 /* "while"  */
    T_FOR = 278,                   /* "for"  */
    T_RETURN = 279,                /* "return"  */
    T_LENGTH = 280,                /* "length"  */
    T_CIN = 281,                   /* "cin"  */
    T_COUT = 282,                  /* "cout"  */
    T_MAIN = 283,                  /* "main"  */
    T_THIS = 284,                  /* "this"  */
    T_ID = 285,                    /* "id"  */
    T_NUM = 286,                   /* "num"  */
    T_ICONST = 287,                /* "iconst"  */
    T_UNKNOWN = 288,               /* "unknown"  */
    T_FCONST = 289,                /* "fconst"  */
    T_SCONST = 290,                /* "sconst"  */
    T_CCONST = 291,                /* "cconst"  */
    T_OROP = 292,                  /* "orop"  */
    T_ANDOP = 293,                 /* "andop"  */
    T_EQUOP = 294,                 /* "equop"  */
    T_RELOP = 295,                 /* "relop"  */
    T_ADDOP = 296,                 /* "addop"  */
    T_MULOP = 297,                 /* "mulop"  */
    T_NOTOP = 298,                 /* "notop"  */
    T_INCDEC = 299,                /* "incdec"  */
    T_SIZEOP = 300,                /* "sizeop"  */
    T_LISTFUNC = 301,              /* "listfunc"  */
    T_LPAREN = 302,                /* "lparen"  */
    T_RPAREN = 303,                /* "rparen"  */
    T_SEMI = 304,                  /* "semi"  */
    T_DOT = 305,                   /* "dot"  */
    T_COMMA = 306,                 /* "comma"  */
    T_ASSIGN = 307,                /* "assign"  */
    T_COLON = 308,                 /* "colon"  */
    T_LBRACK = 309,                /* "lbrack"  */
    T_RBRACK = 310,                /* "rbrack"  */
    T_REFER = 311,                 /* "refer"  */
    T_LBRACE = 312,                /* "lbrace"  */
    T_RBRACE = 313,                /* "rbrace"  */
    T_METH = 314,                  /* "meth"  */
    T_INP = 315,                   /* "inp"  */
    T_OUT = 316,                   /* "out"  */
    T_ERROR = 317,                 /* "error"  */
    PREFIX = 318,                  /* PREFIX  */
    POSTFIX = 319,                 /* POSTFIX  */
    LOWER_THAN_ELSE = 320          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "syntax.y"

    int   intval;
    float floatval;
    char *strval;
    char  charval;
    Type *type;

#line 137 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
