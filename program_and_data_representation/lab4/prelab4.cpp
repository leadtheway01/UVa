//Wright Kim wdk7bj
//09/22/2015
//prelab4.cpp

#include <iostream>
#include <climits>

using namespace std;

void sizeOfTest() {
	int i;				//4byte
	unsigned int ui;	//4byte
	float f;			//4byte
	double d;			//8byte
	char c;				//1byte
	bool b;				//1byte
	int *ip;			//4byte
	char *cp;			//1byte
	double *dp;			//8byte

	cout << sizeof i << endl;
	cout << sizeof ui << endl;
	cout << sizeof f << endl;
	cout << sizeof d << endl;
	cout << sizeof c << endl;
	cout << sizeof b <<endl;
	cout << sizeof *ip <<endl;
	cout << sizeof *cp << endl;
	cout << sizeof *dp << endl;
	cout << endl;
}

void outputBinary(unsigned int ui) {
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

void overflow() {
	unsigned int ui;
	ui = UINT_MAX + 1;
	cout << ui << endl;
	cout << "since the max value is 11...11,  if 1 is added, "
	<< "the max value becomes 0 with an overflow" <<endl;
}

//testing
int main() {
	unsigned int x;
	cout << "enter an integer to convert to binary: ";
	cin >> x;

	sizeOfTest();
	outputBinary(x);
	overflow();
	return 0;
}
