//
//  md2brl_parser.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brl_parser.h"
#include <stdlib.h>
#include "callbacks/md2brlcb_enter_block.h"
#include "callbacks/md2brlcb_leave_block.h"
#include "callbacks/md2brlcb_enter_span.h"
#include "callbacks/md2brlcb_leave_span.h"
#include "callbacks/md2brlcb_text.h"
#include "callbacks/md2brlcb_debug_log.h"

MD_PARSER *md2brl_parser(void) {
    MD_PARSER *parser = (MD_PARSER*)malloc(sizeof(MD_PARSER));
    if (parser == NULL) return NULL;
    
    parser->abi_version = 0;
    parser->flags = 0; //TODO check if some are useful
    
    parser->enter_block = md2brlcb_enter_block;
    parser->leave_block = md2brlcb_leave_block;
    parser->enter_span = md2brlcb_enter_span;
    parser->leave_span = md2brlcb_leave_span;
    parser->text = md2brlcb_text;
    parser->debug_log = md2brlcb_debug_log;
    parser->syntax = NULL; //accodring to md4c.h
    
    return parser;
}

int md2brl_parse(char *text, unsigned size, md2brl *data) {
    MD_PARSER *parser = md2brl_parser();
    if (parser == NULL) return -1;
    
    return md_parse(text, size, parser, (void*)data);
}
