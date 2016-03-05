%{
#include "compiler.tab.h"
#include "symbol.h"
#include <string.h>
#include <stdlib.h>
#define DEBUG 1

int currentLine = 1;

#define yyparse compiler_parse
#define yylex compiler_lex
%}

%option prefix="compiler"
%option noyywrap
%x BLOCK_COMMENT
%x INLINE_COMMENT

%%
"/*"                {
                        BEGIN(BLOCK_COMMENT);
                    }

<BLOCK_COMMENT>"*/" {
                        BEGIN(INITIAL);
                    }

<BLOCK_COMMENT>.    {}

"//"                {
                        BEGIN(INLINE_COMMENT);
                    }

<INLINE_COMMENT>"\n"    {
                        BEGIN(INITIAL);
                        }

<INLINE_COMMENT>.   {}

main                {
                        #if DEBUG
                            printf("tMain");
                        #endif
                        return tMain;
                    }

\(                  {
                        #if DEBUG
                            printf("tOpenBracket");
                        #endif
                        return tOpenBracket;
                    }

\)                  {
                        #if DEBUG
                            printf("tCloseBracket");
                        #endif
                        return tCloseBracket;
                    }

\{                  {
                        #if DEBUG
                            printf("tOpenBrace");
                        #endif
                        return tOpenBrace;
                    }

\}                  {
                        #if DEBUG
                            printf("tCloseBrace");
                        #endif
                        return tCloseBrace;
                    }

const               {
                        #if DEBUG
                            printf("tConstantKey");
                        #endif
                        return tConstantKey;
                    }

int                 {
                        #if DEBUG
                            printf("tIntegerKey");
                        #endif
                        return tIntegerKey;
                    }

if                  {
                        #if DEBUG
                            printf("tIfKey");
                        #endif
                        return tIfKey;
                    }

else                {
                        #if DEBUG
                            printf("\tElseKey");
                        #endif
                        return tElseKey;
                    }

while               {
                        #if DEBUG
                            printf("\tWhileKey");
                        #endif
                        return tWhileKey;
                    }

printf              {
                        #if DEBUG
                            printf("tPrintKey");
                        #endif
                        return tPrintKey;
                    }

NULL                {
                        #if DEBUG
                            printf("tNullKey");
                        #endif
                        return tNullKey;
                    }

string              {
                        #if DEBUG
                            printf("tStringKey");
                        #endif
                        return tStringKey;
                    }

\+                  {
                        #if DEBUG
                            printf("tAdd");
                        #endif
                        return tAdd;
                    }

\-                  {
                        #if DEBUG
                            printf("tSubstract");
                        #endif
                        return tSubstract;
                    }

\*                  {
                        #if DEBUG
                            printf("tMultiply");
                        #endif
                        return tMultiply;
                    }

\/                  {
                        #if DEBUG
                            printf("tDivide");
                        #endif
                        return tDivide;
                    }

\=                  {
                        #if DEBUG
                            printf("tEqual");
                        #endif
                        return tEqual;
                    }

\=\=                {
                        #if DEBUG
                            printf("tCompEqual");
                        #endif
                        return tCompEqual;
                    }

\<                  {
                        #if DEBUG
                            printf("tLt");
                        #endif
                        return tLt;
                    }

\>                  {
                        #if DEBUG
                            printf("tGt");
                        #endif
                        return tGt;
                    }

\!\=                {
                        #if DEBUG
                            printf("tDifferent");
                        #endif
                        return tDifferent;
                    }

\&                  {
                        #if DEBUG
                            printf("tRef");
                        #endif
                        return tRef;
                    }

[ ]                 {
                        #if DEBUG
                            printf(" ");
                        #endif
                    }

[\t]                {
                        #if DEBUG
                            printf("\t");
                        #endif
                    }

,                   {
                        #if DEBUG
                            printf(",");
                        #endif
                        return tComma;
                    }

;                   {
                        #if DEBUG
                            printf(" ; ");
                        #endif
                        return tSemiColon;
                    }

\n                  {
                        #if DEBUG
                            printf("\n");
                        #endif
                        currentLine++;
                    }

[a-z][a-zA-Z_]*     {
                        #if DEBUG
                            printf("tName");
                        #endif
                        compilerlval.string = strdup(yytext);
                        return tName;
                    }

[0-9]+              {
                        #if DEBUG
                            printf("tNumber");
                        #endif
                        compilerlval.integer = atoi(yytext);
                        return tNumber;
                    }

\"[a-zA-Z0-9]+\"    {
                        #if DEBUG
                            printf("tString");
                        #endif
                        compilerlval.string = strdup(yytext);
                        return tString;
                    }

.                   {};
