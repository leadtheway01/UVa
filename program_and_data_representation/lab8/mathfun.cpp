//Wright Kim
//wdk7bj
//mathfun.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product(int x, int y);
extern "C" int power(int x, int y);


int main() {
	int x, y = 0;
	int prod, po;

	cout<< "Please enter first integer: " << "\n";
	cin >> x;
	cout << "Please enter second integer: " << "\n";
	cin >> y;

	prod = product(x, y);
	po = power(x, y);

	cout << "product(x, y): " << prod << "\n";
	cout << "power(x, y): " << po << "\n";

	return 0;
}
