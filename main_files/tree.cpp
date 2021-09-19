/*
Name: Peter Massarello
Instructor: Mark Hauschild
Assignment: P0
Date: September 20th 2021
Class: CMPSCI 4280
*/
#include "tree.hpp"
using namespace std;

// Reads from keyboard and returns a vector of all strings given
vector<string> readFromKeyBoard(){
    string line;
    vector<string> wordList;
    while (cin>>line) // read input until none are left in stdin
    {
        wordList.push_back(line);
    }
    
    return wordList;
}

// Reads from keyboard and returns a vector of all strings given
vector<string> readFromFile(ifstream &file){
    string word;
    vector<string> wordList;
    while (file >> word) // Read from file until no words are left
    {   
        wordList.push_back(word);
    }

    return wordList;
}

// Opens the file of a specfic filename and reads from that file to get the words in there
vector<string> openFile(string fileName){
    ifstream file(fileName);
    vector<string> wordList;

    // Tries to open file, catches error if cannot and exits
    try {
        if (file)
            wordList = readFromFile(file);
        else
            throw -1;
    } catch(int error){
        cout << "ERROR: File could not be found, existing...\n";
        exit(1);
        
    }
    
    file.close();
    return wordList;
}

// Inserts value into node on tree
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

// Loop through entire wordList vector and insert word to node
Node* loopThroughWordListAndInsert(vector<string> wordList, Node* root){
    for(INT i = 1; i < wordList.size(); i++){
        insertNode(wordList.at(i), root);
    }
    return root;
}

// Build tree without file given
Node* buildTree(){
    vector<string> wordList = readFromKeyBoard(); // Read from keyboard to gain word list
    string word = wordList.at(0); // Take first word to initalize root
    Node* root;
    
    //initialize root
    root = new Node(word[0]);
    root->chars.push_back(word);

    return loopThroughWordListAndInsert(wordList, root); // Loop through rest of list and insert to root, then return
}

// Build tree with file given
Node* buildTree(string fileName){
    vector<string> wordList = openFile(fileName); // Try to open file
    string word = wordList.at(0); // Take first word to initalize root
    Node* root;

    //initialize root
    root = new Node(word[0]);
    root->chars.push_back(word);

   return loopThroughWordListAndInsert(wordList, root); // Loop through rest of list and insert to root, then return
}

// Prints current node level to file
void printRootLevelToFile(ofstream &file, Node* &root, int level){
    //create initial level text and tab over per how many levels deep
    file << level << ": ";
    for (int i = 0; i <= level; i++){
        file << "\t";
    }

    //add roots key to the current line    
    file << root->key<< ": ";

    //for each word in nodes elements array, add to new line
    for (INT i = 0; i < root->chars.size(); i++) {
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

//Removes bst from memory by recursion traversal
void deleteTree(Node* &root){
    if (root == NULL) return;
    
    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
    root = NULL;
}