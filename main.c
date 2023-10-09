#include <stdio.h>

void print_error_message() {
    printf("Wrong arguments or number of arguments.\n");
    printf("\n");
    printf("\n");
}

int main(int argc, char* argv[]) {
    if ((argv[1] == "-g" || argv[1] == "--generate-hashes") && argc == 3) {
        
    } else if ((argv[1] == "-t" || "--test-password") && argc == 4) {

    } else {
        print_error_message();
    }
    return 0;
}