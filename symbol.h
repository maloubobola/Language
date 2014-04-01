#ifndef Language_symbol_h
#define Language_symbol_h

#define NSYMS 512
#define INT_SIZE 4
#define DEBUG 0

#include <string.h>
#include "list.h"

typedef struct symbol_table
{
	char *name;
	int value;
	int address;
} symbol_table;

symbol_table * symlook(char *s) ;

int printSymTab(void);

void setValue(symbol_table * symtable, int value);

void setAddress(symbol_table * symtable, int address);

int getDeclarationAddress();

void setDeclarationAddress(int address);

int getCurrentAddress();

void setCurrentAddress(int address);

int getCptIf();

void increaseCptIf();

void decreaseCptIf();

void increaseCptLine();

int getCptLine();

#endif
