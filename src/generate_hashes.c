#include <stdio.h>
#include <stdlib.h>

int readFile( FILE * file)
{
    char * line = NULL;
    size_t len = 0;
    int read;

    if (file == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, file)) != -1) {
        printf("Retrieved line of length %d:\n", read);
        printf("%s", line);
    }

    fseek(file, 0, SEEK_END);
    unsigned long size = (unsigned long)ftell(file);
    printf("Size of the file: %ld", size);

    fclose(file);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}