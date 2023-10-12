#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/generate_hashes.h"

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
            printf("%s\n",argv[2]);
            readFile(f);
            break;
        
        default:
            print_error_message();
            break;
        }
    }
    {
        print_error_message();
        return 1;
    }
    
    return 0;
}