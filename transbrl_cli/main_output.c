//
//  main_output.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 02.01.21.
//

#include "main_output.h"


#ifndef _MSC_VER
#include <unistd.h>
#include <limits.h>
#endif
#include <stdio.h>
#include "external/liblouis/liblouis.h"

void print_help(char **argv) {
    printf("transbrl_cli - Translate markdown to brl\n");
    printf("\n");
    printf("%s [-h] [-m MARKDOWNFILE] \n", argv[0]);
    printf("        [-o outputfile can be - for stdout]\n");
    printf("        [-H HEIGHT in chars]\n");
    printf("        [-W WIDTH in chars]\n");
    printf("        [-t libloouis tables list]\n");
    printf("        [-d activate debug output]\n");
    printf("        [-v activate verbose output]\n");
    printf("\n");
}

void print_startmsg(char *markdownfile, int width, int height, char *loutables, char *outfile) {
    #ifndef _MSC_VER
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    }
    else {
        fprintf(stderr, "getcwd() error");
    }
    #endif
    printf("transbrl_cli - Version TODO\n");
    printf("###########################\n");
    #ifndef _MSC_VER
    printf("# cwd: %s\n", cwd);
    #endif
    printf("# md-file: %s\n", markdownfile);
    printf("# outfile: %s\n", outfile);
    printf("# Page: width=%d height=%d\n", width, height);
    printf("# liblouis tables: %s\n", loutables);
    printf("# liblouis-version: %s\n", lou_version());
    printf("###########################\n");
}
