//
//  list.h
//  Language
//
//  Created by Thomas on 30/03/2014.
//  Copyright (c) 2014 Thomas. All rights reserved.
//

#ifndef Language_list_h
#define Language_list_h

typedef struct int_element {
    int value;
    struct int_element *next;
} int_element;

typedef int_element* int_list;

int_list addFirst(int_list list, int value);

int_list addLast(int_list list, int value);

int_list addBeforelast(int_list list, int value);

void print(int_list list);

int isEmpty(int_list list);

int_list removeFirst(int_list list);

int_list removeLast(int_list list);

int_list find(int_list list, int value);

int numberOf(int_list list, int value);

int_list get(int_list list, int index);

int value(int_list list);

int size(int_list list);

int_list removeAll(int_list list, int value);

int_list clear(int_list list);

#endif
