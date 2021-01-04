//
//  writefile.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 04.01.21.
//

#include "writefile.h"

#include <stdio.h>

int writefile(char *filename, char *content, int size) {
    FILE *fd = fopen(filename, "w");
    if (fd == NULL) return -1;
    fwrite(content, sizeof(char), (size_t)size, fd);
    fclose(fd);
    return 0;
}
