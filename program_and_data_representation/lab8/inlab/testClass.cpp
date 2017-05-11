

#include <iostream>
#include "test.h"

using namespace std;

void returnYour(testCase your);
void returnYourRef(testCase &your);
int main() {
	testCase your;
	your.height = 6.0;
	your.weight = 170.5;
	returnYour(your);
	//cout << your.height << "\n" << your.weight <<endl;
	returnYourRef(your);
	//cout << your.height << "\n" << your.weight <<endl;
	return 0;
}
void returnYourRef(testCase &your){
	your.height = 5.3;
	your.weight = 200.5;
	//cout << your.height << "\n" << your.weight << endl;
}
void returnYour(testCase your){
	your.height = 5.0;
	your.weight = 200.0;
	//cout << your.height << "\n" << your.weight << endl;
}