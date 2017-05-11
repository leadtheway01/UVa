//Wright Kim 
//wdk7bj
//huffmanenc.cpp
#include <iostream>	// need for cout
#include <stdlib.h>	// need for exit()
#include <stdio.h>	// need for standard I/O
#include <vector>	// need to use vector
#include "heap.h"

using namespace std;

int main (int argc, char **argv) {
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file.  FILE is a type desgined to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit    
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }
    // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file. 

    // to store number of frequency of each char
    struct numberOfChar {
    	char c;
    	int count;
    };

    // vector to store number of frequency of each char
    vector<numberOfChar> frequency;
    frequency.push_back(numberOfChar());
    int i = 0;
    int j = 1;
    int k = 1;
    char g;

    // get frequecy of each char
    while ( (g = fgetc(fp)) != EOF ) {
        // to reset k to 0 when while starts
        k=1; 
        // to check if char is in the vector
        for (j = 1; j < frequency.size(); j++) {
            if ( g != frequency[j].c && g != '\n' && g != '\t' && g != '\r') {
                k++;
            }
        }

        // insert char to vector
        // to increase the size of vector by one
        // store char in vector and initializes number of frequency
        if(k == frequency.size()){
            // increments the size of the vector
            frequency.push_back(numberOfChar());
            // stores the char in vector   
            frequency[k].c = g;
            // initializes number of frequency 
            frequency[k].count = 0;
        }
        // to increment number of frequency by 1 if char is in vector
        for ( i = 0; i < frequency.size(); i++ ) {
            if ( g == frequency[i].c ) {
                frequency[i].count += 1;
                break;
            } 
        }  
    }

// copies the frequency and unique char to heap
heap *bheap = new heap();

for ( i = 1; i < frequency.size(); i++) {
      node *hNode = new node();
      hNode->c = frequency[i].c;
      hNode->freq = frequency[i].count;
      hNode->left = NULL;
      hNode->right = NULL; 
      bheap->insert(hNode); // to use vector<node*> heapVec
}
// to find distinct symbols in text file
int sizeOfHeap = bheap->heapSize()-1;


// to find total bits in file
vector<numberOfChar> original;
original.push_back(numberOfChar());
rewind(fp);
int totalBits = 0;
while ( (g = fgetc(fp)) != EOF ) {
    if (g != '\n' && g != '\t' && g != '\r')
    totalBits++;
}

// to create huffman tree
 bheap->huffmanEnc(bheap);


// This is the cout part
node* huffman = bheap->deleteMin();
string Code ="";
bheap->prefix(huffman, Code);
cout << "----------------------------------------" << endl;
//read the text file from the beginning again
rewind(fp);
//to count all of the bit of the text file
string bitCount;
while ( (g = fgetc(fp)) != EOF ) {
    char c = g;
    cout << bheap->bitFromMap(c) << " ";
    bitCount += bheap->bitFromMap(c);
}

double bitSize = bitCount.length(); //value is 13
cout << "\n" << "----------------------------------------" << endl;       
cout << "There are a totla of " << huffman->freq << " symbols that are encoded." << endl;
cout << "There are " << sizeOfHeap << " distinct symbols used." << endl;
cout << "There were " << totalBits * 8 << " bits in the original file." << endl;
cout << "There were " << bitSize << " bits in the compressed file." << endl;
cout << "This gives a compression ratio of " << (totalBits * 8) / bitSize << "." << endl;
cout << "The cost of the Huffman tree is " <<bitSize / huffman->freq << " bits per character." <<endl;
// close the file
fclose(fp);
return 0;
}
