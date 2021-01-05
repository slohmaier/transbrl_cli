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
    int j;
    
    printf("i=%d textlen=%d text=%s", i, *textlen, text);
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
        //only print '-' if not at space
        if (text[j] != ' ') text[j] = '-';
        text[j+1] = '\n';
        
        i += width + 2;
    }
    return text;
}
