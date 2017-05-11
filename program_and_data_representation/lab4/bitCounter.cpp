//Wright Kim
//wdk7bj
//09/25/15
//bitCounter.cpp

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

void counter(int i, int count){
	int x = i;						//x is the input value
	int c = count;					//c is to count 1
	if(x == 0){						//base case
		cout << c << endl;
	} else if(x % 2 == 0){			//even
		 counter(x / 2, c);			

	} else if (x % 2 != 0){			// odd
		counter(x / 2, c + 1);
	}
}

int main(int argc, char **argv){

	if (argc !=2){
		cout << "there is an error" << endl;
		return -1;
	}

	int i;
	
	string s(argv[1]);		//cast argv[1] to string value
	i = atoi(s.c_str());	//convert it to int value

	counter(i, 0);

	return 0;
}

