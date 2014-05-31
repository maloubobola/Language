/**
 *  File : list.c
 *  Project : Language
 *
 *  Created by Thomas Thiebaud on 30/03/2014.
 *  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int_list jumpList = NULL;

/**
 *  Add an element to the beginning of the list
 *  @param list List to change
 *  @param value Element to add
 *  @return Changed list
 */
int_list addFirst(int_list list, int value) {
    int_element* element = malloc(sizeof(int_element));
    element->value = value;
    element->next = list;
    return element;
}

/**
 *  Add an element to the end of the list
 *  @param list List to change
 *  @param value Element to add
 *  @return Changed list
 */
int_list addLast(int_list list, int value) {
    int_element* element = malloc(sizeof(int_element));
    
    element->value = value;
    element->next = NULL;
    
    if(list == NULL)
        return element;
    else {
        int_element *tmp = list;
        
        while(tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = element;
        return list;
    }
}

/**
 *  Add an element to the penultimate place of the list
 *  @param list List to change
 *  @param value Element to add
 *  @return Changed list
 */
int_list addBeforelast(int_list list, int value) {
    int_element* element = malloc(sizeof(int_element));
    
    element->value = value;
    element->next = NULL;
    
    if(list == NULL)
        return element;
    else if(size(list) == 1){
        return addFirst(list,value);
    }
    else {
        int_element *tmp = list;
        
        while(tmp->next->next != NULL) {
            tmp = tmp->next;
        }
        
        element->next = tmp->next;
        tmp->next = element;
        
        return list;
    }
}

/**
 *  Print the given list
 *  @param list List to print
 */
void print(int_list list) {
    int_element *tmp = list;
    
    while(tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

/**
 *  Check if the given list is empty or not
 *  @param list Given list
 *  @return 1 if the list is empty, 0 otherwise
 */
int isEmpty(int_list list) {
    return (list == NULL) ? 1 : 0;
}

/**
 *  Remove the first element of the given list
 *  @param list Given list
 *  @return Changed list
 */
int_list removeFirst(int_list list) {
    if(list != NULL) {
        int_element *secondElement = list->next;
        free(list);
        return secondElement;
    }
    else
        return NULL;
}

/**
 *  Remove the last element of the given list
 *  @param list Given list
 *  @return Changed list
 */
int_list removeLast(int_list list) {
    if(list == NULL)
        return NULL;
    
    if(list->next == NULL) {
        free(list);
        return NULL;
    }
    
    int_element *tmp = list;
    int_element *ptmp = list;

    while(tmp->next != NULL) {
        ptmp = tmp;
        tmp = tmp->next;
    }

    ptmp->next = NULL;
    free(tmp);
    return list;
}

/**
 *  Find an element from a given list
 *  @param list Given list
 *  @param value Element to find
 *  @return Changed list
 */
int_list find(int_list list, int value) {
    int_element *tmp = list;
    while(tmp != NULL) {
        if(tmp->value == value)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

/**
 *  Get the number of one element from the given list
 *  @param list Given list
 *  @param value Element to find
 *  @return Number of element
 */
int numberOf(int_list list, int value) {
    int i = 0;
    
    if(list == NULL)
        return 0;
    
    while((list = find(list, value)) != NULL) {
        list = list->next;
        i++;
    }
    return i;
}

/**
 *  Get the element at the given index from the given list
 *  @param list Given list
 *  @param index Given index
 *  @return Changed list
 */
int_list get(int_list list, int index) {
    int i;

    for(i=0; i<index && list != NULL; i++)
        list = list->next;
    
    if(list == NULL)
        return NULL;
    else
        return list;
}

/**
 *  Get the value of a given integer list
 *  @param list Given list
 *  @return -1 if the list is NULL, value of the first element otherwise
 */
int value(int_list list) {
    return ((list == NULL) ? -1 : (list->value));
}

/**
 *  Get the size of a given list
 *  @param list Given list
 *  @return Size of the list
 */
int size(int_list list) {
    int nb = 0;
    int_element *tmp = list;
    
    while(tmp != NULL) {
        nb++;
        tmp = tmp->next;
    }
    return nb;
}

/**
 *  Remove all occurence of a given element from a given list
 *  @param list Given list
 *  @param value Given element
 *  @return Changed list
 */
int_list removeAll(int_list list, int value) {
    if(list == NULL)
        return NULL;
    
    if(list->value == value) {
        int_element* tmp = list->next;
        free(list);
        tmp = removeAll(tmp, value);
        return tmp;
    } else {
        list->next = removeAll(list->next, value);
        return list;
    }
}

/**
 *  Clear a given list
 *  @return Changed list
 */
int_list clear(int_list list) {
    if(list == NULL)
        return NULL;
    else {
        int_element *tmp;
        tmp = list->next;
        free(list);
        return clear(tmp);
    }
}