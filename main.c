#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "include/generate.h"
#include "include/lookup.h"

int main(int argc, char *argv[]) {
    hashPasswordFile("minirockyou.txt", "rainbow.table");
}