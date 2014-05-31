/**
 *  File : compiler_table.c
 *  Project : Language
 *
 *  Created by Thomas Thiebaud on 30/03/2014.
 *  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
 */

#include <stdio.h>
#include "compiler_table.h"

compiler_table comp_table = NULL;

/**
 *  Find an element into the list from the given name. If the tag isCreationAllowed is equal to 1, if the element does not exist, it will be create
 *  @param s Given name
 *  @param isCreationAllowaed When equal to 1, allow to create an element if it does not exist.
 */
compiler_element * find_by_name(char *s, int isCreationAllowed) {
    compiler_element *tmp = comp_table;
    while(tmp != NULL) {
        if(tmp->name && !strcmp(tmp->name, s))
			return tmp;
        tmp = tmp->next;
    }
    
    if(isCreationAllowed == 1) {
        compiler_element* element = malloc(sizeof(compiler_element));
        element->name = strdup(s);
        if(comp_table == NULL)
            comp_table = element;
        else {
            tmp = comp_table;
            
            while(tmp->next != NULL)
                tmp = tmp->next;
            
            tmp->next = element;
        }
        return element;
    }
}

compiler_element * add_compiler_element(char *s) {
    
}

/**
 *  Find an element from the given addresse
 *  @param address Given address
 */
compiler_element * find_by_address(int address) {
    compiler_element *tmp = comp_table;
    
    while(tmp != NULL) {
        if(tmp->address == address)
            return tmp;
        tmp = tmp->next;
    }
  	return NULL;
}

/**
 *  Set the value of an element
 *  @param element Element to change
 *  @param value New value
 */
void setValue(compiler_element * element, int value) {
	element->value = value;
}

/**
 *  Set the address of an element
 *  @param element Element to change
 *  @param address New address
 */
void setAddress(compiler_element * element, int address) {
	element->address = address;
}

/**
 *  Print the compiler table
 */
int printCompilerTable(void) {
	printf("\n\n########################\nTable des symboles\n########################\n");
    compiler_element *tmp = comp_table;
    
    while(tmp != NULL) {
        if(tmp->name != NULL && tmp->value)
			printf("%s\t%d\t%d\n", tmp->name, tmp->value, tmp->address);
		else if(tmp->name != NULL && tmp->address >= 0)
			printf("%s\t-\t%d\n", tmp->name, tmp->address);
		else if(tmp->name != NULL)
			printf("%s\t-\t-\n", tmp->name);
        tmp = tmp->next;
    }
	printf("########################\n");
    return 0;
}

void compiler_free(int address) {
    compiler_element *tmp = comp_table;
    
    while(tmp != NULL) {
        if(tmp->address == address)
            free(tmp);
        tmp = tmp->next;
    }
}