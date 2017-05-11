//Wright Kim
//wdk7bj
//getWordInTable.cpp

/** This file defines and demonstrates two necessary components for
 * the hash table lab for CS 2150.  The first is the use of the
 * getWordInTable() function, which is used for retrieving a word in a
 * grid of letters in one of the cardinal 8 directions (north,
 * south-east, etc).  The second is the use of file streams to read in
 * input from a file, specifically one formatted as per the lab 6
 * guidelines.
 *
 * Written by Aaron Bloomfield, 2009
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

// We create a 2-D array of some big size, and assume that the table
// read in will be less than this size (a valid assumption for lab 6)



/** The main() function shows how to call both the readInTable()
 * function as well as the getWordInTable() function.
 */
/* 
int main() {
    // to hold the number of rows and cols in the input file
    int rows, cols;
    // attempt to read in the file
    bool result = readInTable ("5x8.grid.txt", rows, cols);
    // if there is an error, report it
    if ( !result ) {
        cout << "Error reading in file!" << endl;
        exit(1); // requires the <stdlib.h> #include header!
    }
    // Get a word (of length 10), starting at position (2,2) in the
    // array, in each of the 8 directions
    cout << endl;
    for ( int i = 0; i < 8; i++ )
        cout << i << ": " << getWordInTable(2,2,i,10,rows,cols) << endl;
    // All done!
    return 0;
}
*/


/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global table[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */



/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char table[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The length of the string to return (assuming the edge of
 *            the grid is not reached).
 * @param numRows The number of rows in the global char table[][]
 *                array .
 * @param numCols The number of columns in the global char table[][]
 *                array.
 */


unsigned int sizeOfDic(string filename){
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