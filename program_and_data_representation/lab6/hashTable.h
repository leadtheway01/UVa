
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>

#include "timer.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char table[MAXROWS][MAXCOLS];

class hashTable{
	public:
		unsigned int key;
		unsigned int value;
		bool readInTable (string filename, int &rows, int &cols);
		
		char* getWordInTable (int startRow, int startCol, int dir, int len,
                      		  int numRows, int numCols);
		void insertWordToHTable (string filename, vector<list<string> > h_Table);
		unsigned int loadFactor(unsigned int tableSize);

		void rehash(unsigned int tableSize);
		unsigned int hashFunction(string word);
		int getNextPrime (unsigned int n);
		bool checkprime(unsigned int p);

	private:
		vector<list<string> > h_Table;
		list<string> h_list;
};






#endif
