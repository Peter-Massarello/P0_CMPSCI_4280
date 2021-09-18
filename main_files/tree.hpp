#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "node.hpp"
using namespace std;

void printInorder(ofstream &file, Node* &root, int level);
void printPostorder(ofstream &file, Node* &root, int level);
void printPreorder(ofstream &file, Node* &root, int level);
Node* buildTree(string filename);
Node* buildTree();

#endif