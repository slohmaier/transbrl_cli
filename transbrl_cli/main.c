//
//  main.c
//  transbrl_cli
//
//  Created by Stefan Lohmaier on 02.01.21.
//

#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "md2brl.h"
#include "md2brl_parser.h"
#include "readfile.h"
#include "main_check.h"
#include "main_output.h"

void print_help(char **argv);
int parse_dimenstion(char *optarg, char *title);

int main(int argc, char * argv[]) {
    //data read from getop. set to invalid values.
    char *markdownfile = NULL;
    int width = -1;
    int height = -1;
    char *loutables = NULL;
    char *outfile = NULL;
    //flags from opts
    bool debug = false;
    bool verbose = false;
    //buffers
    char *mdcontent;
    md2brl *data;
    //needed for getopt
    int optch;
    //ret to check for errors.
    int ret = 0;
    
    //parse options
    while ((optch = getopt(argc, argv, "hm:W:H:t:vdo:")) != -1) {
        switch (optch) {
            case 'h':
                print_help(argv);
                return 0;
                break;
            default:
                fprintf(stderr, "Unknown cmdline option: %s Try -h for help.", argv[optind]);
                return 1;
                break;
            case 'W': width = parse_dimenstion(optarg, "Width"); break;
            case 'H': height = parse_dimenstion(optarg, "Height"); break;
            case 'm': markdownfile = optarg; break;
            case 't': loutables = optarg; break;
            case 'o': outfile = optarg; break;
            case 'd': debug = true; break;
            case 'v': verbose = true; break;
        }
    }
    
    //Check given opts and output errors.
    if ((ret = checkopts(markdownfile, width, height, loutables, outfile)) != 0) return ret;
    
    //create data object for parser
    data = md2brl_new(width, height, loutables, debug, verbose);
    if (data == NULL) { fprintf(stderr, "Could not create data-obkect: %s\n", strerror(errno)); ret = -1; }
    
    //print information
    if (verbose) print_startmsg(markdownfile, width, height, loutables, outfile);
    
    //read whole markdownfile in memory
    if (verbose) printf("# Reading markdownfile :");
    if ((mdcontent = readfile(markdownfile)) == NULL) {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return -1;
    }
    else if (verbose) printf("SUCCESS!\n");
    
    //parse markdown
    if (md2brl_parse(mdcontent, (unsigned)strlen(mdcontent), data) != 0) {
        fprintf(stderr, "PARSER-ERRPR: %s\n", strerror(errno));
        return -1;
    }
    
    //free memory
    if (verbose) printf("# Cleaning up...\n");
    free(mdcontent);
    md2brl_free(data);
    
    return ret;
}
