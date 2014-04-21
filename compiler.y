%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"
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
%token tIfKey
%token tElseKey
%token tWhileKey
%token tNullKey;
%token tRef;
%token tStringKey;
%token <string> tString;

%start Start

%union {char* string ; int integer; int line;}

%left tAdd tSubstract
%right tMultiply tDivide
%right tEqual

%type <integer> Term
%type <integer> Operation
%type <integer> Comparison

%%
Start       :   tIntegerKey tMain tOpenBracket tCloseBracket tOpenBrace Body tCloseBrace
                {
                    printf("Syntax correct\n");
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
                    symbol_table * symbtable = find_by_name($2);
                    
                    symbtable->address = declarationAddress;
                    symbtable->pointer = 0;
                    declarationAddress += INT_SIZE;
                }

            |   tIntegerKey tName
                {
                    symbol_table * symbtable = find_by_name($2);
                    
                    symbtable->address = declarationAddress;
                    symbtable->pointer = 0;
                    declarationAddress += INT_SIZE;
                }

            |   tIntegerKey tName tEqual tNumber
                {
                    symbol_table * symbtable = find_by_name($2);
                    
                    symbtable->value = $4;
                    symbtable->address = declarationAddress;
                    symbtable->pointer = 0;
                    
                    fprintf(file,"AFC %d %d\n",symbtable->address,symbtable->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                }

            |   tConstantKey tIntegerKey tName tEqual tNumber
                {
                    symbol_table * symbtable = find_by_name($3);
                    
                    symbtable->value = $5;
                    symbtable->address = declarationAddress;
                    symbtable->pointer = 0;
                    
                    fprintf(file,"AFC %d %d\n",symbtable->address,symbtable->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                }

            |   tStringKey tName tEqual tString
                {
                    symbol_table * symbtable = find_by_name($2);
                    int size = strlen($4);
                    int i;
                    int j = 0;
                    
                    symbtable->address = declarationAddress;
                    symbtable->pointer = 0;

                    for(i=0; i < size ; i++) {
                        if($4[i] != '"') {
                            fprintf(file,"AFC %d %d\n",symbtable->address + j,(int)$4[i]);
                            cptLine++;
                            j++;
                        }
                    }
                    fprintf(file,"AFC %d %d\n",symbtable->address + size - 2,-1);
                    
                    declarationAddress += size - 1;
                }

            |   Pointer
            ;

Pointer     :   tIntegerKey tMultiply tName tEqual tNullKey
                {
                    symbol_table * symbtable = find_by_name($3);
                    symbtable->pointer = 1;
                }

            |   tIntegerKey tMultiply tName tEqual tRef tName
                {
                    symbol_table * symbtable = find_by_name($3);
                    
                    symbtable->value = find_by_name($6)->address;
                    symbtable->address = declarationAddress;
                    symbtable->pointer = 1;
                    
                    fprintf(file,"AFC %d %d\n",symbtable->address,symbtable->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                }
            ;


Functions 	:   If

            |   If Functions

            |   While

            |   While Functions

            |   Function tSemiColon

            |   Function tSemiColon Functions

            ;

If 			:   tIfKey tOpenBracket Comparison
                {
                    cptIf++;
                    fprintf(file,"JMF %d [%d]\n",$3, cptIf - 1);
                    cptLine++;
                }
                tCloseBracket tOpenBrace Functions tCloseBrace
                {
                    jumpList = addLast(jumpList,cptLine + 1);
                }
            |
                tIfKey tOpenBracket Comparison
                {
                    cptIf++;
                    fprintf(file,"JMF %d [%d]\n",$3, cptIf - 1);
                    cptLine++;
                }
                tCloseBracket tOpenBrace Functions tCloseBrace
                {
                    jumpList = addLast(jumpList,cptLine + 2);
                }
               	tElseKey
                {
                    cptIf++;
                    fprintf(file,"JMP [%d]\n", cptIf - 1);
                    cptLine++;
                }
                tOpenBrace Functions tCloseBrace
                {
                    jumpList = addLast(jumpList,cptLine + 1);
                }
            ;

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
                    currentAddress -= INT_SIZE;
                }
            ;
			
Comparison  :   Term tCompEqual Term
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"EQU %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    $$ = min;
                    //currentAddress -= INT_SIZE;
                }

            |   Term tLt Term
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"INF %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    //currentAddress -= INT_SIZE;
                }

            |   Term tGt Term
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"SUP %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    //currentAddress -= INT_SIZE;
                }
            ;

Function    :   Operation

            |  	tPrintKey tOpenBracket Operation tCloseBracket
                {
                    fprintf(file,"PRI %d\n",$3);
                    
                    cptLine++;
                    currentAddress -= INT_SIZE;
                }

            |   tName tEqual Operation
                {
                    fprintf(file,"COP %d %d\n",find_by_name($1)->address,$3);
                    
                    cptLine++;
                    currentAddress -= INT_SIZE;
                }

            |   tMultiply tName tEqual Operation
                {
                    fprintf(file,"COP %d %d\n",find_by_name($2)->value,$4);
                    
                    cptLine++;
                    currentAddress -= INT_SIZE;
                }
            ;

Operation   :   Operation tAdd Operation
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"ADD %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    currentAddress -= INT_SIZE;
                }

            |   Operation tSubstract Operation
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"SOU %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    currentAddress -= INT_SIZE;
                }
            |   Operation tMultiply Operation
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"MUL %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    currentAddress -= INT_SIZE;
                }

            |   Operation tDivide Operation
                {
                    int min = $1 < $3 ? $1 : $3;
                    
                    fprintf(file,"DIV %d %d %d\n",min,$1,$3);
                    
                    cptLine++;
                    currentAddress -= INT_SIZE;
                }

            |   Term
            ;

Term 		:   tName
                {
                    fprintf(file,"COP %d %d\n",currentAddress,find_by_name($1)->address);
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
                    symbol_table * symbtable = find_by_name($2);
                    
                    if(symbtable == NULL) {
                        compiler_error("Null pointer exception");
                        exit(1);
                    }
                    
                    if(symbtable->pointer == 0) {
                        compiler_error("Given variable is not a pointer");
                        exit(1);
                    }
                    
                    fprintf(file,"COP %d %d\n",currentAddress,symbtable->value);
                    
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
    printf("Error %d: %s\n", currentLine, err);
    return 0;
}

