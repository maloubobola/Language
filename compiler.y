%{
#include <stdio.h>
#include <stdlib.h>
#include "compiler_table.h"
#include "list.h"
#include "utils.h"

#define yyparse compiler_parse
#define yylex compiler_lex
#define yyerror compiler_error

int_list jumpList;

int declarationAddress = 0;

int currentAddress = -1;
int cptIf = 0;
int cptLine = 0;
extern int currentLine;

FILE *file = NULL;
%}

%name-prefix="compiler"
%token tMain
%token tOpenBracket
%token tCloseBracket
%token tOpenBrace
%token tCloseBrace
%token tConstantKey
%token tIntegerKey
%token <string> tName
%token tAdd
%token tSubstract
%token tMultiply
%token tDivide
%token tEqual
%token tSpace
%token tTab
%token tComma
%token tSemiColon
%token tPrintKey
%token <integer> tNumber
%token tCompEqual
%token tLt
%token tGt
%token tDifferent
%token tElseKey
%token tWhileKey
%token tNullKey
%token tRef
%token tStringKey
%token <string> tString

%token tIfKey
%nonassoc tIfX
%nonassoc tElseKey

%start Start

%union {char* string ; int integer; int line;}

%right tEqual
%left tAdd tSubstract
%left tMultiply tDivide

%type <integer> Term
%type <integer> Operation
%type <integer> Comparison

%%
Start       :   tIntegerKey tMain tOpenBracket tCloseBracket tOpenBrace Body tCloseBrace
                {
                    printf("Compiler : Syntax correct\n");
                }
            ;

Body        :   Vars
            |   Vars
                {
                    if(currentAddress == -1) {
                        currentAddress = declarationAddress;
                    }
                }
                Functions
            ;


Vars        :   Var Vars
            |   Var tSemiColon Vars
            |   Var tSemiColon
            ;

Var         :   tComma tName
                {
                    compiler_element *element = find_by_name($2,1);
                    
                    element->address = declarationAddress;
                    element->pointer = 0;
                    declarationAddress += INT_SIZE;
                }
            |
                tComma tName tEqual tNumber
                {
                    compiler_element *element = find_by_name($2,1);
                    
                    element->value = $4;
                    element->address = declarationAddress;
                    element->pointer = 0;
                    
                    fprintf(file,"AFC %d %d\n",element->address,element->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                }

            |   tIntegerKey tName
                {
                    compiler_element *element = find_by_name($2,1);
                    
                    element->address = declarationAddress;
                    element->pointer = 0;
                    declarationAddress += INT_SIZE;
                }

            |   tIntegerKey tName tEqual tNumber
                {
                    compiler_element *element = find_by_name($2,1);
                    
                    element->value = $4;
                    element->address = declarationAddress;
                    element->pointer = 0;
                    
                    fprintf(file,"AFC %d %d\n",element->address,element->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                }

            |   tConstantKey tIntegerKey tName tEqual tNumber
                {
                    compiler_element *element = find_by_name($3,1);
                    
                    element->value = $5;
                    element->address = declarationAddress;
                    element->pointer = 0;
                    element->constante = 1;
                    
                    fprintf(file,"AFC %d %d\n",element->address,element->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                }

            |   tStringKey tName tEqual tString
                {
                    compiler_element *element = find_by_name($2,1);
                    int size = strlen($4);
                    int i;
                    int j = 0;
                    
                    element->address = declarationAddress;
                    element->pointer = 0;

                    for(i=0; i < size ; i++) {
                        if($4[i] != '"') {
                            fprintf(file,"AFC %d %d\n",element->address + j,(int)$4[i]);
                            cptLine++;
                            j++;
                        }
                    }
                    fprintf(file,"AFC %d %d\n",element->address + size - 2,-1);
                    
                    declarationAddress += size - 1;
                }

            |   Pointer
            ;

Pointer     :   tIntegerKey tMultiply tName tEqual tNullKey
                {
                    compiler_element *element = find_by_name($3,1);
                    element->pointer = 1;
                }

            |   tIntegerKey tMultiply tName tEqual tRef tName
                {
                    compiler_element *element = find_by_name($3,1);
                    
                    element->value = find_by_name($6,0)->address;
                    element->address = declarationAddress;
                    element->pointer = 1;
                    
                    fprintf(file,"AFC %d %d\n",element->address,element->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                }
            ;


Functions 	:   Condition

            |   Condition Functions

            |   While

            |   While Functions

            |   Function tSemiColon

            |   Function tSemiColon Functions

            ;

Condition   :   If tOpenBrace Functions tCloseBrace %prec tIfX
                {
                    jumpList = addLast(jumpList,cptLine + 1);
                }

            |   If tOpenBrace Functions tCloseBrace %prec tIfX
                {
                    jumpList = addLast(jumpList,cptLine + 2);
                }
                Else tOpenBrace Functions tCloseBrace
                {
                    jumpList = addLast(jumpList,cptLine + 1);
                }
            ;

If          :   tIfKey tOpenBracket Comparison
                {
                    cptIf++;
                    fprintf(file,"JMF %d [%d]\n",$3, cptIf - 1);
                    cptLine++;
                }
                tCloseBracket

Else        :   tElseKey
                {
                    cptIf++;
                    fprintf(file,"JMP [%d]\n", cptIf - 1);
                    cptLine++;
                }


While       :  tWhileKey tOpenBracket Comparison
                {
                    cptIf++;
                    fprintf(file,"JMF %d [%d]\n",$3, cptIf - 1);
                    cptLine++;
                    jumpList = addLast(jumpList,cptLine -  1);
                }
                tCloseBracket tOpenBrace Functions tCloseBrace
                {
                    cptIf++;
                    jumpList = addBeforelast(jumpList,cptLine + 2);
                    fprintf(file,"JMP [%d]\n", cptIf - 1);
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                }
            ;
			
Comparison  :   tName tCompEqual Term
                {
                    compiler_element *element = find_by_name($1,0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"EQU %d %d %d\n",currentAddress,element->address,$3);
                    
                    cptLine++;
                    $$ = currentAddress;
                    currentAddress += INT_SIZE;
                }

            |   tName tLt Term
                {
                    compiler_element *element = find_by_name($1,0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"INF %d %d %d\n",currentAddress,element->address,$3);
                    
                    cptLine++;
                    $$ = currentAddress;
                    currentAddress += INT_SIZE;
                }

            |   tName tGt Term
                {
   
                    compiler_element *element = find_by_name($1,0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"SUP %d %d %d\n",currentAddress,element->address,$3);
                    
                    cptLine++;
                    $$ = currentAddress;
                    currentAddress += INT_SIZE;
                }
            ;

Function    :   Operation

            |  	tPrintKey tOpenBracket Operation tCloseBracket
                {
                    fprintf(file,"PRI %d\n",$3);
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                }

            |   tName tEqual Operation
                {
                    compiler_element *element = find_by_name($1,0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    if(element->constante == 1)
                        compiler_error("Impossible de modifier une constante.");
                    
                    fprintf(file,"COP %d %d\n",element->address,$3);
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                }

            |   tMultiply tName tEqual Operation
                {
                    compiler_element *element = find_by_name($2,0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"COP %d %d\n",element->value,$4);
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                }
            ;

Operation   :   Operation tAdd Operation
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"ADD %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                }

            |   Operation tSubstract Operation
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"SOU %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                }
            |   Operation tMultiply Operation
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"MUL %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                }

            |   Operation tDivide Operation
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"DIV %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                }
            |   tOpenBracket Operation tCloseBracket
                {
                    $$ = $2;
                }

            |   Term

            ;

Term 		:   tName
                {
                    compiler_element *element = find_by_name($1,0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"COP %d %d\n",currentAddress,element->address);
                    cptLine++;
                    $$ = currentAddress;
                    currentAddress += INT_SIZE;
                }

            |   tNumber
                {
                    fprintf(file,"AFC %d %d\n",currentAddress,$1);
                    cptLine++;
                    $$ = currentAddress;
                    currentAddress += INT_SIZE;
                }

            |   tMultiply tName
                {
                    compiler_element *element = find_by_name($2,0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    else if(element->pointer == 0)
                        compiler_error("Given variable is not a pointer");
                    
                    fprintf(file,"COP %d %d\n",currentAddress,element->value);
                    
                    cptLine++;
                    $$ = currentAddress;
                    currentAddress += INT_SIZE;
                }
            ;

%%

int secondTime() {
    int i ;
    char c[4];
    
    if(file != NULL) {
        fseek(file, 0, SEEK_END);
        long fsize = ftell(file);
        fseek(file, 0, SEEK_SET);
        
        char *string = malloc(fsize + 1);
        fread(string, fsize, 1, file);
        
        fclose(file);                       //esay way to clear a file
        file = fopen("output.txt","w+");
        
        for(i=0; i<size(jumpList); i++) {
            char cat[10];
            sprintf(c, "%d", value(get(jumpList,i)));
            sprintf(cat,"[%d]",i);
            replaceAllString(string,cat,c);
        }
        
        fprintf(file,"%s\n",string);
    }

    return 0;
}

int main(void) {
    
    file = fopen("output.txt","w+");
    
    if(file != NULL) {
        compiler_parse();
        secondTime();
        fclose(file);
        system("./interpreter");
    }
    else {
        compiler_error("Impossible to execute second time parser");
    }
	return 0;
}

int compiler_error(char *err)
{
    printf("Error (line %d) : %s\n", currentLine, err);
    exit(EXIT_FAILURE);
    return -1;
}

