#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <stdlib.h>

int testPasswordFromFile(FILE * inputFile, FILE * rainbowTable) {
    char * lineF = NULL;
    size_t lenF = 0;
    int readF;
    char * lineT = NULL;
    size_t lenT = 0;
    int readT;

    // fseek(rainbowTable, 0, SEEK_END);
    // unsigned long size = (unsigned long)ftell(rainbowTable);
    // printf("Size of the rainbow table: %ld", size);

    while ((readF = getline(&lineF, &lenF, inputFile)) != -1) {
        char *cryptLine = crypt(lineF, "key");
        while ((readT = getline(&lineT, &lenT, rainbowTable)) != -1)  {
            if (strcmp(cryptLine, lineT) == 0) {
                printf("%s:%s\n",lineF,lineT);
            }
        }
    }

    return 0;
} 