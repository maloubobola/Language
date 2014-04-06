%{
#include "y.tab.h"
#include "symbol.h"
#include <string.h>
#include <stdlib.h>
%}

%x BLOCK_COMMENT
%x INLINE_COMMENT

%%
main			{
					#if DEBUG
						printf("tMain");
					#endif
					return tMain;
				}

\(				{
					#if DEBUG
						printf("tOpenBracket");
					#endif
					return tOpenBracket;
				}

\)				{
					#if DEBUG
						printf("tCloseBracket");
					#endif
					return tCloseBracket;
				}

\{				{
					#if DEBUG
						printf("tOpenBrace");
					#endif
					return tOpenBrace;
				}

\}				{
					#if DEBUG
						printf("tCloseBrace");
					#endif
					return tCloseBrace;
				}

const			{
					#if DEBUG
						printf("tConstant");
					#endif
					return tConstant;
				}

int				{
					#if DEBUG
						printf("tInteger");
					#endif
					return tInteger;
				}

if 				{
					#if DEBUG
						printf("tIf");
					#endif
					return tIf;
				}

else			{
					#if DEBUG
						printf("\tElse");
					#endif
					return tElse;
				}

while           {
                    #if DEBUG
                        printf("\tWhile");
                    #endif
                    return tWhile;
                }

printf			{
					#if DEBUG
						printf("tPrintf");
					#endif
					return tPrintf;
				}

"/*"            {
                    BEGIN(BLOCK_COMMENT);
                }

<BLOCK_COMMENT>"*/"   {
                    BEGIN(INITIAL);
                }

<BLOCK_COMMENT>.      {}

"//"            {
                    BEGIN(INLINE_COMMENT);
                }

<INLINE_COMMENT>"\n"   {
                    BEGIN(INITIAL);
                }

<INLINE_COMMENT>.      {}

[a-z][a-zA-Z_]*	{
					#if DEBUG
						printf("tName");
					#endif
					yylval.string = strdup(yytext);
					return tName;
				}

\+				{
					#if DEBUG
						printf("tAdd");
					#endif
					return tAdd;
				}

\-				{
					#if DEBUG
						printf("tSubstract");
					#endif
					return tSubstract;
				}

\*				{
					#if DEBUG
						printf("tMultiply");
					#endif
					return tMultiply;
				}

\/				{
					#if DEBUG
						printf("tDivide");
					#endif
					return tDivide;
				}

\=				{
					#if DEBUG
						printf("tEqual");
					#endif
					return tEqual;
				}

[ ]				{
					#if DEBUG
						printf(" ");
					#endif
				}

[\t]			{
					#if DEBUG
						printf("\t");
					#endif
				}

,				{
					#if DEBUG
						printf(", ");
					#endif
					return tComma;
				}

;				{
					#if DEBUG
						printf(" ; ");
					#endif
					return tSemiColon;
				}

[0-9]*			{
					#if DEBUG
						printf("tNumber");
					#endif
					yylval.integer = atoi(yytext);
					return tNumber;
				}

\n				{
					#if DEBUG
						printf("\n");
					#endif
				}
				
\=\=			{
					#if DEBUG
						printf("tCompEqual");
					#endif
					return tCompEqual;
				}

\<				{
					#if DEBUG
						printf("tLt");
					#endif
					return tLt;
				}
				
\> 				{
					#if DEBUG
						printf("tGt");
					#endif
					return tGt;
				}
				
\<\=			{
					#if DEBUG
						printf("tLte");
					#endif
					return tLte;
				}

\>\=			{
					#if DEBUG
						printf("tGte");
					#endif
					return tGte;
				}
				
\!\=			{
					#if DEBUG
						printf("tDifferent");
					#endif
					return tDifferent;
				}		

.				{}
