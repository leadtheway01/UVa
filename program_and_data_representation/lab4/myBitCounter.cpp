#include <iostream>
#include <stdlib.h>
using namespace std;

//argc is the number of parameters plus one
//argv is an array of C-stye string. **argv is same as *argv[]

void outputBinary(int ui) {
	int r, i;
	int count = 0;
	
	for (int i = 0; i < 31; i++){	//little endian expression
			r = ui % 2;				//remainder
			cout << r;				//print remainder
			ui = ui / 2;			//divide it by 2
		 if (r ==1){
		 	count++;
		 }
	}
	cout << endl;
	cout << count << endl;
}

int main(int argc, char **argv){
	
    int x;	
	string s(argv[1]);		//cast argv[1] to string value
	x = atoi(s.c_str());	//convert it to int value

	outputBinary(x);
	
	return 0;
}

