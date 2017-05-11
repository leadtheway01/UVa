//Wright Kim
//wdk7bj
//09/23/15
//inlab4.cpp

#include <iostream>
#include <climits>
using namespace std;

union data {
	int i;
	unsigned int ui;
	float f;
	int *ip;
};

void outputBinary(unsigned ui) {

	int r, i;
	int count = 0;
	int out[32];
	for (int i = 0; i < 31; i++){
			r = ui % 2;				//remainder
			//cout << r;			//print remainder
			out[i] = r;
			ui = ui / 2;			//divide it by 2
		 //ui = ui >> 2;			//same as dividing by 2
	}
	for (i = 31; i >= 0; i--){		//to print binary 
		cout << out[i];				
		count++;					//counting
			if (count % 4 == 0){	//print space for every 4 count
				cout << " ";
			}
	}
	cout << endl;
	cout << endl;
}

// In-Lab Size of c++ data types 4 byte
/*
int main() {
	data Data;
	float fl;
	unsigned int ui;
	int i;
	//double d;
	//double *dp;
	//bool b;
	cout << "enter an integer to convert to binary: ";
	cin >> fl;
	Data.f = fl;
	//cout << sizeof(b) <<endl;
	//sizeOfTest();
	outputBinary(Data.ui);		//need to change to ui because outputbinary only takes unsigned int
	//overflow();
	return 0;
}
*/

//In-lab Size of c++ data types, others
/*
int main() {

	double d = 0.0;			

	char c = '0';			

	bool b = false;				

	int *ip = NULL;			

	char *cp = NULL;			

	double *dp = NULL;		

	cout << c << endl;

}
*/

//In-Lab Representation in memory
/*
int main() {
	bool b = true;
	char c = '1';
	int i = 1;
	double d = 1.0;
	int *ip = NULL;

	cout << b << " " << c << " " << i << " " << d << " " << *ip << endl;
	return 0;
}
*/

//In-Lab Primitive Array in c++

int main(){
	int IntArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	char CharArray[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'a'};

	int IntArray2D[6][5] = {1, 2, 3, 4, 5,
							6, 7, 8, 9, 10,
							11, 12, 13, 14, 15,
							16, 17, 18, 19, 20,
							21, 22, 23, 24, 25,
							26, 27, 28, 29, 30
							};

	char CharArray2D[6][5] = {'1', '2', '3', '4', '5',
							  '6', '7', '8', '9', 'a',
							  'b', 'c', 'd', 'e', 'f',
							  'g', 'h', 'i', 'j', 'k',
							  'l', 'm', 'n', 'o', 'p',
							  'q', 'r', 's', 't', 'u'
							};

	return 0;
}

