CC=gcc
CFLAGS=-g -Wall -lcrypt -lssl -lcrypto
SRC=src/
EXEC=main

all:$(EXEC)

main: $(SRC)main.c  $(SRC)generate.o $(SRC)lookup.o
	$(CC) -o $(SRC)$@ $^ $(CFLAGS)

$(SRC)%.o:  $(SRC)%.CC
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(SRC)*.o $(SRC)main
