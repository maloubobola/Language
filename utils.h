/**
 *  File : utils.h
 *  Project : Language
 *
 *  Created by Thomas Thiebaud on 06/04/2014.
 *  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
 */

#ifndef Language_utils_h
#define Language_utils_h

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 *  Replace all occurence of a string from a buffer by another one
 *  @param buf Full text
 *  @param orig String to replace
 *  @param replace New string
 */
void replaceAllString(char *buf, const char *orig, const char *replace);

#endif
