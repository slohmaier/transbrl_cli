//
//  md2brl.h
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 02.01.21.
//

#ifndef md2brl_h
#define md2brl_h

#include "bool.h"

typedef struct {
    //states
    char *last_text;
    
    //output related
    char *output;
    int output_capacity;
    int output_size;
    
    bool debug;
    bool verbose;
    char *loutables;
    int width;
    int height;
} md2brl;

md2brl *md2brl_new(int width, int height, char *loutables, bool debug, bool verbose);
void md2brl_free(md2brl* data);

#endif /* md2brl_h */