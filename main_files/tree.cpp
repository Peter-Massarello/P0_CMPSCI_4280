#include "tree.hpp"
using namespace std;

void readFromKeyBoard(){
    string line;
    string output = "";
    while (getline(cin, line))
    {
        output += line + " ";
    }
    cout << output << endl;
}

void readFromFile(ifstream &file){
    string word;
    vector<string> wordList;
    while (file >> word)
    {   
        wordList.push_back(word);
    }
    for (int i = 0; i < wordList.size(); i++){
        cout << wordList.at(i) << endl;
    }
}

void openFile(string fileName){
    ifstream file(fileName);

    try {
        if (file)
            readFromFile(file);
        else
            throw -1;
    } catch(int error){
        cout << "ERROR: File could not be found, existing...\n";
    }
    
    file.close();
}

void printInorder(ofstream &file){

}

void printPostorder(ofstream &file){

}

void printPreorder(ofstream &file){

}