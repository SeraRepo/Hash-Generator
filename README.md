# Hash Generator

## Prerequis 

Vous devez avec la librairie openssl dev d'installer sur l'ordinateur ainsi que make

``` bash
sudo apt install libssl-dev
sudo apt install make
```

## Installation du projet

Cloner le dépot github

``` bash
git clone https://github.com/SeraRepo/Hash-Generator
```

Compiler le projet

``` bash
make
```

Le binaire compiler sera ./src/main

## Utilisation du projet

Le projet a deux mode de fonctionnnement : un générateur de condensats à partir d'un dictionnaire de mot de passe donné (-G) et un chercheur de mot de passe par condensat (-L).

### Mode générateur de condensat (-G)

Le mode -G prend en paramètre en entrée un dictionnaire de mot de passe et a comme option facultative : -o qui indique l'endroit et le nom de la table générée ; et --algorithm qui permet de choisir entre trois algorithmes de chiffrements (sha256, sha1 et md5).

Par défaut la table générée s'appelle rainbow.table et est générée à l'endroit de lancement de l'exécutable, et l'algorithme de chiffrement est md5.

``` bash
./src/main -G inputFile -o outPutFile --algorithm algo
```

### Mode chercheur de mot de passe par condensat (-L)

Le mode -L prend en paramètre en entrée un dictionnaire de condensat à retrouver et a comme option facultative -i qui indique la table de correspondance condensat:motdepasse à utiliser.

Par défaut la table de correspondance utilisée est rainbow.table située à l'endroit de lancement de l'exécutable.

``` bash
./src/main -L inputFile -i rainbow.table
```