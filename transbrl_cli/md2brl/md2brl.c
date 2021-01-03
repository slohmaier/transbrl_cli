//
//  md2brl.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 02.01.21.
//

#include "md2brl.h"

#include <stdlib.h>

#define MD2BRL_NEWSIZE 128

md2brl *md2brl_new(int width, int height, char *loutables, bool debug, bool verbose) {
    md2brl *data = (md2brl*)malloc(sizeof(md2brl));
    if (data == NULL) return NULL;
    
    //parameters
    data->debug = debug;
    data->verbose = verbose;
    data->width = width;
    data->height = height;
    data->loutables = loutables;
    
    //state vars
    data->last_text = NULL;
    data->last_text_size = -1;
    
    //create empty string
    data->output_capacity = MD2BRL_NEWSIZE;
    data->output = (char *)malloc(sizeof(char)*data->output_capacity);
    data->output[0] = '\0';
    data->output_size = 1;
    
    return data;
}

void md2brl_free(md2brl* data) {
    if (data->last_text != NULL) free(data->last_text);
    free(data->output);
    free(data);
}
