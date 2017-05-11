//Wright Kim
//wdk7bj
//hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <cstring>


using namespace std;

class hashTable{
public:
	hashTable();
	//~hashTable();
	void rehash(unsigned int tableSize, string dictionary, hashTable ht);
	unsigned int hashFunction(string word);
	void insertWord(string filename);
	unsigned int loadFactor(unsigned int tableSize, hashTable ht);
	bool findWord(string word);
	unsigned int sizeOfDic(string filename);

private:
	vector<list<string> > h_table;
	
};

#endif

