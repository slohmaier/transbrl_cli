//
//  md2brlcb_leave_block_p.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_leave_block_p.h"
#include <string.h>
#include "outputbuffer.h"
#include <stdlib.h>
#include "insert_newlines.h"

#define LINES_WITHOUT_INDENT 2

int md2brlcb_leave_block_p(MD_BLOCKTYPE type, MD_BLOCK_H_DETAIL *detail, md2brl *data) {
    int neededchars = data->last_text_size + 1; //1 newline
    char *buf;
    
    //add two spaces if enough LINES_WITHOUT_INDENT
    if (data->last_text_size > data->width*LINES_WITHOUT_INDENT) neededchars += 2;
    
    //increase output buffer
    if (incbuffer(data, neededchars) == NULL) return -1;
    
    //add two spaces if enough LINES_WITHOUT_INDENT
    if (data->last_text_size > data->width*LINES_WITHOUT_INDENT) {
        data->last_text = (char*)realloc(data->last_text, sizeof(char)*(data->last_text_size+2));
        if (data->last_text == NULL) return -1;
        data->last_text_size += 1;
        movechar(data->last_text, data->last_text_size, 0, 2);
        data->last_text[0] = ' ';
        data->last_text[1] = ' ';
    }
    
    buf = data->last_text;
    data->last_text = insert_newlines(data->last_text, &data->last_text_size, data->width);
    if (data->last_text == NULL) return -1;
    free(buf);
    
    strncat(data->output, data->last_text, data->last_text_size);
    strncat(data->output, "\n", 1);
    
    return 0;
}
