//Wright Kim
//wdk7bj
//huffmandec.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "dheap.h"
#include "dnode.h"
using namespace std;

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // vector of struct to store char c and string bitcode
    struct decodingInfo {
        string c;
        string bitcode;
    };
    // decVec created
    vector<decodingInfo> decVec;
    // to use member functions 
    dheap *decheap = new dheap();
    // decVec index
    int i = 0;
    string s = "";
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        //add a space to decVec
        decVec.push_back(decodingInfo());
        //store char in decVec
        decVec[i].c = character;
        // read in the prefix code
        file >> prefix;
        //store bitcode in decVec
        decVec[i].bitcode = prefix;
        // to increase the index of decVec for next char and bitcode if needed
        i++;
        // do something with the prefix code
        // cout << "character '" << character << "' has prefix code '"
        //      << prefix << "'" << endl;
        // to increase the index of decVec for next char and bitcode
    }
    //to test if the decVec has correct values
    for (int i = 0; i < decVec.size(); i++){
        //cout << decVec[i].c << " ";
        //cout << decVec[i].bitcode << endl;
    }

    // huffman is the root of the huffman tree
    node *huffman = new node();
    // to create the huffman tree
    for (int i = 0; i < decVec.size(); i++) {
        huffman = decheap->huffmanDec(huffman, decVec[i].bitcode, decVec[i].c);
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    //print decoded text messages
    decheap->returnDec(huffman, huffman, allbits);
    cout << endl;
    // close the file before exiting
    file.close();
}
