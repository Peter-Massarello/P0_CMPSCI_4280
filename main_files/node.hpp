/*
Name: Peter Massarello
Instructor: Mark Hauschild
Assignment: P0
Date: September 20th 2021
*/
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
using namespace std;

// Struct for Node
struct Node {
    char key; // Key for level of BST
    struct Node *left, *right; // Child nodes
    vector<string> chars; // Vector of words on that level of key

    // Constructor
    Node(char data){
        key = data;
        left = right = NULL;
    }
};

#endif