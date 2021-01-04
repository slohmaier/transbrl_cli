//
//  insert_pagebreaks.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "insert_pagebreaks.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "outputbuffer.h"

char *generate_pagenumber(md2brl *data, int num);

md2brl *insert_pagebreaks(md2brl *data) {
    int newlines = 0;
    int i = 0;
    int neededchars;
    char *buf;
    
    for (i = 0; i < data->output_size; i++) {
        if (data->output[i] == '\n') {
            newlines++;
            if(newlines%(data->height-1) == 0) {
                neededchars = data->width + 1;
                if (incbuffer(data, neededchars) == NULL) return NULL;
                if ((buf = generate_pagenumber(data, newlines/(data->width-1))) == NULL) return NULL;
                movechar(data->output, data->output_size, i, data->width+1);
                strncat(&data->output[i], buf, data->width+1);
                free(buf);
                i += data->width + 1;
            }
        }
    }
    
    return data;
}

char *generate_pagenumber(md2brl *data, int num) {
    int size = snprintf(NULL, 0, "#%d", num);
    char *result = (char*)malloc(sizeof(char)*data->width+1);
    int i;
    
    for (i = 0; i < data->width+1; i++) result[i] = ' ';
    
    if (size < 0 || result == NULL) return NULL;
    snprintf(&result[data->width-size], size, "#%d", num);
    strncat(result, "\n", 1);
    return result;
}
