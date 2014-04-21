//
//  interpreter_table.h
//  Language
//
//  Created by thomas  thiebaud on 11/04/2014.
//  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
//

#ifndef Language_interpreter_table_h
#define Language_interpreter_table_h

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 512

typedef struct interpreter_element
{
    struct interpreter_element *next;
	int address;
    int value;
} interpreter_element;

typedef interpreter_element* interpreter_table;

typedef struct interpreter_command_element
{
    struct interpreter_command_element *next;
	int code;
    int op1;
    int op2;
    int op3;
} interpreter_command_element;

typedef interpreter_command_element* interpreter_command_table;

void interpreter_set_value(int address, int value) ;

int interpreter_get_value(int address) ;

void print_interpreter_table();

void interpreter_add_first(int address) ;

void interpreter_add_last(int address, int value) ;

void interpreter_command_add(int code, int op1, int op2, int op3);

void interpreter_command_print();

int interpreter_command_size();

interpreter_command_element * interpreter_get_command(int index);

#endif
