
#include <iostream>
#include "test.h"
using namespace std;

void returnInt(int i);
void returnChar(char c);
void returnfloat(float f);
void returnPointer(int *p);
void returnIntRef(int &i);
void returnArray(int array[]);
void returnYour(testCase your);
void returnYourRef(testCase &your);
int main() {

	int i = 1;
	returnInt(i);
	cout << i << endl;
	returnIntRef(i);
	cout << i << endl;

	char c = 'a';
	returnChar(c);

	float f = 1.0;
	returnfloat(f);

	int temp = 1;
	int *p;
	p = &temp;
	cout << *p << endl;
	returnPointer(p);

	int array[] = {1, 2, 3};
	cout << array[0] << endl;
	returnArray(array);

	testCase your;
	your.height = 6.0;
	your.weight = 170.5;
	returnYour(your);
	cout << your.height << "\n" << your.weight <<endl;
	returnYourRef(your);
	cout << your.height << "\n" << your.weight <<endl;
	return 0;
}
void returnYourRef(testCase &your){
	your.height = 5.3;
	your.weight = 200.5;
	cout << your.height << "\n" << your.weight << endl;
}
void returnYour(testCase your){
	your.height = 5.0;
	your.weight = 200.0;
	cout << your.height << "\n" << your.weight << endl;
}
void returnArray(int array[]){
	array[0] = 63;
	cout << array[0] << endl;
}
void returnInt(int i){
	i = 64;
	cout << i <<endl;
}
void returnIntRef(int &i){
	i = 64;
	cout << i <<endl;
}
void returnChar(char c){
	c = 65;
	cout << c << endl;
}
void returnfloat(float f){
	f = 66.0;
	cout << f << endl;
}
void returnPointer(int *p) {
	int temp = 67;
	*p = temp;			//p = &temp same thing
	cout << *p << endl;
}