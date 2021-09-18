#include "tree.hpp"
#include "node.hpp"

using namespace std;

int main(int argc, char **argv){
    string fileName = "file";
    Node *root;

    if (argc == 1) { 
        root = buildTree();
    } else if (argc == 2) { 
        root = buildTree(argv[1]);
        fileName = argv[1];
    } else cout << "ERROR: Too many args given, existing...\n";

    ofstream inOrder(fileName + ".inorder");
    ofstream postOrder(fileName + ".postorder");
    ofstream preOrder(fileName + ".preorder");

    printInorder(inOrder, root);
    printPostorder(postOrder, root);
    printPreorder(preOrder, root);

    inOrder.close();
    postOrder.close();
    preOrder.close();

    return 0;
} 