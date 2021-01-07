//
//  outputbuffer.h
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#ifndef outputbuffer_h
#define outputbuffer_h

#include "../md2brl/md2brl.h"

md2brl *incbuffer(md2brl *data, int neededsize);
void movechar(char *text, int textlen, int start, int offset);
char *inctextsize(char *text, int *textsize, int plus);

#endif /* outputbuffer_h */
