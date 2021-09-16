#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

void readFromKeyBoard();
void openFile(string fileName);
void readFromFile(ifstream &file);
void printInorder(ofstream &file);
void printPostorder(ofstream &file);
void printPreorder(ofstream &file);

#endif