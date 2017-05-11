
#include <iostream>
using namespace std;

int returnInt(int i, int j);
int returnIntRef(int &i, int &j);
int main() {
	int i = 1;
	int j = 2;
	returnInt(i, j);			// int i is still 1
	//cout << i << endl;
	returnIntRef(i, j);		// int i is changed to 64
	//cout << i << endl;
	return 0;
}

int returnInt(int i, int j){
	return i + j;
	//cout << i <<endl;
}
int returnIntRef(int &i, int &j){
	return i + j;
	//cout << i <<endl;
}