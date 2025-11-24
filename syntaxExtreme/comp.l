%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "types.h"
    #include "syntax.tab.h"
    #include "string.h"
    #include "settings.h"

    extern int yyerrorno;

    extern void yyerror(const char *s);
    void t_print(int t_id);
    int str_to_int(char *str);
    float str_to_float(char *str);
    char str_to_char(char *str);

%}

%option noyywrap
%option case-insensitive
%option yylineno



%x COMMENT

digit [1-9]
digit0 [0-9]
digits {digit}{digit0}*
hex_digit [0-9a-fA-F]
hex_digits [1-9a-fA-F]{hex_digit}*
octal_digit [0-7]
octal_digits [1-7]{octal_digit}*
binary_digit [0-1]
binary_digits "1"{binary_digit}*

%%

"//"[^\n]*              { ;}
"/*"                    { BEGIN(COMMENT); }

<COMMENT>[^*\n]+        { ; }
<COMMENT>\n             { /*++yylineno;*/ }
<COMMENT>"*"+[^*/]      { ;}
<COMMENT>"*"+"/"        { BEGIN(INITIAL); }
<COMMENT><<EOF>>        { yyerror ("unterminated comment found EOF"); BEGIN(INITIAL); return T_ERROR;}

"TYPEDEF"                                       {t_print(T_TYPEDEF); return T_TYPEDEF;}
"CHAR"                                          {t_print(T_CHAR); return T_CHAR;}
"INT"                                           {t_print(T_INT); return T_INT;}
"FLOAT"                                         {t_print(T_FLOAT); return T_FLOAT;}
"STRING"                                        {t_print(T_STRING); return T_STRING;}
"CONST"                                         {t_print(T_CONST); return T_CONST;}
"CLASS"                                         {t_print(T_CLASS); return T_CLASS;}
"PRIVATE"                                       {t_print(T_PRIVATE); return T_PRIVATE;}
"PROTECTED"                                     {t_print(T_PROTECTED); return T_PROTECTED;}
"PUBLIC"                                        {t_print(T_PUBLIC); return T_PUBLIC;}
"VOID"                                          {t_print(T_VOID); return T_VOID;}
"STATIC"                                        {t_print(T_STATIC); return T_STATIC;}
"UNION"                                         {t_print(T_UNION); return T_UNION;}
"ENUM"                                          {t_print(T_ENUM); return T_ENUM;}
"LIST"                                          {t_print(T_LIST); return T_LIST;}
"CONTINUE"                                      {t_print(T_CONTINUE); return T_CONTINUE;}
"BREAK"                                         {t_print(T_BREAK); return T_BREAK;}
"IF"                                            {t_print(T_IF); return T_IF;}
"ELSE"                                          {t_print(T_ELSE); return T_ELSE;}
"WHILE"                                         {t_print(T_WHILE); return T_WHILE;}
"FOR"                                           {t_print(T_FOR); return T_FOR;}
"RETURN"                                        {t_print(T_RETURN); return T_RETURN;}
"LENGTH"                                        {t_print(T_LENGTH); return T_LENGTH;}
"CIN"                                           {t_print(T_CIN); return T_CIN;}
"COUT"                                          {t_print(T_COUT); return T_COUT;}
"MAIN"                                          {t_print(T_MAIN); return T_MAIN;}
"THIS"                                          {t_print(T_THIS); return T_THIS;}
"SIZEOF"                                        {t_print(T_SIZEOP); return T_SIZEOP;}

"||"                                            {t_print(T_OROP); return T_OROP;}
"&&"                                            {t_print(T_ANDOP); return T_ANDOP;}
"=="|"!="                                       {t_print(T_EQUOP); return T_EQUOP;}
">="|"<="|">"|"<"                               {t_print(T_RELOP); return T_RELOP;}
"+"|"-"                                         {t_print(T_ADDOP); return T_ADDOP;}
"*"|"/"|"%"                                     {t_print(T_MULOP); return T_MULOP;}
"!"                                             {t_print(T_NOTOP); return T_NOTOP;}
"++"|"--"                                       {t_print(T_INCDEC); return T_INCDEC;}
"("                                             {t_print(T_LPAREN); return T_LPAREN;}
")"                                             {t_print(T_RPAREN); return T_RPAREN;}
";"                                             {t_print(T_SEMI); return T_SEMI;}
"."                                             {t_print(T_DOT); return T_DOT;}
","                                             {t_print(T_COMMA); return T_COMMA;}
"="                                             {t_print(T_ASSIGN); return T_ASSIGN;}
":"                                             {t_print(T_COLON); return T_COLON;}
"["                                             {t_print(T_LBRACK); return T_LBRACK;}
"]"                                             {t_print(T_RBRACK); return T_RBRACK;}
"&"                                             {t_print(T_REFER); return T_REFER;}
"{"                                             {t_print(T_LBRACE); return T_LBRACE;}
"}"                                             {t_print(T_RBRACE); return T_RBRACE;}
"::"                                            {t_print(T_METH); return T_METH;}
">>"                                            {t_print(T_INP); return T_INP;}
"<<"                                            {t_print(T_OUT); return T_OUT;}

"C"(("A""D"*)|("D"+))"R"                        {t_print(T_LISTFUNC); return T_LISTFUNC;}

"_"*[a-zA-Z]([a-zA-Z0-9]*|("_"?[a-zA-Z0-9])*)                           {t_print(T_ID); yylval.strval=strdup(yytext); return T_ID;}

"0"|{digits}|"0X"{hex_digits}|"0O"{octal_digits}|"0B"{binary_digits}    {t_print(T_ICONST); yylval.intval=str_to_int(yytext); return T_ICONST;}

("0"|{digits})?"."("0"|"0"*{digits})("E""-"?("0"|{digits}))?            {t_print(T_FCONST); yylval.floatval=str_to_float(yytext); return T_FCONST;}
{digits}("E""-"?("0"|{digits}))                                         {t_print(T_FCONST); yylval.floatval=str_to_float(yytext); return T_FCONST;}
"0X"("0"|{hex_digits})?"."("0"|"0"*{hex_digits})                        {t_print(T_FCONST); yylval.floatval=str_to_float(yytext); return T_FCONST;}
"0O"("0"|{octal_digits})?"."("0"|"0"*{octal_digits})                    {t_print(T_FCONST); yylval.floatval=str_to_float(yytext); return T_FCONST;}
"0B"("0"|{binary_digits})?"."("0"|"0"*{binary_digits})                  {t_print(T_FCONST); yylval.floatval=str_to_float(yytext); return T_FCONST;}

(\'[ -~]\')|(\'\\[nfrtbv]\')                    {t_print(T_CCONST); yylval.charval=str_to_char(yytext); return T_CCONST; }

\"([ !#-~]|\\[\"\\nfrtbv]|\\\r?\n)*\"           {
                                                    yytext[yyleng - 1] = '\0';  
                                                    yylval.strval = strdup(yytext + 1);
                                                    t_print(T_SCONST);
                                                    return T_SCONST;
                                                }

[ \t\n\r]+                                      {;}
.                                               {yyerror ("unrecognised character"); return T_UNKNOWN;}
<<EOF>>                                         {t_print(T_EOF); return T_EOF;}

%%

/*int main(int argc, char *argv[]){
    int token;

    if(argc > 1){
        yyin = fopen(argv[1],"r");
        if(yyin==NULL){
            perror("error opening file");
            return -1;
        }
    }

    do {
        token = yylex();
        //t_print(token);
    }while(token!=0);

    fclose(yyin);

}*/

void t_print(int t_id){
    if(FLEX_DEBUG==0){
        return;
    }
    if(t_id == T_FCONST){
        printf("line: [%d]: token = %f, id = %d\n", yylineno,  str_to_float(yytext), t_id);    
    }
    else if(t_id == T_ICONST){
        printf("line: [%d]: token = %d, id = %d\n", yylineno,  str_to_int(yytext), t_id);
    }
    else{
        printf("line: [%d]: token = %s, id = %d\n", yylineno,  yytext, t_id);
    }
}

char str_to_char(char *str){
    char str_buff;
    if(strlen(str)==2){
        if(strcmp(yytext,"\\n")==0){
            // strcat(str_buff,"\n");
            str_buff='\n';
        }
        else if(strcmp(yytext,"\\f")==0){
            //strcat(str_buff,"\f");
            str_buff='\f';
        }
        else if(strcmp(yytext,"\\r")==0){
            // strcat(str_buff,"\r");
            str_buff='\r';
        }
        else if(strcmp(yytext,"\\t")==0){
            // strcat(str_buff,"\t");
            str_buff='\t';
        }
        else if(strcmp(yytext,"\\v")==0){
            // strcat(str_buff,"\v");
            str_buff='\v';
        }
        else if(strcmp(yytext,"\\b")==0) {
            // strcat(str_buff,"\b");
            str_buff='\b';
        }
    }
    // else strcat(str_buff,yytext);
    else str_buff=yytext[0];
    return str_buff;
}

int str_to_int(char *str){
    if (strncmp(str, "0o", 2) == 0) {
        return strtol(str + 2, NULL, 8);
    } else if (strncmp(str, "0x", 2) == 0) {
        return strtol(str + 2, NULL, 16);
    } else if (strncmp(str, "0b", 2) == 0) {
        return strtol(str + 2, NULL, 2);
    } else {
        return strtol(str, NULL, 10);
    }
}

float str_to_float(char *str) {

    // Προσημο
    int sign = 1;
    if (*str == '+' || *str == '-') {
        if (*str == '-') sign = -1;
        str++;
    }

    // Ανίχνευση βάσης
    int base = 10;
    if (strncmp(str, "0b", 2) == 0 || strncmp(str, "0B", 2) == 0) { base = 2;  str += 2; }
    else if (strncmp(str, "0o", 2) == 0 || strncmp(str, "0O", 2) == 0) { base = 8;  str += 2; }
    else if (strncmp(str, "0x", 2) == 0 || strncmp(str, "0X", 2) == 0) { base = 16; str += 2; }

    // Αν η βάση είναι 10, απλώς χρησιμοποίησε strtof
    if (base == 10) {
        char buf[256];
        buf[0] = (sign < 0) ? '-' : '\0';
        strncat(buf, str, sizeof(buf) - strlen(buf) - 1);
        return strtof(buf, NULL);
    }

    // Αλλιώς, χειροκίνητο parsing
    double val = 0.0;
    while (*str) {
        int d;
        if (isdigit((unsigned char)*str)) d = *str - '0';
        else if (isalpha((unsigned char)*str)) d = (tolower(*str) - 'a') + 10;
        else break;

        if (d < 0 || d >= base) break;
        val = val * base + d;
        str++;
    }

    // Κλασματικό μέρος
    if (*str == '.') {
        str++;
        double frac = 0.0, denom = (double)base;
        while (*str) {
            int d;
            if (isdigit((unsigned char)*str)) d = *str - '0';
            else if (isalpha((unsigned char)*str)) d = (tolower(*str) - 'a') + 10;
            else break;

            if (d < 0 || d >= base) break;
            frac += d / denom;
            denom *= base;
            str++;
        }
        val += frac;
    }

    return (float)(sign * val);
}

