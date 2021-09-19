/*
Name: Peter Massarello
Instructor: Mark Hauschild
Assignment: P0
Date: September 20th 2021
Class: CMPSCI 4280
*/
#include "tree.hpp"
#include "node.hpp"

using namespace std;

int main(int argc, char **argv){
    string fileName = "output";
    Node *root;

    // Read from command line and determine path based on arg count
    if (argc == 1) { 
        root = buildTree();
    } else if (argc == 2) { 
        root = buildTree(argv[1]);
        fileName = argv[1];
    } else cout << "ERROR: Too many args given, existing...\n";

    // Create the three files that will be used
    ofstream inOrder(fileName + ".inorder");
    ofstream postOrder(fileName + ".postorder");
    ofstream preOrder(fileName + ".preorder");

    // Print to each file with their traversal method
    printInorder(inOrder, root, 0);
    printPostorder(postOrder, root, 0);
    printPreorder(preOrder, root, 0);

    // Close each file
    inOrder.close();
    postOrder.close();
    preOrder.close();

    // Remove tree from memory
    deleteTree(root);

    return 0;
}