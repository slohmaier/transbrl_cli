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

//headers to use with strncat
static char *header_1 = NULL;
static char *header_2 = NULL;

#define HEADER_1 'g'
#define HEADER_2 'c'

int init_headers(md2brl* data);

/* add title text and one line of header-var followed by a newline*/
int md2brlcb_leave_block_header(MD_BLOCKTYPE type, MD_BLOCK_H_DETAIL *detail, md2brl *data) {
    int neededchars = data->last_text_size + 3/*\n's*/;
    int headerchars;
    char *header;
    
    //2 newlines for header_1 1 newline otherwise
    if (detail->level == 1) neededchars += 2;
    else neededchars += 1;
    
    //init_headerstrings
    if (header_1 == NULL || header_2 == NULL) init_headers(data);
    
    //add to size of text the underlying line
    if (data->last_text_size > data->width) headerchars = data->width;
    else headerchars = data->last_text_size;
    neededchars += headerchars;
    
    //decide what header to use
    if (detail->level < 2) header = header_1;
    else header = header_2;
    
    if (incbuffer(data, neededchars) == NULL) return -1;
    
    //2 newlines for header_1 1 newline otherwise
    if (detail->level == 1) strncat(data->output, "\n\n", 2);
    else strncat(data->output, "\n", 1);
    
    //add text, newline, header, 2 newlines
    strncat(data->output, data->last_text, (size_t)data->last_text_size);
    strncat(data->output, "\n", 1);
    strncat(data->output, header, headerchars);
    strncat(data->output, "\n\n", 2);
    
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
