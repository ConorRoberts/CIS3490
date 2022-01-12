CFLAGS = -Wpedantic -std=c99
CC = gcc

HELPERS = Helpers

OBJ1 = Q1
OBJ2 = Q2

EXECUTABLES = $(OBJ1) $(OBJ2)

all: $(EXECUTABLES)

$(HELPERS).o: $(HELPERS).c 
	$(CC) $(CFLAGS) -c $(HELPERS).c  -o $(HELPERS).o

$(OBJ1).o: $(OBJ1).c 
	$(CC) $(CFLAGS) -c $(OBJ1).c  -o $(OBJ1).o

$(OBJ1): $(OBJ1).o $(HELPERS).o
	$(CC) $(CFLAGS) $(OBJ1).o $(HELPERS).o -o $(OBJ1)

$(OBJ2).o: $(OBJ2).c 
	$(CC) $(CFLAGS) -c $(OBJ2).c  -o $(OBJ2).o

$(OBJ2): $(OBJ2).o $(HELPERS).o
	$(CC) $(CFLAGS) $(OBJ2).o $(HELPERS).o -o $(OBJ2)

clean:
	rm *o $(EXECUTABLES)