//Wright Kim
//wdk7bj
//wordPuzzle.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>

#include "primenumber.h"
#include "hashTable.h"
#include "timer.h"

using namespace std;
#define MAXROWS 500
#define MAXCOLS 500

char table[MAXROWS][MAXCOLS];
bool readInTable (string filename, int &rows, int &cols);
char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols);


int main(int argc, char* argv[]) {
	/*
	if(argc < 2){
		cout << "error" <<endl;
	} 
	*/
	string dictionary(argv[1]);			//dictionary filename converted to c++ string from c string and stored at string dictionary 
	string	grid(argv[2]);				//grid filename converted to c++ string from c string and stored at string grid
	
	hashTable ht;										//to instantiate hashTable class


	string rows, cols;
	ifstream file(grid.c_str());
	getline(file, rows);									//first line of grid file is row
	getline(file, cols);									//second line of grid file is col

	int row = atoi(rows.c_str());							//convert string row to int
	int col = atoi(cols.c_str());							//convert string col to int
	bool result = readInTable(grid, row, col);				//read in grid

	ht.insertWord(dictionary);	
	timer t;
	int count = 0;
	int i = 0;
	int j = 0;
	int d = 0;
	int l = 0;
	int length = 0;
	t.start();
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			for(d = 0; d < 8; d++){
				if(row < col){
					length = col;
				}else {
					length = row;
				}
					for (l = 0; l < length; l ++){
						char *word = getWordInTable(i, j, d, l, row, col);
						string word1(word);
							if(word1.length() != l){
								break;
								}
					if(ht.findWord(word1)){
								count++;

								if(d == 0){
								cout << "N" << "(" << i << ", " << j << ")" << "\t" << word1 << "\n";
								}else if (d == 1){
								cout << "NE" << "(" << i << ", " << j << ")" << word1 << "\n";
								}else if (d ==2){
								cout << "E" << "(" << i << ", " << j << ")" << "\t" << word1 << "\n";
								}else if (d == 3){
								cout << "SE" << "(" << i << ", " << j << ")" << word1 << "\n";
								}else if (d == 4){
								cout << "S" << "(" << i << ", " << j << ")" << "\t" << word1 << "\n";
								}else if (d == 5){
								cout << "SW" << "(" << i << ", " << j << ")" << word1 << "\n";
								}else if (d == 6){
								cout << "W" << "(" << i << ", " << j << ")" << "\t" << word1 << "\n";
								}else if (d == 7){
								cout << "NW" << "(" << i << ", " << j << ")" << word1 << "\n";
								}
	
							}
						}
				}
			}
		}
	
	t.stop();
	double tot = t.getTime();
	cout << count << " words found" <<endl;
	cout << "Found all words in " << tot << " seconds" << endl;
    return 0;
}//main

char* getWordInTable (int startRow, int startCol, int dir, int len,
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

bool readInTable (string filename, int &rows, int &cols) {
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

