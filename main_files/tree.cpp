#include "tree.hpp"
using namespace std;

vector<string> readFromKeyBoard(){
    string line;
    vector<string> wordList;
    while (getline(cin, line))
    {
        wordList.push_back(line);
    }
    
    return wordList;
}

vector<string> readFromFile(ifstream &file){
    string word;
    vector<string> wordList;
    while (file >> word)
    {   
        wordList.push_back(word);
    }
    for (int i = 0; i < wordList.size(); i++){
        cout << wordList.at(i) << endl;
    }
    return wordList;
}

vector<string> openFile(string fileName){
    ifstream file(fileName);
    vector<string> wordList;

    try {
        if (file)
            wordList = readFromFile(file);
        else
            throw -1;
    } catch(int error){
        cout << "ERROR: File could not be found, existing...\n";
    }
    
    file.close();
    return wordList;
}

void insertNode(string value, Node* root){
    char key = value[0];

    //if current key is equal to the root, place
    if(key == root->key){
        root->chars.push_back(value);
    }else{
        //if key is greater put in right node
        if (key > root->key){
            if (root->right == NULL){ //if right node is empty, place
                root->right = new Node(key);
                root->right->chars.push_back(value);
            } else //if key is already full go through right tree
                insertNode(value, root->right);
            
        } else { //if key is less put in left node
            if (root->left == NULL){ //if left root is empty, place
                root->left = new Node(key);
                root->left->chars.push_back(value);
            } else //if key is already full go through left tree
                insertNode(value, root->left);
        }
    }
}

Node* loopThroughWordListAndInsert(vector<string> wordList, Node* root){
    for(int i = 1; i < wordList.size(); i++){
        insertNode(wordList.at(i), root);
    }
    return root;
}

Node* buildTree(){
    vector<string> wordList = readFromKeyBoard();
    string word = wordList.at(0);
    Node* root;
    
    //initialize root
    root = new Node(word[0]);
    root->chars.push_back(word);

    return loopThroughWordListAndInsert(wordList, root);
}

Node* buildTree(string fileName){
    vector<string> wordList = openFile(fileName);
    string word = wordList.at(0);
    Node* root;

    //initialize root
    root = new Node(word[0]);
    root->chars.push_back(word);

   return loopThroughWordListAndInsert(wordList, root);
}

void printRootLevelToFile(ofstream &file, Node* &root, int level){
    //create initial level text and tab over per how many levels deep
    file << level << ": ";
    for (int i = 0; i <= level; i++){
        file << "\t";
    }

    //add roots key to the current line    
    file << root->key<< " " << endl;

    //create second line for keys elements by tabbing over
    for (int i = 0; i <= level; i++){
        file << "\t";
    }

    //for each word in nodes elements array, add to new line
    for (int i = 0; i < root->chars.size(); i++) {
        if (i == 0){
            file << "\t";
        }   
        file << root->chars.at(i) << " ";
    }

    file << endl << endl;
}

// left root right
void printInorder(ofstream &file, Node* &root, int level){
    if (root == NULL) return;

    //left substree
    printInorder(file, root->left, level+1);

    //root
    printRootLevelToFile(file, root, level);    

    //right subtree
    printInorder(file, root->right, level+1);
}

// left right root
void printPostorder(ofstream &file, Node* &root, int level){
    if (root == NULL) return;

    //left substree
    printInorder(file, root->left, level+1);

    //right subtree
    printInorder(file, root->right, level+1);

    //root
    printRootLevelToFile(file, root, level);    
}

// root left right
void printPreorder(ofstream &file, Node* &root, int level){
    if (root == NULL) return;

    //root
    printRootLevelToFile(file, root, level);  

    //left substree
    printInorder(file, root->left, level+1);  

    //right subtree
    printInorder(file, root->right, level+1);
}