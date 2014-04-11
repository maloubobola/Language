//
//  interpreter_table.c
//  Language
//
//  Created by thomas  thiebaud on 11/04/2014.
//  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
//

#include "interpreter_table.h"

interpreter_table table = NULL;


void interpreter_set_value(int address, int value) {
    interpreter_element *tmp = table;
    
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

int interpreter_get_value(int address) {
    interpreter_element *tmp = table;
    
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

void print_interpreter_table() {
    interpreter_element *tmp = table;
    printf("Interpreter table\n");
    while(tmp != NULL) {
        printf("%d\t%d\n",tmp->address, tmp->value);
        tmp = tmp->next;
    }
}

void interpreter_add_first(int address) {
    interpreter_element* element = malloc(sizeof(interpreter_element));
    element->address = address;
    element->next = table;
    table = element;
}

void interpreter_add_last(int address, int value) {
    interpreter_element* element = malloc(sizeof(interpreter_element));
    
    element->address = address;
    element->value = value;
    element->next = NULL;
    
    if(table == NULL)
        table = element;
    else {
        interpreter_element *tmp = table;
        
        while(tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = element;
    }
}