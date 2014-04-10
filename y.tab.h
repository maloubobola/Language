/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tMain = 258,
     tOpenBracket = 259,
     tCloseBracket = 260,
     tOpenBrace = 261,
     tCloseBrace = 262,
     tConstant = 263,
     tInteger = 264,
     tName = 265,
     tAdd = 266,
     tSubstract = 267,
     tMultiply = 268,
     tDivide = 269,
     tEqual = 270,
     tSpace = 271,
     tTab = 272,
     tComma = 273,
     tSemiColon = 274,
     tPrintf = 275,
     tNumber = 276,
     tCompEqual = 277,
     tLt = 278,
     tGt = 279,
     tLte = 280,
     tGte = 281,
     tDifferent = 282,
     tIf = 283,
     tElse = 284,
     tWhile = 285,
     tNull = 286,
     tRef = 287
   };
#endif
/* Tokens.  */
#define tMain 258
#define tOpenBracket 259
#define tCloseBracket 260
#define tOpenBrace 261
#define tCloseBrace 262
#define tConstant 263
#define tInteger 264
#define tName 265
#define tAdd 266
#define tSubstract 267
#define tMultiply 268
#define tDivide 269
#define tEqual 270
#define tSpace 271
#define tTab 272
#define tComma 273
#define tSemiColon 274
#define tPrintf 275
#define tNumber 276
#define tCompEqual 277
#define tLt 278
#define tGt 279
#define tLte 280
#define tGte 281
#define tDifferent 282
#define tIf 283
#define tElse 284
#define tWhile 285
#define tNull 286
#define tRef 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 55 "lexical.y"
{char* string ; int integer;}
/* Line 1529 of yacc.c.  */
#line 115 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

