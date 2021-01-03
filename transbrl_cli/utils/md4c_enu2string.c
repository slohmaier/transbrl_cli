//
//  md4c_enu2string.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md4c_enu2string.h"
#include <stdlib.h>

char *mdblocktype2string(MD_BLOCKTYPE type) {
    switch (type) {
        case MD_BLOCK_DOC: return "MD_BLOCK_DOC";
        case MD_BLOCK_QUOTE: return "MD_BLOCK_QUOTE";
        case MD_BLOCK_UL: return "MD_BLOCK_UL";
        case MD_BLOCK_OL: return "MD_BLOCK_OL";
        case MD_BLOCK_LI: return "MD_BLOCK_LI";
        case MD_BLOCK_HR: return "MD_BLOCK_HR";
        case MD_BLOCK_H: return "MD_BLOCK_H";
        case MD_BLOCK_CODE: return "MD_BLOCK_CODE";
        case MD_BLOCK_HTML: return "MD_BLOCK_HTML";
        case MD_BLOCK_P: return "MD_BLOCK_P";
        case MD_BLOCK_TABLE: return "MD_BLOCK_TABLE";
        case MD_BLOCK_THEAD: return "MD_BLOCK_THEAD";
        case MD_BLOCK_TBODY: return "MD_BLOCK_TBODY";
        case MD_BLOCK_TR: return "MD_BLOCK_TR";
        case MD_BLOCK_TH: return "MD_BLOCK_TH";
        case MD_BLOCK_TD: return "MD_BLOCK_TD";
        default: return NULL;
    }
}

