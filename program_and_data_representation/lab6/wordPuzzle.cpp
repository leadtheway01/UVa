//Wright Kim wdk7bj
//date
//CS2150 - 104
//wordPuzzle.cpp

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>


#include "hashTable.h"
#include "timer.h"
#include "tableSize.h"
using namespace std;


//dictionary, grid filenames are passed as command line arguments
int main(int argc, char* argv[]){
	if(argc < 2){	//if there is no command line arguments, exit the program
		cout << "no command line arguments." << endl;
		cout << "exiting the program." << endl;
		exit(1);
	} else {		//if dictionary and grid filename as command line arguments
		string dictionary(argv[1]);		//dictionary filename converted to c++ style string
		string grid(argv[2]);			//grid filename converted to c++ style string

		vector <list<string> > h_Table = new vector<list<string>>(tablesize); 
		//table size should be prime
		unsigned int tableSize;
		if(checkprime(sizeOfDictionary(dictionary)) == false){
			return tableSize = getNextPrime(sizeOfDictionary(dictionary));
		}else {
			return tableSize = sizeOfDictionary(dictionary);
		}
		
		

		h_Table.insertWordtoHTable(dictionary, h_Table);			//to insert all of the words in the dictionary file to thte vector and list

		bool result = readInTable(dictionary, rows, cols);

		timer t = new timer();
		t.start();	
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				for(int d = 0; d < 8; d++){
					for(int l = 0; l < len; l++){
						char *word = getWordInTable(i, j, d, l, rows, cols);
						if(find(begin(insertWordtoHTable(dictionary, h_Table)), end(insertWordtoHTable(dictionary, h_Table)), word)){
							return word;
						}
					}
				}
			}
		}
		t.stop();
		int tot = t.getTime();

	}

	return 0;
}

