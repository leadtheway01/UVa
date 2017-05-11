

#include <iostream>
using namespace std;

int returnPointer(int *p, int *q);
int returnPointerRef(int &p, int &q);
int main() {
	int temp = 1;
	int temp1 = 2;
	int *p;
	int *q;
	p = &temp;
	q = &temp1;
	//cout << *p << endl;
	//cout << temp << endl;
	returnPointer(p, q);	
	//cout << *p << endl;
	//cout << temp << endl;
	returnPointerRef(*p, *q);
	//cout << *p << endl;
	//cout << temp << endl;
	return 0;
}

int returnPointer(int *p ,int *q) {
	return *p + *q;
}
int returnPointerRef(int &p, int &q) {
	return p + q;
	
}