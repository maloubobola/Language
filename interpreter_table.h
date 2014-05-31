/**
 *  File : interpreter_table.h
 *  Project : Language
 *
 *  Created by Thomas Thiebaud on 11/04/2014.
 *  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
 */

#ifndef Language_interpreter_table_h
#define Language_interpreter_table_h

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 512

/**
 *  Structure which represent a variable during interpretation
 */
typedef struct interpreter_element
{
    struct interpreter_element *next;
	int address;
    int value;
} interpreter_element;

/**
 *  Structure which represent all variables during interpretation
 */
typedef interpreter_element* interpreter_table;

/**
 *  Structure which represents an assembler command from the compiler output file
 */
typedef struct interpreter_command_element
{
    struct interpreter_command_element *next;
	int code;
    int op1;
    int op2;
    int op3;
} interpreter_command_element;

/**
 *  Structure which represents all the assembler commands from the compiler output file
 */
typedef interpreter_command_element* interpreter_command_table;

/**
 *  Set the value of the element with the given address
 *  @param address Given address
 *  @param value New value
 */
void interpreter_set_value(int address, int value) ;

/**
 *  Get the value of the element with the given address
 *  @param address Given address
 *  @return value
 */
int interpreter_get_value(int address) ;

/**
 *  Print interpreter table
 */
void print_interpreter_table();

/**
 *  Add an element to the beginning with the given address
 *  @param address Given address
 */
void interpreter_add_first(int address) ;

/**
 *  Add an element to the end with the given address
 *  @param address Given address
 */
void interpreter_add_last(int address, int value) ;

/**
 *  Add a command to the command list
 *  @param code Command code
 *  @param op1 First operand of the command
 *  @param op2 Second operand of the command
 *  @param op3 Third operand of the command
 */
void interpreter_command_add(int code, int op1, int op2, int op3);

/**
 *  Print the command list
 */
void interpreter_command_print();

/**
 *  Get the command list size
 *  @return Command list size
 */
int interpreter_command_size();

/**
 *  Get the command at the given index
 *  @param index Given index
 *  @return Command
 */
interpreter_command_element * interpreter_get_command(int index);

#endif
