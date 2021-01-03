//
//  md2brl_parser.h
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#ifndef md2brl_parser_h
#define md2brl_parser_h

#include "md4c.h"
#include "md2brl.h"

MD_PARSER *md2brl_parser(void);
int md2brl_parse(char *text, unsigned size, md2brl *data);

#endif /* md2brl_parser_h */
