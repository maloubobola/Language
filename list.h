/**
 *  File : list.h
 *  Project : Language
 *
 *  Created by Thomas Thiebaud on 30/03/2014.
 *  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
 */

#ifndef Language_list_h
#define Language_list_h

/**
 *  Structure which represents an integer element
 */
typedef struct int_element {
    int value;
    struct int_element *next;
} int_element;

/**
 *  Structure which represents all integer elements
 */
typedef int_element* int_list;

/**
 *  Add an element to the beginning of the list
 *  @param list List to change
 *  @param value Element to add
 *  @return Changed list
 */
int_list addFirst(int_list list, int value);

/**
 *  Add an element to the end of the list
 *  @param list List to change
 *  @param value Element to add
 *  @return Changed list
 */
int_list addLast(int_list list, int value);

/**
 *  Add an element to the penultimate place of the list
 *  @param list List to change
 *  @param value Element to add
 *  @return Changed list
 */
int_list addBeforelast(int_list list, int value);

/**
 *  Print the given list
 *  @param list List to print
 */
void print(int_list list);

/**
 *  Check if the given list is empty or not
 *  @param list Given list
 *  @return 1 if the list is empty, 0 otherwise
 */
int isEmpty(int_list list);

/**
 *  Remove the first element of the given list
 *  @param list Given list
 *  @return Changed list
 */
int_list removeFirst(int_list list);

/**
 *  Remove the last element of the given list
 *  @param list Given list
 *  @return Changed list
 */
int_list removeLast(int_list list);

/**
 *  Find an element from a given list
 *  @param list Given list
 *  @param value Element to find
 *  @return Changed list
 */
int_list find(int_list list, int value);

/**
 *  Get the number of one element from the given list
 *  @param list Given list
 *  @param value Element to find
 *  @return Number of element
 */
int numberOf(int_list list, int value);

/**
 *  Get the element at the given index from the given list
 *  @param list Given list
 *  @param index Given index
 *  @return Changed list
 */
int_list get(int_list list, int index);

/**
 *  Get the value of a given integer list
 *  @param list Given list
 *  @return -1 if the list is NULL, value of the first element otherwise
 */
int value(int_list list);

/**
 *  Get the size of a given list
 *  @param list Given list
 *  @return Size of the list
 */
int size(int_list list);

/**
 *  Remove all occurence of a given element from a given list
 *  @param list Given list
 *  @param value Given element
 *  @return Changed list
 */
int_list removeAll(int_list list, int value);

/**
 *  Clear a given list
 *  @return Changed list
 */
int_list clear(int_list list);

#endif
