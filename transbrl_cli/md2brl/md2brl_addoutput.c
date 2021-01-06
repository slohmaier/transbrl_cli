//
//  md2brladdoutput.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 06.01.21.
//

#include "md2brl_addoutput.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "outputbuffer.h"

char *generate_pageline(const int width, const int page);

md2brl *md2brl_addoutput(md2brl *data, char *text) {
    int newlines = 0, textlen = (int)strlen(text);
    char *buf;
    int newsize, reqpagebreaks = 0, linestonextpage;
    char *i, *i_old;
    
    //count newlines
    for (buf = text; buf != NULL; buf = strchr(buf, '\n')) {
        buf++;
    }
    
    //calculated neeeded newsize
    linestonextpage = (data->height-1) - (data->output_newliens%(data->height-1));
    if (newlines == 0) reqpagebreaks = newlines/data->height-1;
    else if (newlines > linestonextpage) {
        reqpagebreaks = (newlines-linestonextpage)%(data->height-1);
    }
    newsize = textlen + reqpagebreaks*(data->width+1);
    incbuffer(data, newsize);
    
    //add newlines with pagebteaks inbetween
    i = text;
    i_old = text;
    while((i=strchr(i, '\n')) != NULL) {
        i++;
        strncat(data->output, i_old, i-i_old);
        data->output_newliens++;
        i_old = i;
        if (data->output_newliens%(data->height-1) == 0) {
            buf = generate_pageline(data->width, data->output_newliens/(data->height)+1);
            strcat(data->output, buf);
            free(buf);
        }
    }
    data->output_size = (int)strlen(data->output);
    
    return data;
}

char *generate_pageline(const int width, const int page) {
    char *result = (char*)malloc(sizeof(char)*(width+2));
    const int numstrlen = page/10 + 2; //+2 for \n\0
    char *buf = (char*)malloc(sizeof(char)*numstrlen);
    int i;
    
    if (result == NULL) return NULL;
    result[0] = '\0';
    
    //fill with spaces to pagenumstring
    for (i = 0; i < width-numstrlen-1; i++) {
        strcat(result, " ");
    }
    
    snprintf(buf, (size_t)numstrlen+2, "#%d\n", page);
    strcat(result, buf);
    free(buf);
    
    return result;
}
