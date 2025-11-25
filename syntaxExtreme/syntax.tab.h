/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_EOF = 0,
    T_TYPEDEF = 258,
    T_CHAR = 259,
    T_INT = 260,
    T_FLOAT = 261,
    T_STRING = 262,
    T_CONST = 263,
    T_CLASS = 264,
    T_PRIVATE = 265,
    T_PROTECTED = 266,
    T_PUBLIC = 267,
    T_VOID = 268,
    T_STATIC = 269,
    T_UNION = 270,
    T_ENUM = 271,
    T_LIST = 272,
    T_CONTINUE = 273,
    T_BREAK = 274,
    T_IF = 275,
    T_ELSE = 276,
    T_WHILE = 277,
    T_FOR = 278,
    T_RETURN = 279,
    T_LENGTH = 280,
    T_CIN = 281,
    T_COUT = 282,
    T_MAIN = 283,
    T_THIS = 284,
    T_ID = 285,
    T_NUM = 286,
    T_ICONST = 287,
    T_UNKNOWN = 288,
    T_FCONST = 289,
    T_SCONST = 290,
    T_CCONST = 291,
    T_OROP = 292,
    T_ANDOP = 293,
    T_EQUOP = 294,
    T_RELOP = 295,
    T_ADDOP = 296,
    T_MULOP = 297,
    T_NOTOP = 298,
    T_INCDEC = 299,
    T_SIZEOP = 300,
    T_LISTFUNC = 301,
    T_LPAREN = 302,
    T_RPAREN = 303,
    T_SEMI = 304,
    T_DOT = 305,
    T_COMMA = 306,
    T_ASSIGN = 307,
    T_COLON = 308,
    T_LBRACK = 309,
    T_RBRACK = 310,
    T_REFER = 311,
    T_LBRACE = 312,
    T_RBRACE = 313,
    T_METH = 314,
    T_INP = 315,
    T_OUT = 316,
    T_ERROR = 317,
    PREFIX = 318,
    POSTFIX = 319,
    LOWER_THAN_ELSE = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "syntax.y" /* yacc.c:1909  */

    int   intval;
    float floatval;
    char *strval;
    char  charval;
    Type *type;

#line 129 "syntax.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
