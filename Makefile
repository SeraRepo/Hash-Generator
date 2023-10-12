CC=gcc
CFLAGS=-g -Wall
SRC=src/
EXEC=main

all:$(EXEC)

main: $(SRC)main.c  $(SRC)generate_hashes.o
	$(CC) -o $(SRC)$@ $^ $(CFLAGS)

$(SRC)%.o:  $(SRC)%.CC
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(SRC)*.o