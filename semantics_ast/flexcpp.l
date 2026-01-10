%{
    #include <stdio.h>
    #include <stdlib.h>
%}


%option noyywrap
%option case-insensitive

("_"*[a-zA_Z]([a-zA-Z0-9]*("_"[a-zA-Z0-9]+)?)*)



%%

"TYPEDEF"                                       {return 1;}
"CHAR"                                          {return 2;}
"INT"                                           {return 3;}
"FLOAT"                                         {return 4;}
"STRING"                                        {return 5;}
"CONST"                                         {return 6;}
"CLASS"                                         {return 7;}
"PRIVATE"                                       {return 8;}
"PROTECTED"                                     {return 9;}
"PUBLIC"                                        {return 10;}
"VOID"                                          {return 11;}
"STATIC"                                        {return 12;}
"UNION"                                         {return 13;}
"ENUM"                                          {return 14;}
"LIST"                                          {return 15;}
"CONTINUE"                                      {return 16;}
"BREAK"                                         {return 17;}
"IF"                                            {return 18;}
"ELSE"                                          {return 19;}
"WHILE"                                         {return 20;}
"FOR"                                           {return 21;}
"RETURN"                                        {return 22;}
"LENGHT"                                        {return 23;}
"CIN"                                           {return 24;}
"COUT"                                          {return 25;}
"MAIN"                                          {return 26;}
"THIS"                                          {return 27;}
"_"*[a-zA-Z]([a-zA-Z0-9]*|("_"?[a-zA-Z0-9])*)   {ID}
.                                               {return -1}
<<EOF>>                                         {retrun 0;}

%%

int main(int argc, char *argv[]){

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
    }while(token!=0);

    fclose(argv[1]);

}