%{
    #include "interpreter.tab.h"
    #include <stdlib.h>
    
    #define yyparse interpreter_parse
    #define yylex interpreter_lex
    #define yyerror interpreter_error
    #define yyin interpreter_in
    
    int currentLine = 1;
%}

%option prefix="interpreter_"
%option noyywrap

%%
ADD                 {
                        return tADD;
                    }

MUL                 {
                        return tMUL;
                    }

SOU                 {
                        return tSOU;
                    }

DIV                 {
                        return tDIV;
                    }

COP                 {
                        return tCOP;
                    }

AFC                 {
                        return tAFC;
                    }

JMP                 {
                        return tJMP;
                    }

JMF                 {
                        return tJMF;
                    }

INF                 {
                        return tINF;
                    }

SUP                 {
                        return tSUP;
                    }

EQU                 {
                        return tEQU;
                    }

PRI                 {
                        return tPRI;
                    }

\n                  {
                        #if DEBUG
                            printf("\n");
                        #endif
                        currentLine++;
                    }

[0-9]+              {
                        interpreter_lval.integer = atoi(yytext);
                        return tNumber;
                    }

.                   {}
