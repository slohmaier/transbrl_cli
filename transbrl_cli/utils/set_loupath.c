//
//  set_loupath.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 05.01.21.
//

#include "set_loupath.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "bool.h"
#include "liblouis.h"
#include <stdio.h>
#include <stdlib.h>

bool isdir(char *path);

#define MAXPATH 1024

int set_loupath(char *loudatapath) {
    
    char buf[MAXPATH];
    char *program_path;

    buf[0] = '\0';

    program_path = lou_getProgramPath();
    sprintf(buf, "%s/liblouis", program_path);

    if (isdir(buf)) {
        printf("LALA");
        lou_setDataPath(program_path);
    } else if (loudatapath != NULL) {
        lou_setDataPath(loudatapath);
    }
    free(program_path);
    return 0;
}

bool isdir(char *path) {
    struct stat info;
    
    if (stat(path, &info) != 0) return false;

    return (bool)(info.st_mode & S_IFDIR);
}
