//
//  md2brlcb_debug_log.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_debug_log.h"

#include <stdio.h>
#include "../md2brl.h"

void md2brlcb_debug_log(const char *msg, void *userdata) {
    md2brl *data = (md2brl*)userdata;
    if (data->debug) {
        printf("MD4> %s\n", msg);
    }
}
