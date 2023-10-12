#include <stdio.h>
#include <crypt.h>
#include <stdlib.h>

int generateHashesFromFile( FILE * file)
{
    char * line = NULL;
    char * filename = "rainbowtable.table";
    size_t len = 0;
    int read;

    if (file == NULL)
        return 1;

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) 
        return 1;

    while ((read = getline(&line, &len, file)) != -1) {
        char *cryptLine = crypt(line, "key");
        fprintf(fp, "%s\n", cryptLine);
    }

    fclose(file);
    if (line)
        free(line);
    return 0;
}