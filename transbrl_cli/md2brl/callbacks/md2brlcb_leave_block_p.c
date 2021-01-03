//
//  md2brlcb_leave_block_p.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_leave_block_p.h"
#include <string.h>
#include "outputbuffer.h"

#define LINES_WITHOUT_INDENT 2

int md2brlcb_leave_block_p(MD_BLOCKTYPE type, MD_BLOCK_H_DETAIL *detail, md2brl *data) {
    int neededchars = data->last_text_size + 1; //1 newline
    
    //add two spaces if enough LINES_WITHOUT_INDENT
    if (data->last_text_size > data->width*LINES_WITHOUT_INDENT) neededchars += 2;
    
    //increase output buffer
    if (incbuffer(data, neededchars) == NULL) return -1;
    
    //add two spaces if enough LINES_WITHOUT_INDENT
    if (data->last_text_size > data->width*LINES_WITHOUT_INDENT) {
        strncat(data->output, "  ", 2);
    }
    strncat(data->output, data->last_text, data->last_text_size);
    strncat(data->output, "\n", 1);
    
    return 0;
}
