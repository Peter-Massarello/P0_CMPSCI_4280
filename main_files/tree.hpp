/*
Name: Peter Massarello
Instructor: Mark Hauschild
Assignment: P0
Date: September 20th 2021
*/
#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "node.hpp"
using namespace std;

typedef long unsigned int INT; // typedef to remove warnings when trying to use 'int' to loop through vector 

void printInorder(ofstream &file, Node* &root, int level);
void printPostorder(ofstream &file, Node* &root, int level);
void printPreorder(ofstream &file, Node* &root, int level);
Node* buildTree(string filename);
Node* buildTree();
void deleteTree(Node* &root);

#endif