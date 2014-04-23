%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "interpreter_table.h"
    
    #define yyparse interpreter_parse
    #define yylex interpreter_lex
    #define yyerror interpreter_error
    #define yyin interpreter_in
    
    extern int currentLine;
    extern FILE *interpreter_in;	//yyin renamed
    
    FILE *file = NULL;
    int evaluateIndex = 0;
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
                    interpreter_command_add(1,$2,$3,$4);
                }

            |   tMUL tNumber tNumber tNumber
                {
                    interpreter_command_add(2,$2,$3,$4);
                }

            |   tSOU tNumber tNumber tNumber
                {
                    interpreter_command_add(3,$2,$3,$4);
                }

            |   tDIV tNumber tNumber tNumber
                {
                    interpreter_command_add(4,$2,$3,$4);
                }

            |   tCOP tNumber tNumber
                {
                    interpreter_command_add(5,$2,$3,-1);
                }

            |   tAFC tNumber tNumber
                {
                    interpreter_command_add(6,$2,$3,-1);
                }

            |   tJMP tNumber
                {
                	interpreter_command_add(7,$2,-1,-1);
                }

            |   tJMF tNumber tNumber
                {
                	interpreter_command_add(8,$2,$3,-1);
                }

            |   tINF tNumber tNumber tNumber
                {   
                    interpreter_command_add(9,$2,$3,$4);
                }

            |   tSUP tNumber tNumber tNumber
                {
                    interpreter_command_add(10,$2,$3,$4);
                }

            |   tEQU tNumber tNumber tNumber
                {
                    interpreter_command_add(11,$2,$3,$4);
                }

            |   tPRI tNumber
                {
                    interpreter_command_add(12,$2,-1,-1);
                }
            ;

%%

void evaluate() {
	int res;
	interpreter_command_element *element = interpreter_get_command(evaluateIndex);
	//printf("%d %d\n",evaluateIndex, element->code);
	switch(element->code) {
		case 1:
			res = interpreter_get_value(element->op2) + interpreter_get_value(element->op3);
            interpreter_set_value(element->op1,res);
            evaluateIndex++;
		break;
		
		case 2:
			res = interpreter_get_value(element->op2) * interpreter_get_value(element->op3);
            interpreter_set_value(element->op1,res);
            evaluateIndex++;
		break;
		
		case 3:
			res = interpreter_get_value(element->op2) - interpreter_get_value(element->op3);
            interpreter_set_value(element->op1,res);
            evaluateIndex++;
		break;
		
		case 4:
			if(interpreter_get_value(element->op3) == 0)
				interpreter_error("Division by 0\n");
			res = interpreter_get_value(element->op2) / interpreter_get_value(element->op3);
            interpreter_set_value(element->op1,res);
            evaluateIndex++;
		break;
        
		case 5:
			interpreter_set_value(element->op1,interpreter_get_value(element->op2));
			evaluateIndex++;
		break;
		
		case 6:
			interpreter_set_value(element->op1,element->op2);
			evaluateIndex++;
		break;
		
		case 7:
			evaluateIndex = element->op1 - 1;
		break;
		
		case 8:
			if(interpreter_get_value(element->op1) == 0) {
				evaluateIndex = element->op2 - 1;
			} else {
				evaluateIndex++;
			}			
		break;
		
		case 9:
            if(interpreter_get_value(element->op2) < interpreter_get_value(element->op3)) {
                res = 1;
            } else {
                res = 0;
            }
            interpreter_set_value(element->op1,res);
            evaluateIndex++;
		break;
		
		case 10:
			if(interpreter_get_value(element->op2) > interpreter_get_value(element->op3)) {
                res = 0;
            } else {
                res = 1;
            }
            interpreter_set_value(element->op1,res);
            evaluateIndex++;
		break;
		
		case 11:
			if(interpreter_get_value(element->op2) == interpreter_get_value(element->op3)) {
                res = 1;
            } else {
                res = 0;
            }
            interpreter_set_value(element->op1,res);
            evaluateIndex++;
		break;
		
		case 12:
			printf("%d\n",interpreter_get_value(element->op1));
			evaluateIndex++;
		break;
	}

}

int main(void) {
    file = fopen("output.txt","r");
    if(file != NULL) {
        interpreter_in = file;
        interpreter_parse();
        //interpreter_command_print();
        
        while(evaluateIndex < interpreter_command_size()) {
        	evaluate();
        }
        //print_interpreter_table();
    }
	return 0;
}

int interpreter_error(char *err)
{
    printf("Error %d: %s\n", currentLine, err);
    return 0;
}
