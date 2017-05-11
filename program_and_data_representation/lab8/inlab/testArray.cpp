
#include <iostream>
using namespace std;

int returnArray(int array[]);
int returnArrayRef(int *array);
int main() {
	int array[] = {1, 2};
	//cout << array[0] << endl;
	returnArray(array);
	//cout << array[0] << endl;
	returnArrayRef(array);
	//cout << array[0] << endl;
	return 0;
}

int returnArray(int array[]){
	return array[0] + array[1];
	//cout << array[0] << endl;
}
int returnArrayRef(int *array) {
	return array[0] + array[1];
	//cout << array[0] << endl;
}
//can't pass array as a value to subroutine in c or c++
//