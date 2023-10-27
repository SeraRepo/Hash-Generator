#ifndef GENERATE_H
#define GENERATE_H

#include <openssl/evp.h>

int hashPasswordFile(const char *inputFile, const char *outputFile);

#endif  // GENERATE_H
