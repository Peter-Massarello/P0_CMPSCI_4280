#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
using namespace std;

struct Node {
    char key;
    struct Node* left, *right;
    vector<string> chars;

    Node(char data){
        key = data;
        left = right = NULL;
    }
};

#endif