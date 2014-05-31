/**
 *  File : utils.c
 *  Project : Language
 *
 *  Created by Thomas Thiebaud on 06/04/2014.
 *  Copyright (c) 2014 thomas  thiebaud. All rights reserved.
 */

#include <stdio.h>
#include "utils.h"

/**
 *  Replace all occurence of a string from a buffer by another one
 *  @param buf Full text
 *  @param orig String to replace
 *  @param replace New string
 */
void replaceAllString(char *buf, const char *orig, const char *replace) {
    int olen, rlen;
    char *s, *d;
    char *tmpbuf;
    
    if (!buf || !*buf || !orig || !*orig || !replace)
        return;
    
    tmpbuf = malloc(strlen(buf) + 1);
    if (tmpbuf == NULL)
        return;
    
    
    olen = strlen(orig);
    rlen = strlen(replace);
    
    s = buf;
    d = tmpbuf;
    
    while (*s) {
        if (strncmp(s, orig, olen) == 0) {
            strcpy(d, replace);
            s += olen;
            d += rlen;
        }
        else
            *d++ = *s++;
    }
    
    *d = '\0';
    
    strcpy(buf, tmpbuf);
    free(tmpbuf);
}