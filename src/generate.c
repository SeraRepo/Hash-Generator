#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

// Fonction pour hasher les mots de passe dans la rainbow.table
int hashPasswordFile(const char *inputFile, const char *outputFile) {
    FILE *file = fopen("minirockyou.txt", "r");
    if (!file) {
        perror("Error with input file");
        fclose(file);
        return 1;
    }
    printf("1");

    FILE *rainbowTable = fopen("rainbow.table", "w");
    if (!rainbowTable) {
        perror("Error with output file");
        fclose(rainbowTable);
        return 1;
    }
    printf("2");
    

    char line[256];  

    printf("3");
    // Différent algorithmes de chiffrements
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    // const EVP_MD *md = NULL;
    const EVP_MD *md = EVP_md5();
    // if (strcmp(algorithm, "md5") == 0) {
    //     md = EVP_md5();
    //     printf("md5");
    // } else if (strcmp(algorithm, "sha256") == 0) {
    //     md = EVP_sha256();
    //     printf("sha256");
    // } else if (strcmp(algorithm, "sha1") == 0) {
    //     md = EVP_sha1();
    //     printf("sha1");
    // } else {
    //     perror("Wrong type of algorithm, choose between \"md5\", \"sha1\" or \"sha256\"");
    //     return 1;
    // }
    printf("4");

    while (fgets(line, sizeof(line), inputFile)) {
        line[strcspn(line, "\n")] = 0; 

        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, line, strlen(line));

        unsigned char hash[EVP_MD_size(md)];
        int hashLen;
        EVP_DigestFinal(mdctx, hash, &hashLen);

        for (int i = 0; i < hashLen; i++) {
            fprintf(rainbowTable, "%02x", hash[i]);
        }
        fprintf(rainbowTable, ":%s\n", line);
    }

    EVP_MD_CTX_free(mdctx);
    fclose(inputFile);
    fclose(rainbowTable);

    return 0;
}