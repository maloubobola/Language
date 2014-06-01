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
#include <string.h>

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
    int constante;
} compiler_element;

/**
 *  Structure which represents all the variables from the source code to compile
 */
typedef compiler_element* compiler_table;

/**
 *  Find an element into the list from the given name. If the tag isCreationAllowed is equal to 1, if the element does not exist, it will be create
 *  @param s Given name
 *  @param isCreationAllowaed When equal to 1, allow to create an element if it does not exist.
 */
compiler_element * find_by_name(char *s, int isCreationAllowed) ;

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

/**
 *  Free an element from the list with the given address
 *  @param address Given address
 */
void compiler_free(int address);

#endif
