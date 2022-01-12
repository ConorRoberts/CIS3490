CFLAGS = -Wpedantic -std=c99
CC = gcc

P11 = P11
P12 = P12

P21 = P21
P22 = P22

HELPERS = Helpers

MAIN = main

EXECUTABLES = $(MAIN)

all: $(EXECUTABLES)

$(P11).o: $(P11).c 
	$(CC) $(CFLAGS) -c $(P11).c  -o $(P11).o

$(P12).o: $(P12).c 
	$(CC) $(CFLAGS) -c $(P12).c  -o $(P12).o

$(P21).o: $(P21).c 
	$(CC) $(CFLAGS) -c $(P21).c  -o $(P21).o

$(P22).o: $(P22).c 
	$(CC) $(CFLAGS) -c $(P22).c  -o $(P22).o

$(HELPERS).o: $(HELPERS).c 
	$(CC) $(CFLAGS) -c $(HELPERS).c  -o $(HELPERS).o

$(MAIN): $(MAIN).o $(P11).o $(P12).o $(P21).o $(P22).o $(HELPERS).o
	$(CC) $(CFLAGS) $(MAIN).o $(P11).o $(P12).o $(P21).o $(P22).o $(HELPERS).o -o $(MAIN) -lm

clean:
	rm *o $(EXECUTABLES)