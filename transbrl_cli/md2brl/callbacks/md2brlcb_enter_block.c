//
//  md2brlcb_enter_block.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_enter_block.h"
#include "md2brl.h"
#include "../../utils/md4c_enu2string.h"
#include <stdio.h>

int md2brlcb_enter_block(MD_BLOCKTYPE type, void *detail, void *userdata) {
    int ret = 0;
    md2brl *data = (md2brl*)userdata;
    
    if (data->debug) printf("DEBUG: ENTER-BLOCK %s\n", mdblocktype2string(type));
    
    return ret;
}
