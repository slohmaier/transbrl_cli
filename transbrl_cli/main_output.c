//
//  main_output.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 02.01.21.
//

#include "main_output.h"

#include <stdio.h>
//#include "liblouis.h"

void print_help(char **argv) {
    printf("transbrl_cli - Translate markdown to brl\n");
    printf("\n");
    printf("%s [-h] [-m MARKDOWNFILE] \n", argv[0]);
    printf("        [-H HEIGHT in chars]\n");
    printf("        [-W WIDTH in chars]\n");
    printf("        [-t libloouis tables list]\n");
    printf("        [-d activate debug output]\n");
    printf("\n");
}

void print_startmsg(char *markdownfile, int width, int height, char *loutables, char *outfile) {
    printf("transbrl_cli - Version TODO\n");
    printf("###########################\n");
    printf("# md-fike: %s\n", markdownfile);
    printf("# outfile: %s\n", outfile);
    printf("# Page: width=%d height=%d", width, height);
    printf("# liblouis tables: %s\n", loutables);
    printf("###########################\n");
}
