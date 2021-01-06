//
//  insert_newlines.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "insert_newlines.h"
#include "bool.h"
#include <stdlib.h>
#include <string.h>
#include "outputbuffer.h"
#include <stdio.h>

/* function inserts newline every width characters*/
char *insert_newlines(char *text, int *textlen, int width) {
    int i = width-1;
    int j, i_old = 0;
    int newsize = (*textlen/width)+1 + *textlen + 1;
    char *newtext;
    int cursize = 0;
    
    newtext = (char*)malloc(sizeof(char)*newsize);
    if (newtext == NULL) return NULL;
    newtext[0] = '\0';
    
    while (i < *textlen) {
        j = i;
        bool isnum = false;
        while (text[j] != ' ' && i-j < width-1) {
            j--;
        }
        if (text[j+1] == '#' && j+2 < *textlen && text[j+2] >= 'a' && text[j+2] <= 'j') isnum = true;
        
        //if wholw line has no space break line at end
        if (j-i >= width-1) j = i;
        //don't break numbers and leave at least two characters.
        else if (!isnum && i-j > 2) j = i - 1;
        
        //copy string to this state
        strncat(newtext, &text[i_old], j-i_old);
        cursize += j-i_old;
        if (text[j] != ' ') strcat(newtext, "-");
        else j++; //skip space
        strcat(newtext, "\n");
        
        i_old = j;
        i = j + width - 1;
    }
    
    //free old text and return new one
    free(text);
    return newtext;
}
