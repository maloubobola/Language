%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "list.h"

extern int_list jumpList;
FILE *file = NULL;

%}

%token tMain
%token tOpenBracket
%token tCloseBracket
%token tOpenBrace
%token tCloseBrace
%token tConstant
%token tInteger
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
%token tPrintf
%token <integer> tNumber
%token tCompEqual
%token tLt
%token tGt
%token tLte
%token tGte
%token tDifferent
%token tIf
%token tElse

%start Start

%union {char* string ; int integer;}

%left tAdd tSubstract
%right tMultiply tDivide
%right tEqual

%type <integer> Term
%type <integer> Operation
%type <integer> Comparison

%%
Start       : tInteger tMain tOpenBracket tCloseBracket tOpenBrace Body tCloseBrace {printf("\n\n#########\nSyntax ok\n#########\n");} ;

Body        : Vars ;

Body        : Vars
			{
				if(getCurrentAddress() == -1) {
					setCurrentAddress(getDeclarationAddress());
				}
			}  
			Functions ; 

Vars        : Var tComma Vars ;

Vars        : Var tSemiColon Vars ;

Vars        : Var tSemiColon ;

Var         : tInteger tName
			{
				symbol_table * symbtable = symlook($2);
				setAddress(symbtable,getDeclarationAddress());
				setDeclarationAddress(getDeclarationAddress() + INT_SIZE);
			};

Var         : tInteger tName tEqual tNumber
			{
				symbol_table * symbtable = symlook($2);
				setValue(symbtable,$4);
				setAddress(symbtable,getDeclarationAddress());
				printf("AFC %d %d\n",symbtable->address,symbtable->value);
				increaseCptLine();
				setDeclarationAddress(getDeclarationAddress() + INT_SIZE);
			};

Var         : tConstant tInteger tName tEqual tNumber
			{
				symbol_table * symbtable = symlook($3);
				setValue(symbtable,$5);
				setAddress(symbtable,getDeclarationAddress());
				printf("AFC %d %d\n",symbtable->address,symbtable->value);
				increaseCptLine();
				setDeclarationAddress(getDeclarationAddress() + INT_SIZE);
			};

Functions 	: If ;

Functions 	: If Functions ;

If 			: tIf tOpenBracket Comparison   
			{
				increaseCptIf();
				printf("JMF %d [%d]\n",$3, getCptIf());
				increaseCptLine();
			} 
			tCloseBracket tOpenBrace Functions tCloseBrace 
			{
                jumpList = addLast(jumpList,getCptLine() + 2);
                print(jumpList);
			} 
			tElse tOpenBrace  
			{
				increaseCptIf();
				printf("JMP [%d]\n", getCptIf());	
				increaseCptLine();	
			} 
			Functions tCloseBrace {
                jumpList = addLast(jumpList,getCptLine() + 1);
                print(jumpList);
			};

If			: tIf tOpenBracket Comparison   
			{
				increaseCptIf();
				printf("JMF %d [%d]\n",$3, getCptIf());
				increaseCptLine();
			} 
			tCloseBracket tOpenBrace Functions tCloseBrace 
			{
                jumpList = addLast(jumpList,getCptLine() + 1);
                print(jumpList);
			};
			
Comparison  : Term tCompEqual Term 
			{
				int min = $1 < $3 ? $1 : $3;
				printf("EQU %d %d %d\n",min,$1,$3);	
				increaseCptLine();
				$$ = min;
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};
			 
Comparison  : Term tLt Term
			{
				int min = $1 < $3 ? $1 : $3;
				printf("INF %d %d %d\n",min,$1,$3);	
				increaseCptLine();
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};
			
Comparison  : Term tLte Term 
			{
				int min = $1 < $3 ? $1 : $3;
				printf("INF %d %d %d\n",min,$1,$3);	
				increaseCptLine();
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};
			
Comparison  : Term tGt Term
			{
				int min = $1 < $3 ? $1 : $3;
				printf("SUP %d %d %d\n",min,$1,$3);	
				increaseCptLine();
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};
			
Comparison  : Term tGte Term
			{
				int min = $1 < $3 ? $1 : $3;
				printf("SUP %d %d %d\n",min,$1,$3);	
				increaseCptLine();
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};

Functions   : Function tSemiColon ;

Functions   : Function tSemiColon Functions
			{
				
			};		

Function    : Operation;

Function    : tPrintf tOpenBracket tName tCloseBracket
			{
				symbol_table * symbtable = symlook($3);
				printf("PRI %d\n",symbtable->address);
				increaseCptLine();
			};
			
Function    : tName tEqual Operation
			{
				printf("COP %d %d\n",symlook($1)->address,$3);
				increaseCptLine();
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};

Operation   : Operation tAdd Operation
			{
				int min = $1 < $3 ? $1 : $3;
				printf("ADD %d %d %d\n",min,$1,$3);
				increaseCptLine();
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};

Operation   : Operation tSubstract Operation
			{
				int min = $1 < $3 ? $1 : $3;
				printf("SOU %d %d %d\n",min,$1,$3);
				increaseCptLine();
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};

Operation   : Operation tMultiply Operation
			{
				int min = $1 < $3 ? $1 : $3;
				printf("MUL %d %d %d\n",min,$1,$3);
				increaseCptLine();
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};

Operation   : Operation tDivide Operation
			{
				int min = $1 < $3 ? $1 : $3;
				printf("DIV %d %d %d\n",min,$1,$3);
				increaseCptLine();
				setCurrentAddress(getCurrentAddress() - INT_SIZE);
			};

Operation	: Term ;

Term 		: tName
			{
				printf("COP %d %d\n",getCurrentAddress(),symlook($1)->address);
				increaseCptLine();
				$$ = getCurrentAddress();
				setCurrentAddress(getCurrentAddress() + INT_SIZE);
			};

Term		: tNumber
			{
				printf("AFC %d %d\n",getCurrentAddress(),$1);
				increaseCptLine();
				$$ = getCurrentAddress();
				setCurrentAddress(getCurrentAddress() + INT_SIZE);
			};

%%

int secondTime() {
    return 0;
}

int main(void) {
    file = fopen("output.txt","w");
    
    if(file != NULL) {
        yyparse();
        
        fclose(file);
    }
    else {

    }
	return 0;
}

int yyerror(char *err) {
	printf("\n\n############\n%s\n############\n", err);
    return 0;
}

