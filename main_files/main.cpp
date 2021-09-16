#include "tree.hpp"

using namespace std;

int main(int argc, char **argv){
    string fileName = "file";

    if (argc == 1)
    { 
        readFromKeyBoard(); 
    } else if (argc == 2) 
    { 
        openFile(argv[1]); 
        fileName = argv[1];
    } else cout << "ERROR: Too many args given, existing...\n";

    ofstream inOrder(fileName + ".inorder");
    ofstream postOrder(fileName + ".postorder");
    ofstream preOrder(fileName + ".preorder");

    printInorder(inOrder);
    printPostorder(postOrder);
    printPreorder(preOrder);

    inOrder.close();
    postOrder.close();
    preOrder.close();

    return 0;
} 