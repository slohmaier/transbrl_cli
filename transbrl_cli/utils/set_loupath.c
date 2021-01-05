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

bool isdir(char *path);

int set_loupath(void) {
    if (isdir("liblouis")) {
        printf("LALA");
        lou_setDataPath(".");
    }
    return 0;
}

bool isdir(char *path) {
    struct stat info;
    
    if (stat(path, &info) != 0) return false;

    return (bool)(info.st_mode & S_IFDIR);
}