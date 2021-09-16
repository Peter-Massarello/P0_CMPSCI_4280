#include <iostream>

using namespace std;

int main(int argc, char **argv){
    if (argc == 1) {
        cout << "no arg given\n";
    } else if (argc == 2) {
        cout << "1 arg given\n";
    } else 
        cout << "ERROR: Too many args given, existing...\n";

    return 0;
} 