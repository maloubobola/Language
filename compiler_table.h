/**
 *  File : compiler_table.h
 *  Project : Language
 *
 *  Created by Thomas Thiebaud on 30/03/2014.
 *  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
 */

#ifndef Language_compiler_table_h
#define Language_compiler_table_h

#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE 4
#define DEBUG 0

/**
 *  Structure which represents a variable from source code to compile
 */
typedef struct compiler_element
{
    struct compiler_element *next;
	char *name;
	int value;
	int address;
    int pointer;
} compiler_element;

/**
 *  Structure which represents all the variables from the source code to compile
 */
typedef compiler_element* compiler_table;

/**
 *  Find an element from the given name if it exists, otherwise create an element with the given name
 *  @param s Given name
 */
compiler_element * find_by_name(char *s) ;

/**
 *  Find an element from the given addresse
 *  @param address Given address
 */
compiler_element * find_by_address(int address) ;

/**
 *  Set the value of an element
 *  @param element Element to change
 *  @param value New value
 */
void setValue(compiler_element * element, int value);

/**
 *  Set the address of an element
 *  @param element Element to change
 *  @param address New address
 */
void setAddress(compiler_element * element, int address);

/**
 *  Print the compiler table
 */
int printCompilerTable(void);

#endif
