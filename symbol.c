//
//  symbol.c
//  Language
//
//  Created by Thomas on 30/03/2014.
//  Copyright (c) 2014 Thomas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"

symbol_table symtable[NSYMS];
int declarationAddress = 0;
int currentAddress = -1;
int cptIf = 0;
int cptLine = 0;

symbol_table * symlook(char *s) {
  	symbol_table *sp;
  	for(sp = symtable; sp < &symtable[NSYMS]; sp++) {
		if(sp->name && !strcmp(sp->name, s))
			return sp;
		if(!sp->name) {
			sp->name = strdup(s);
	  		return sp;
		}
  	}
  	yyerror("Too many symbols");
  	exit(1);
}

void setValue(symbol_table * symtable, int value) {
	symtable->value = value;
}

void setAddress(symbol_table * symtable, int address) {
	symtable->address = address;
}

inline int getDeclarationAddress() {
	return declarationAddress;
}

inline void setDeclarationAddress(int address) {
	declarationAddress = address;
}

inline int getCurrentAddress() {
	return currentAddress;
}

inline void setCurrentAddress(int address) {
	currentAddress = address;
}

inline int getCptIf() {
	return cptIf;
}

inline void increaseCptIf() {
	cptIf ++;
}

inline void decreaseCptIf() {
	cptIf --;
}

inline void increaseCptLine() {
	cptLine ++;
}

inline int getCptLine() {
	return cptLine;
}

int printSymTab(void) {
	printf("\n\n########################\nTable des symboles\n########################\n");
	symbol_table *sp;
	for(sp = symtable; sp < &symtable[NSYMS]; sp++) {
		if(sp->name != NULL && sp->value)
			printf("%s\t%d\t%d\n", sp->name, sp->value, sp->address);
		else if(sp->name != NULL && sp->address)
			printf("%s\t-\t%d\n", sp->name, sp->address);
		else if(sp->name != NULL)
			printf("%s\t-\t-\n", sp->name);
	}
	printf("########################\n");
    return 0;
}