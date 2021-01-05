//
//  md2brlcb_text.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_text.h"
#include "md2brl.h"
#include "md2brl_trans.h"
#include "insert_newlines.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int md2brlcb_text(MD_TEXTTYPE type, const MD_CHAR *text, MD_SIZE size, void *userdata) {
    int ret = 0;
    md2brl *data = (md2brl*)userdata;
    int textlen = size;
    
    //free old text and traslate
    data->last_text = md2brl_trans(text, &textlen, data->loutables);
    if (data->last_text == NULL) {
        fprintf(stderr, "\nTRANSLATION_ERROR for text: '%s'\n", text);
        ret = -1;
    }
    data->last_text_size = textlen;
    
    return ret;
}
