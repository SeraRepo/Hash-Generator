#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/generate.h"
#include "../include/lookup.h"

int main(int argc, char *argv[]) {
    char *inputFile = NULL;
    char *outputFile = "rainbow.table";
    char *tableFile = "rainbow.table";
    char *algorithm = "md5";
    int lookupMode = 0;
    int generateMode = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-L") == 0) {
            if (i + 1 < argc) {
                lookupMode = 1;
                inputFile = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: Missing argument for -L option\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-G") == 0) {
            if (i + 1 < argc) {
                generateMode = 1;
                inputFile = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: Missing argument for -G option\n");
                return 1;
            }
        } else if (generateMode && strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                outputFile = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: Missing argument for -o option\n");
                return 1;
            }
        } else if (generateMode && strcmp(argv[i], "--algorithm") == 0) {
            if (i + 1 < argc) {
                algorithm = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: Missing argument for --algorithm option\n");
                return 1;
            }
        } else if (lookupMode && strcmp(argv[i], "-i") == 0) {
            if (i + 1 < argc) {
                tableFile = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: Missing argument for -i option\n");
                return 1;
            }
        } else {
            fprintf(stderr, "Error: Invalid argument: %s\n", argv[i]);
            return 1;
        }
    }

    if (generateMode) {
        printf("Writing %s with %s algorithm... \n", outputFile, algorithm);
        hashPasswordFile(inputFile, outputFile, algorithm);
    }

    if (lookupMode) {
        printf("Loading dict file: %s\n", tableFile);
        findPassword(inputFile, tableFile);
    }

    return 0;
}