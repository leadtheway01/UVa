
#include <iostream>
#include <cmath>
#include "hashTable.h"
using namespace std;


//to get the size of the dictionary
int hashTable::sizeOfDictionary (string filename) {
    // a C++ string to hold the word of a line that is read in
    string word;
    int count = 0;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        cout << "error" <<endl;
        exit(0);
    //read until end of the file
    while(!file.eof()){ 
        getline(file, word);
        count++;
    }
    file.close();
    return count;
}
