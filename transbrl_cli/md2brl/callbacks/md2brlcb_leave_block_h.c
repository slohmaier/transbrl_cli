//
//  md2brlcb_leave_block_h.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_leave_block_h.h"

#include <string.h>
#include "outputbuffer.h"
#include <stdlib.h>
#include "md2brl_addoutput.h"

//headers to use with strncat
static char *header_1 = NULL;
static char *header_2 = NULL;

#define HEADER_1 'g'
#define HEADER_2 'c'

int init_headers(md2brl* data);

/* add title text and one line of header-var followed by a newline*/
int md2brlcb_leave_block_header(MD_BLOCKTYPE type, MD_BLOCK_H_DETAIL *detail, md2brl *data) {
    //init_headerstrings
    if (header_1 == NULL || header_2 == NULL) init_headers(data);
    
    int newlines = 0, i;
    char *buf;
    int linestopagebreak, neededlines;
    int textlen = (int)strlen(data->last_text);
    int newsize, headerchars;
    
    for (buf = data->last_text; strchr(buf, '\n') != NULL; buf++) {
        newlines++;
    }
    neededlines = newlines + 2;
    //count newlines befor header
    if (detail->level < 2) neededlines += 1;
    else neededlines += 2;
    
    linestopagebreak = data->height - 1 - data->output_newliens%(data->height);
    //skip to nextpage if not enough for title + 2 lines
    if (linestopagebreak < neededlines) {
        newsize = textlen + data->width+1 + neededlines;
    }
    else {
        newsize = textlen + neededlines - newlines;
    }
    buf = (char *)malloc(sizeof(char)*newsize);
    buf[0] = '\0';
    if (linestopagebreak < neededlines) {
        for(i = 0; i < linestopagebreak; i++) strcat(buf, "\n");
    }
    else if (data->output_newliens%data->height > 0) {
        if (detail->level > 2) strcat(buf, "\n");
        else strcat(buf, "\n\n");
    }
    strcat(buf, data->last_text);
    strcat(buf, "\n");
    
    //decide what header to use
    headerchars = textlen;
    if (headerchars > data->width) headerchars = data->width;
    if (detail->level < 2) strncat(buf, header_1, headerchars);
    else strncat(buf, header_2, headerchars);
    strcat(buf, "\n");
    
    if (md2brl_addoutput(data, buf) == NULL) return -1;
    
    /* these lead to coruupe error why?
     FIXME
    free(data->last_text);
    free(buf);*/
    
    return 0;
}

/* init both headers with one line of the fillcar*/
int init_headers(md2brl* data) {
    int i;
    
    header_1 = (char*)malloc(sizeof(char)*(data->width+1));
    header_2 = (char*)malloc(sizeof(char)*(data->width+1));
    if (header_1 == NULL || header_2 == NULL) return -1;
    
    for (i = 0; i < data->width+1; i++) {
        header_1[i] = HEADER_1;
        header_2[i] = HEADER_2;
    }
    header_1[i] = '\0';
    header_2[i] = '\0';
    return 0;
}
