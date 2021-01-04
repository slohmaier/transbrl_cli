//
//  main_check.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 02.01.21.
//

#include "main_check.h"
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int checkopts(char *markdownfile, int width, int height, char *loutables, char *outfile) {
    int ret = 0;
    
    if (markdownfile == NULL) { fprintf(stderr, "Missing option -m. Try -h.\n"); ret = 2; }
    if (width == -1) { fprintf(stderr, "Missing option -W. Try -h.\n"); ret = 2; }
    if (height == -1) { fprintf(stderr, "Missing option -H. Try -h.\n"); ret = 2; }
    if (loutables == NULL) { fprintf(stderr, "Missing option -t. Try -h.\n"); ret = 2; }
    if (outfile == NULL) { fprintf(stderr, "Missing option -o. Try -h.\n"); ret = 2; }
    
    return ret;
}

//parse dimenstion from optarg. On error output error
//message using title and exit;
int parse_dimenstion(char *optarg, char *title) {
    char *res;
    long num = strtol(optarg, &res, 10);
    if (num > INT32_MAX || num <= 0 || *res != '\0') {
        fprintf(stderr, "ERROR: %s must be a non-zero integer!\n", title);
        exit(1);
    }
    return (int)num;
}
