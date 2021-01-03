//
//  outputbuffer.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "outputbuffer.h"
#include <stdlib.h>

#define BUFF_INCREMENTS 1024

/* increase buffer by neededchars or buff_increments
 * which ever is bigger, if remaining size is too
 * small for neededchars */
md2brl *incbuffer(md2brl *data, int neededsize) {
    if(data->output_capacity - data->output_size < neededsize) {
        if (neededsize > BUFF_INCREMENTS) data->output_capacity += neededsize;
        else data->output_capacity += BUFF_INCREMENTS;
        
        data->output = (char*)realloc(data->output, sizeof(char)*data->output_capacity);
        if (data->output == NULL) return NULL;
    }
    return data;
}
