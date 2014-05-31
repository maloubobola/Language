/**
 *  File : interpreter_table.c
 *  Project : Language
 *
 *  Created by Thomas Thiebaud on 11/04/2014.
 *  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
 */

#include "interpreter_table.h"

interpreter_table int_table = NULL;
interpreter_command_table command_table = NULL;

/**
 *  Set the value of the element with the given address
 *  @param address Given address
 *  @param value New value
 */
void interpreter_set_value(int address, int value) {
    interpreter_element *tmp = int_table;
    
    while(tmp != NULL) {
        if(tmp->address == address) {
            tmp->value = value;
            return;
        }
        else {
            tmp = tmp->next;
        }
    }
    interpreter_add_last(address,value);
}

/**
 *  Get the value of the element with the given address
 *  @param address Given address
 *  @return value
 */
int interpreter_get_value(int address) {
    interpreter_element *tmp = int_table;
    
    while(tmp != NULL) {
        if(tmp->address == address) {
            return tmp->value;
        }
        else
            tmp = tmp->next;
    }
    interpreter_add_last(address, 0);
    return 0;
}

/**
 *  Print interpreter table
 */
void print_interpreter_table() {
    interpreter_element *tmp = int_table;
    printf("Interpreter table\n");
    while(tmp != NULL) {
        printf("%d\t%d\n",tmp->address, tmp->value);
        tmp = tmp->next;
    }
}

/**
 *  Add an element to the beginning with the given address
 *  @param address Given address
 */
void interpreter_add_first(int address) {
    interpreter_element* element = malloc(sizeof(interpreter_element));
    element->address = address;
    element->next = int_table;
    int_table = element;
}

/**
 *  Add an element to the end with the given address
 *  @param address Given address
 */
void interpreter_add_last(int address, int value) {
    interpreter_element* element = malloc(sizeof(interpreter_element));
    element->address = address;
    element->value = value;
    element->next = NULL;
    
    if(int_table == NULL)
        int_table = element;
    else {void interpreter_command_print();
        interpreter_element *tmp = int_table;
        
        while(tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = element;
    }
}

/**
 *  Add a command to the command list
 *  @param code Command code
 *  @param op1 First operand of the command
 *  @param op2 Second operand of the command
 *  @param op3 Third operand of the command
 */
void interpreter_command_add(int code, int op1, int op2, int op3) {
	interpreter_command_element* element = malloc(sizeof(interpreter_command_element));
    element->code = code;
    element->op1 = op1;
    element->op2 = op2;
    element->op3 = op3;
    element->next = NULL;
    
    if(command_table == NULL)
        command_table = element;
    else {
        interpreter_command_element *tmp = command_table;
        
        while(tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = element;
    }
}

/**
 *  Print the command list
 */
void interpreter_command_print() {
	interpreter_command_element *tmp = command_table;
    printf("Interpreter command table\n");
    while(tmp != NULL) {
        printf("%d\t%d\t%d\t%d\n",tmp->code, tmp->op1, tmp->op2, tmp->op3);
        tmp = tmp->next;
    }
}

/**
 *  Get the command list size
 *  @return Command list size
 */
int interpreter_command_size() {
	int i = 0; 
	interpreter_command_element *tmp = command_table;
    while(tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    return i;
}

/**
 *  Get the command at the given index
 *  @param index Given index
 *  @return Command
 */
interpreter_command_element * interpreter_get_command(int index) {
	int i;
	
	interpreter_command_element *tmp = command_table;
    for(i=0; i<index && command_table != NULL; i++)
        tmp = tmp->next;
    
    if(tmp == NULL)
        return NULL;
    else
        return tmp;
}
