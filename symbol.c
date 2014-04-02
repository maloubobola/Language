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