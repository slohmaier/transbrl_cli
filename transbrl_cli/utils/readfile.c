//
//  readfile.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 02.01.21.
//

#include "readfile.h"

#include <stdio.h>
#include <stdlib.h>

char *readfile(const char *path) {
    FILE *fd;
    long fsize;
    char *content;
    
    //try open file
    fd = fopen(path, "r");
    if (fd == NULL) return NULL;
    
    //get size of file
    if (fseek(fd, 0, SEEK_END) != 0) return NULL;
    if ((fsize = ftell(fd)) == -1) return NULL;
    rewind(fd);
    
    //alloc read and return
    content = (char*) malloc(sizeof(char*)*fsize);
    if (content == NULL) return NULL;
    #ifdef _MSC_VER //FIXME
    fread(content, sizeof(char), fsize, fd);
    #else
    if (fread(content, sizeof(char), fsize, fd) < fsize) return NULL;
    #endif
    return content;
}
