#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure pour stocker les données (hash et mot de passe)
typedef struct RainbowTableRow {
    char hash[65];
    char password[256];
    struct RainbowTableRow* left;
    struct RainbowTableRow* right;
} RainbowTableRow;

// Fonction pour insérer une entrée dans l'arbre binaire
RainbowTableRow* insert(RainbowTableRow* root, const char* hash, const char* password) {
    if (root == NULL) {
        RainbowTableRow* node = (RainbowTableRow*)malloc(sizeof(RainbowTableRow));
        if (node == NULL) {
            perror("Erreur d'allocation de mémoire");
            exit(1);
        }
        strcpy(node->hash, hash);
        strcpy(node->password, password);
        node->left = node->right = NULL;
        return node;
    }

    int cmp = strcmp(hash, root->hash);
    if (cmp < 0) {
        root->left = insert(root->left, hash, password);
    } else if (cmp > 0) {
        root->right = insert(root->right, hash, password);
    }

    return root;
}

// Fonction pour lire un fichier et initialiser la rainbow table
RainbowTableRow* initRainbowTableFromFile(const char* filename) {
    RainbowTableRow* rainbowTable = NULL;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Impossible d'ouvrir le fichier");
        exit(1);
    }

    char line[320];
    while (fgets(line, sizeof(line), file) != NULL) {
        char* delimiter = strchr(line, ':');
        if (delimiter != NULL) {
            *delimiter = '\0'; // Remplace le premier ':' par un caractère nul
            char* hash = line;
            char* password = delimiter + 1;

            rainbowTable = insert(rainbowTable, hash, password);
        }
    }

    fclose(file);
    return rainbowTable;
}

// Fonction pour chercher un mot de passe en utilisant l'arbre binaire
const char* findPasswordFromRainbowTable(RainbowTableRow* root, const char* hash) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(hash, root->hash);
    if (cmp == 0) {
        return root->password;
    } else if (cmp < 0) {
        return findPasswordFromRainbowTable(root->left, hash);
    } else {
        return findPasswordFromRainbowTable(root->right, hash);
    }
}

// Fonction pour chercher les mots de passes contenue dans un fichier
void findPassword(const char* hashFilname, const char* rainbowFilename) {
    RainbowTableRow* rainbowTable = initRainbowTableFromFile(rainbowFilename);

    FILE *hashFile = fopen(hashFilname, "r");
    char hashToFind[65];

    while (fscanf(hashFile, "%64s", hashToFind) != EOF) {
        size_t len = strlen(hashToFind);
        if (len > 0 && hashToFind[len - 1] == '\n') {
            hashToFind[len - 1] = '\0';
        }
        // printf("%s\n", hashToFind);

        const char* foundPassword = findPasswordFromRainbowTable(rainbowTable, hashToFind);

        if (foundPassword != NULL) {
            printf("Hash: %s, Password: %s\n", hashToFind, foundPassword);
        } else {
            printf("Hash: %s, Password not found\n", hashToFind);
        }
    }

    fclose(hashFile);
}