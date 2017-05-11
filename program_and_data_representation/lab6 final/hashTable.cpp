//Wright Kim
//wdk7bj
//hashTable.cpp

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <string>
#include "hashTable.h"


using namespace std;

hashTable::hashTable(){
	h_table.resize(301);
}

//different hashfunction used is at the end of this file
unsigned int hashTable::hashFunction(string word){	//c++ style string word
  int key = 0;

	key = word.length();
	return key % (h_table.size()+1);
    
}

void hashTable::insertWord(string filename){
	string word;
	ifstream file(filename.c_str());
	//list<string> temp;
	
	if( !file.is_open() ) {
		cout << "error" <<endl;
		exit(0);
	}else {
		
 		for (int i = 0; i < sizeOfDic(filename); i++){
			getline(file, word);
			int val = hashFunction(word);
												//store first line of the file to string word
				if(word.length() >= 3){			
						h_table[val].push_back(word);
				
				/*
				for (int i = 3; i < word.length(); i++){
					string temp = word.substr(0, i);				//add one letter to the key
					h_table[ht.hashFunction(word, ht)].push_back(temp);			//push to the list where the key is stored
				}
				*/
			}
		}
	}
	file.close();
}

void hashTable::rehash(unsigned int tableSize, string dictionary, hashTable ht){
	h_table.resize(2*tableSize);
	//vector<list<string> > h_table_new = new vector<list<string> >(2*tableSize);
	insertWord(dictionary);
	
}

/*
unsigned int loadFactor(unsigned int tableSize, hashTable ht){
	return h_table.size() / tableSize;
}
*/

bool hashTable::findWord(string word){
	int val = hashFunction(word);

	list<string> temp = h_table[val];
	list<string>::iterator it = temp.begin();
		while (it != temp.end()){
			if(find(temp.begin(), temp.end(), word) != temp.end()){
				return true;
			}
			it++;
		}
		
	return false;
}

unsigned int hashTable::sizeOfDic(string filename){
    string word;
    int count = 0;

    ifstream file(filename.c_str());         //set up the file stream to read in the file (takes in a C-style char *string, not a C++ style string object)
    if( !file.is_open() ){
        exit(0);
    }

    while( file >> word ){
        count++;
    }
    file.close();
    return count;
}

//hashfunction #1
/*
unsigned int hashTable::hashFunction(string word){	//c++ style string word
	
	int key = 0;

	key = word.length() * pow(37, word.length());
	return key % (h_table.size()+1);
}

hashfunction #2 DJB2
unsigned int hashTable::hashFunction(string word){	//c++ style string word
  unsigned long hash = 5381;
  int c;
  while ((c = word.length()) != 0)
    hash = ((hash << 5) + hash) + c;
  return hash;
	
}

hashfunction #3
unsigned int hashTable::hashFunction(string word){	//c++ style string word
  int key = 0;

	key = word.length();
	return key % (h_table.size()+1);
    
}
*/