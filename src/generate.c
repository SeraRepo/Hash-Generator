#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

// Fonction pour hasher les mots de passe dans la rainbow.table
int hashPasswordFile(const char *inputFile, const char *outputFile, const char * algorithm) {
    FILE *file = fopen(inputFile, "r");
    if (!file) {
        perror("Error with input file");
        fclose(file);
        return 1;
    }

    FILE *rainbowTable = fopen(outputFile, "w");
    if (!rainbowTable) {
        perror("Error with output file");
        fclose(rainbowTable);
        return 1;
    }
    
    char line[256];  

    // Différent algorithmes de chiffrements
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    const EVP_MD *md = NULL;
    if (strcmp(algorithm, "md5") == 0) {
        md = EVP_md5();
    } else if (strcmp(algorithm, "sha256") == 0) {
        md = EVP_sha256();
    } else if (strcmp(algorithm, "sha1") == 0) {
        md = EVP_sha1();
    } else {
        perror("Wrong type of algorithm, choose between \"md5\", \"sha1\" or \"sha256\"");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; 

        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, line, strlen(line));

        unsigned char hash[EVP_MD_size(md)];
        unsigned int hashLen;
        EVP_DigestFinal(mdctx, hash, &hashLen);

        for (int i = 0; i < hashLen; i++) {
            fprintf(rainbowTable, "%02x", hash[i]);
        }
        fprintf(rainbowTable, ":%s\n", line);
    }

    EVP_MD_CTX_free(mdctx);
    fclose(file);
    fclose(rainbowTable);

    return 0;
}