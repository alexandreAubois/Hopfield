CFLAGS=-Wall 
LDFLAGS=

CC=gcc
EXE= main

all: $(EXE)

main: main.o hopfield.o
	$(CC) -o main main.o hopfield.o $(LDFLAGS)

main.o: main.c hopfield.o
	$(CC) $(CFLAGS) -c main.c

hopfield.o: hopfield.c hopfield.h
	$(CC) $(CFLAGS) -c hopfield.c

clean: 	
	rm -rf *.o
	rm -rf $(EXE)
