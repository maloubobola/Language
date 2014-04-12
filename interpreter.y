%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "interpreter_table.h"
    
    #define yyparse interpreter_parse
    #define yylex interpreter_lex
    #define yyerror interpreter_error
    #define yyin interpreter_in
    
    extern int currentLine;
    extern FILE *interpreter_in;
    
    FILE *file = NULL;
%}

%name-prefix="interpreter_"

%token tNewLine
%token <integer> tNumber
%token tADD
%token tMUL
%token tSOU
%token tDIV
%token tCOP
%token tAFC
%token tJMP
%token tJMF
%token tINF
%token tSUP
%token tEQU
%token tPRI

%union {int integer;}

%start Start

%%
Start       :   Commands
                {
                    printf("Syntax correct\n");
                }
            ;

Commands    :   Commands Command
                {
                    
                }

            |   Command
                {
                    
                }
            ;

Command     :   tADD tNumber tNumber tNumber
                {
                    int res = interpreter_get_value($3) + interpreter_get_value($4);
                    interpreter_set_value($2,res);
                }

            |   tMUL tNumber tNumber tNumber
                {
                    int res = interpreter_get_value($3) * interpreter_get_value($4);
                    interpreter_set_value($2,res);
                }

            |   tSOU tNumber tNumber tNumber
                {
                    int res = interpreter_get_value($3) - interpreter_get_value($4);
                    interpreter_set_value($2,res);
                }

            |   tDIV tNumber tNumber tNumber
                {
                    int res = interpreter_get_value($3) / interpreter_get_value($4);
                    interpreter_set_value($2,res);
                }

            |   tCOP tNumber tNumber
                {
                    interpreter_set_value($2,interpreter_get_value($3));
                }

            |   tAFC tNumber tNumber
                {
                    interpreter_set_value($2,$3);
                }

            |   tJMP tNumber
                {
                
                }

            |   tJMF tNumber tNumber
                {
                
                }

            |   tINF tNumber tNumber tNumber
                {
                    int res = interpreter_get_value($3) - interpreter_get_value($4);
                    if(res < 0) {
                        res = 1;
                    } else {
                        res = 0;
                    }
                    interpreter_set_value($2,res);
                }

            |   tSUP tNumber tNumber tNumber
                {
                    int res = interpreter_get_value($3) - interpreter_get_value($4);
                    if(res < 0) {
                        res = 0;
                    } else {
                        res = 1;
                    }
                    
                    interpreter_set_value($2,res);
                }

            |   tEQU tNumber tNumber tNumber
                {
                    int res = interpreter_get_value($3) - interpreter_get_value($4);
                    if(res == 0) {
                        res = 1;
                    } else {
                        res = 0;
                    }
                    
                    interpreter_set_value($2,res);
                }

            |   tPRI tNumber
                {
                    printf("%d\n",interpreter_get_value($2));
                }
            ;

%%
int main(void) {
    file = fopen("output.txt","r");
    if(file != NULL) {
        interpreter_in = file;
        interpreter_parse();
    }
	return 0;
}

int interpreter_error(char *err)
{
    printf("Error %d: %s\n", currentLine, err);
    return 0;
}