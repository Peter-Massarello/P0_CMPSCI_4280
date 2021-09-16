CC = gcc

CFLAGS  = -g -Wall -lstdc++
 
all: P0
 
P0: main.cpp tree.cpp tree.h node.h
	$(CC) -o $@ $^ $(CFLAGS) 
 
clean:
	rm P0
	rm -r *.dSYM