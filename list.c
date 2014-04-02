//
//  list.c
//  Language
//
//  Created by Thomas on 30/03/2014.
//  Copyright (c) 2014 Thomas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int_list jumpList = NULL;

int_list addFirst(int_list list, int value) {
    int_element* element = malloc(sizeof(int_element));
    element->value = value;
    element->next = list;
    return element;
}

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

void print(int_list list) {
    int_element *tmp = list;
    
    while(tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int isEmpty(int_list list) {
    return (list == NULL) ? 1 : 0;
}

int_list removeFirst(int_list list) {
    if(list != NULL) {
        int_element *secondElement = list->next;
        free(list);
        return secondElement;
    }
    else
        return NULL;
}

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

int_list find(int_list list, int value) {
    int_element *tmp = list;
    while(tmp != NULL) {
        if(tmp->value == value)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

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

int_list get(int_list list, int index) {
    int i;

    for(i=0; i<index && list != NULL; i++)
        list = list->next;
    
    if(list == NULL)
        return NULL;
    else
        return list;
}

int value(int_list list) {
    return ((list == NULL) ? -1 : (list->value));
}

int size(int_list list) {
    int nb = 0;
    int_element *tmp = list;
    
    while(tmp != NULL) {
        nb++;
        tmp = tmp->next;
    }
    return nb;
}

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