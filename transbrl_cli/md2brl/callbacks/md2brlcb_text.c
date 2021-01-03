//
//  md2brlcb_text.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_text.h"

//TODO: REMOVE!
#include <stdio.h>

int md2brlcb_text(MD_TEXTTYPE type, const MD_CHAR *text, MD_SIZE size, void *userdata) {
    int ret = 0;
    printf("%s", text);
    return ret;
}
