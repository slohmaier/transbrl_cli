//
//  md2brlcb_text.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_text.h"
#include "md2brl.h"
#include "md2brl_trans.h"
//TODO: REMOVE!
#include <stdio.h>

int md2brlcb_text(MD_TEXTTYPE type, const MD_CHAR *text, MD_SIZE size, void *userdata) {
    int ret = 0;
    md2brl *data = (md2brl*)userdata;
    printf("%s", md2brl_trans(text, size, data->loutables));
    return ret;
}
