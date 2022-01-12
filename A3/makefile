CFLAGS = -Wpedantic -std=c99
CC = gcc

SRC_FILES = $(wildcard P*.c)
OBJ_FILES = $(patsubst P%.c,P%.o,$(SRC_FILES))

HELPERS = Helpers

MAIN = main

EXECUTABLES = $(MAIN)

all: $(EXECUTABLES)

P%.o: P%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(HELPERS).o: $(HELPERS).c 
	$(CC) $(CFLAGS) -c $(HELPERS).c  -o $(HELPERS).o

$(MAIN): $(MAIN).o $(OBJ_FILES) $(HELPERS).o
	$(CC) $(CFLAGS) $(MAIN).o $(HELPERS).o $(OBJ_FILES) -o $(MAIN)

clean:
	rm *o $(EXECUTABLES)