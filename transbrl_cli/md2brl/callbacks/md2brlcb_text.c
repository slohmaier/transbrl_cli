//
//  md2brlcb_text.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_text.h"
#include "md2brl.h"
#include "md2brl_trans.h"
#include <stdlib.h>
#include <stdio.h>

int md2brlcb_text(MD_TEXTTYPE type, const MD_CHAR *text, MD_SIZE size, void *userdata) {
    int ret = 0;
    md2brl *data = (md2brl*)userdata;
    
    //free old text and traslate
    if (data->last_text != NULL) free(data->last_text);
    data->last_text = md2brl_trans(text, size, data->loutables);
    if (data->last_text == NULL) {
        fprintf(stderr, "\nTRANSLATION_ERROR for text: '%s'\n", text);
        ret = -1;
    }
    
    return ret;
}
