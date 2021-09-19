CC = gcc

CFLAGS  = -g -Wall -std=c++11 -lstdc++
 
all: P0

P0: node.hpp tree.cpp tree.hpp main.cpp 
	$(CC) -o $@ $^ $(CFLAGS) 
 
clean:
	rm P0 *.inorder *.postorder *.preorder
	rm -r *.dSYM