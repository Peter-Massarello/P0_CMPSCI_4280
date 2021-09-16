#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readFromKeyBoard();
void openFile(string fileName);
void readFromFile(ifstream &file);

int main(int argc, char **argv){
    if (argc == 1) { readFromKeyBoard(); } 
    else if (argc == 2) { openFile(argv[1]); } 
    else cout << "ERROR: Too many args given, existing...\n";

    return 0;
} 

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