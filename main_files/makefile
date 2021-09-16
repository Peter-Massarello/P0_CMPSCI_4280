CC = gcc

CFLAGS  = -g -Wall -lstdc++
 
all: P0
 
P0: main.cpp tree.cpp tree.hpp node.hpp
	$(CC) -o $@ $^ $(CFLAGS) 
 
clean:
	rm P0
	rm -r *.dSYM
	rm *.inorder *.postorder *.preorder