//
//  md2brlcb_leave_block.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brlcb_leave_block.h"
#include "md4c_enu2string.h"
#include <stdio.h>

int md2brlcb_leave_block(MD_BLOCKTYPE type, void* detail, void* userdata) {
    int ret = 0;
    
    switch(type) {
        case MD_BLOCK_H:
            break;
        case MD_BLOCK_P:
            break;
            
        //ignore some blocks
        case MD_BLOCK_DOC:
            break;
        
        //error on handling unimplemented blocktypes
        default:
            fprintf(stderr, "MD_PARSER-ERROR: Cannot handle MD_BLOCKSTYPE %s!", mdblocktype2string(type) );
            return -1;
            break;
    }
    
    return ret;
}
