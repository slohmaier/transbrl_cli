//
//  md2brl_trans.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 03.01.21.
//

#include "md2brl_trans.h"
#include <stdlib.h>
#include <string.h>
#include "../external/liblouis/liblouis.h"

char *md2brl_trans(const char *text, int *textlen, const char *loutable) {
    char *result;
    widechar *inbuf = (widechar*)malloc(sizeof(widechar)*(*textlen));
    int inlen = *textlen;
    int i;
    //TODO: is *2 needed?
    widechar *outbuf = (widechar*)malloc(sizeof(widechar)*(*textlen)*2);
    int outlen = *textlen * 2;
    if (inbuf == NULL || outbuf == NULL) {
        free(inbuf); free(outbuf); return NULL;
    }
    
    //convert to widechar *
    for (i = 0; i < *textlen; i++) inbuf[i] = text[i];
    
    //TODO: modes? (is last parameter)
    if (lou_translateString(loutable, inbuf, &inlen, outbuf, &outlen, NULL, NULL, 0) != 1) {
        free(inbuf); free(outbuf); return NULL;
    }
    *textlen = outlen;
    
    //widerchar to char
    result = (char*)malloc(sizeof(char)*outlen);
    if (result == NULL) { free(inbuf); free(outbuf); return NULL; }
    for (i = 0; i < outlen; i++) result[i] = outbuf[i];
    
    //FIXME: free(inbuf);
    //FIXME: free(outbuf);
    return result;
}
