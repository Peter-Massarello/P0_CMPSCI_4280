#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "node.hpp"
using namespace std;

void printInorder(ofstream &file, Node* &root);
void printPostorder(ofstream &file, Node* &root);
void printPreorder(ofstream &file, Node* &root);
Node* buildTree(string filename);
Node* buildTree();

#endif