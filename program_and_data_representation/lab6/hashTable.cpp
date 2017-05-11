
#include <iostream>
#include <cmath>
#include "hashTable.h"
#include "tableSize.h"
using namespace std;


bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

//read in grid file
bool hashTable::readInTable (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // table[][] array.  In the process, we'll print the table to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            table[r][c] = line[pos++];
            cout << table[r][c];
        }
        cout << endl;
    }
    // return success!
    return true;
}


//retrieve a word in a grid of letters in a given direction
char* hashTable::getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the table
        output[pos++] = table[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes table[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}


void hashTable::insertWordToHTable (string filename, vector<list<string> > h_Table) {
    string word;                                   // a C++ string to hold the line of data that is read in
    list<string> keyWord;

    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    
    if ( !file.is_open() ) {                                        // if can't open the file exit the program
        cout << "error" << endl;
        exit(0);
    }
    else {
        if(loadFactor(sizeOfDictionary(filename)) > 0.5){           // if the load factor is greater than 0.5
            file.close();                                           // close the file
            rehash(sizeOfDictionary(filename));                              // rehash by doubling the table size
            }
        
        for (int i = 0; i < sizeOfDictionary(filename); i++){
            getline(file, word);                                        // store first line of the file to string word
                if (word.length() > 3){                                     // if the length of word is greater than 3
                    string temp = word.substr(0, 3);                        // temp is first three letter of word
                    h_Table[hashFunction(word)].push_back(temp);            //insert to vector h_Table at a location determined by hashFunction

                for (int i = 3; i < word.length(); i++){                    // from the third letter til the entire word
                string temp = word.substr(0, i);                            // temp is the substring from 0 to i
                 h_Table[hashFunction(word)].push_back(temp);                // push temp to keyWord list
                    }
                }else {
            h_Table[hashFunction(word)].push_back(word);            // push word to the end of the keyWord list  
            }
    }

}
    file.close();
}


unsigned int hashTable::hashFunction(string word){
    key = 0;
    int power[22];
    for (int i = 0; i < 22; i++){
        power[i] = pow(37, i);
    }
    for(int i = 0; i < word.length() - 1; i++){
        key += word[i] * power[i];
    
    return key;
}

void hashTable::rehash(unsigned int tableSize){
    vector<list<string> > h_Table_New(2*tableSize)
    
}

unsigned int hashTable::loadFactor(unsigned int tableSize){
    return h_Table.size() / tableSize;
}