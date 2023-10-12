#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/includes.h"

void print_error_message() {
    printf("Wrong arguments or number of arguments.\n");
}

int main(int argc, char* argv[]) {
    int opt;

    while ((opt = getopt(argc, argv, "GL")) != -1 ) {
        switch (opt)
        {
        case 'G':
            FILE *f = fopen(argv[2], "r");

            if (f == NULL) {
                printf("Cannot open file.");
                return 1;
            }  
            generateHashesFromFile(f);
            break;

        case 'L':
            FILE *inputFile = fopen(argv[2], "r");
            FILE *rainbowTable = fopen(argv[3], "r");
            if (inputFile == NULL || rainbowTable == NULL) {
                printf("Cannot open file.");
                return 1;
            }  
            testPasswordFromFile(inputFile, rainbowTable);
            break;


        default:
            print_error_message();
            break;
        }
    }
    
    return 0;
}