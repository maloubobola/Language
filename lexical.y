%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "list.h"
#include "string.h"

int_list jumpList;

int declarationAddress = 0;

int currentAddress = -1;
int cptIf = 0;
int cptLine = 0;

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
%token tWhile

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
				if(currentAddress == -1)
                    currentAddress = declarationAddress;
			}  
			Functions ; 

Vars        : Var tComma Vars ;

Vars        : Var tSemiColon Vars ;

Vars        : Var tSemiColon ;

Var         : tInteger tName
			{
				symbol_table * symbtable = symlook($2);
				setAddress(symbtable,declarationAddress);
				declarationAddress += INT_SIZE;
			};

Var         : tInteger tName tEqual tNumber
			{
				symbol_table * symbtable = symlook($2);
				setValue(symbtable,$4);
				setAddress(symbtable,declarationAddress);
				fprintf(file,"AFC %d %d\n",symbtable->address,symbtable->value);
                cptLine++;
				declarationAddress += INT_SIZE;
			};

Var         : tConstant tInteger tName tEqual tNumber
			{
				symbol_table * symbtable = symlook($3);
				setValue(symbtable,$5);
				setAddress(symbtable,declarationAddress);
				fprintf(file,"AFC %d %d\n",symbtable->address,symbtable->value);
				cptLine++;
				declarationAddress += INT_SIZE;
			};

Functions 	: If ;

Functions 	: If Functions ;

Functions 	: While ;

Functions 	: While Functions ;

If 			: tIf tOpenBracket Comparison   
			{
				cptIf++;
				fprintf(file,"JMF %d [%d]\n",$3, cptIf - 1);
				cptLine++;
			} 
			tCloseBracket tOpenBrace Functions tCloseBrace 
			{
                jumpList = addLast(jumpList,cptLine + 2);
			}
			tElse tOpenBrace  
			{
				cptIf++;
				fprintf(file,"JMP [%d]\n", cptIf - 1);
				cptLine++;
			} 
			Functions tCloseBrace {
                jumpList = addLast(jumpList,cptLine + 1);
			};

If			: tIf tOpenBracket Comparison   
			{
				cptIf++;
				fprintf(file,"JMF %d [%d]\n",$3, cptIf);
				cptLine++;
			} 
			tCloseBracket tOpenBrace Functions tCloseBrace 
			{
                jumpList = addLast(jumpList,cptLine + 1);
			};

While       : tWhile tOpenBracket Comparison
            {
                cptIf++;
				fprintf(file,"JMF %d [%d]\n",$3, cptIf - 1);
				cptLine++;
                jumpList = addLast(jumpList,cptLine);
            }
            tCloseBracket tOpenBrace Functions tCloseBrace
            {
                cptIf++;
                jumpList = addBeforelast(jumpList,cptLine + 2);
                fprintf(file,"JMP [%d]\n", cptIf - 1);
				cptLine++;
            };
			
Comparison  : Term tCompEqual Term
			{
				int min = $1 < $3 ? $1 : $3;
				fprintf(file,"EQU %d %d %d\n",min,$1,$3);
				cptLine++;
				$$ = min;
                currentAddress -= INT_SIZE;
			};
			 
Comparison  : Term tLt Term
			{
				int min = $1 < $3 ? $1 : $3;
				fprintf(file,"INF %d %d %d\n",min,$1,$3);
				cptLine++;
				currentAddress -= INT_SIZE;
			};
			
Comparison  : Term tLte Term 
			{
				int min = $1 < $3 ? $1 : $3;
				fprintf(file,"INF %d %d %d\n",min,$1,$3);
				cptLine++;
				currentAddress -= INT_SIZE;
			};
			
Comparison  : Term tGt Term
			{
				int min = $1 < $3 ? $1 : $3;
				fprintf(file,"SUP %d %d %d\n",min,$1,$3);
				cptLine++;
				currentAddress -= INT_SIZE;
			};
			
Comparison  : Term tGte Term
			{
				int min = $1 < $3 ? $1 : $3;
				fprintf(file,"SUP %d %d %d\n",min,$1,$3);
				cptLine++;
				currentAddress -= INT_SIZE;
			};

Functions   : Function tSemiColon ;

Functions   : Function tSemiColon Functions
			{
				
			};		

Function    : Operation;

Function    : tPrintf tOpenBracket tName tCloseBracket
			{
				symbol_table * symbtable = symlook($3);
				fprintf(file,"PRI %d\n",symbtable->address);
				cptLine++;
			};
			
Function    : tName tEqual Operation
			{
				fprintf(file,"COP %d %d\n",symlook($1)->address,$3);
				cptLine++;
				currentAddress -= INT_SIZE;
			};

Operation   : Operation tAdd Operation
			{
				int min = $1 < $3 ? $1 : $3;
				fprintf(file,"ADD %d %d %d\n",min,$1,$3);
				cptLine++;
				currentAddress -= INT_SIZE;
			};

Operation   : Operation tSubstract Operation
			{
				int min = $1 < $3 ? $1 : $3;
				fprintf(file,"SOU %d %d %d\n",min,$1,$3);
				cptLine++;
				currentAddress -= INT_SIZE;
			};

Operation   : Operation tMultiply Operation
			{
				int min = $1 < $3 ? $1 : $3;
				fprintf(file,"MUL %d %d %d\n",min,$1,$3);
				cptLine++;
				currentAddress -= INT_SIZE;
			};

Operation   : Operation tDivide Operation
			{
				int min = $1 < $3 ? $1 : $3;
				fprintf(file,"DIV %d %d %d\n",min,$1,$3);
				cptLine++;
				currentAddress -= INT_SIZE;
			};

Operation	: Term ;

Term 		: tName
			{
				fprintf(file,"COP %d %d\n",currentAddress,symlook($1)->address);
				cptLine++;
				$$ = currentAddress;
				currentAddress += INT_SIZE;
			};

Term		: tNumber
			{
				fprintf(file,"AFC %d %d\n",currentAddress,$1);
				cptLine++;
				$$ = currentAddress;
				currentAddress += INT_SIZE;
			};

%%

void replaceAllString(char *buf, const char *orig, const char *replace) {
    int olen, rlen;
    char *s, *d;
    char *tmpbuf;
    
    if (!buf || !*buf || !orig || !*orig || !replace)
        return;
    
    tmpbuf = malloc(strlen(buf) + 1);
    if (tmpbuf == NULL)
        return;
    
    
    olen = strlen(orig);
    rlen = strlen(replace);
    
    s = buf;
    d = tmpbuf;
    
    while (*s) {
        if (strncmp(s, orig, olen) == 0) {
            strcpy(d, replace);
            s += olen;
            d += rlen;
        }
        else
        *d++ = *s++;
    }
    
    *d = '\0';
    
    strcpy(buf, tmpbuf);
    free(tmpbuf);
}

int secondTime() {
    int i ;
    char c[4];
    
    if(file != NULL) {
        fseek(file, 0, SEEK_END);
        long fsize = ftell(file);
        fseek(file, 0, SEEK_SET);
        
        char *string = malloc(fsize + 1);
        fread(string, fsize, 1, file);
        
        fclose(file);                       //esay way to clear file
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
        yyparse();
        secondTime();
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

