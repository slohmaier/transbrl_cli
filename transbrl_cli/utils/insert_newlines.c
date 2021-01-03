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

void movechar(char *text, int textlen, int start, int offset);
char *inctextsize(char *text, int *textsize, int plus);

/* function inserts newline every width characters*/
char *insert_newlines(char *text, int *textlen, int width) {
    int i = width-1;
    int j;
    
    while (i < *textlen) {
        j = i;
        bool isnum = true;
        while (text[j] != ' ' && i-j < width-1) {
            if ((text[j] < '0' || text[j] > '9') && text[j] != '#') isnum = false;
            j--;
        }
        
        //if wholw line has no space break line at end
        if (j-i == width-1) j = i;
        //don't break numbers and leave at least two characters.
        else if (!isnum && i-j > 2) j = i - 1;
        
        //increate text, move characters and set break;
        text = inctextsize(text, textlen, 2);
        if (text == NULL) return NULL;
        movechar(text, *textlen, j, 2);
        text[j] = '-'; text[j+1] = '\n';
        
        i += width + 2;
    }
    return text;
}

/* move all text beginning at start by offset */
void movechar(char *text, int textlen, int start, int offset) {
    int i;
    for (i = textlen + offset; i > start; i--) {
        text[i] = text[i-offset];
    }
}
    
/* increase size of allocated memory by plus*/
char *inctextsize(char *text, int *textsize, int plus) {
    text = (char *)realloc(text, sizeof(char)*(*textsize+plus));
    *textsize = *textsize + plus;
    return text;
}
