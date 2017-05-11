
#include <iostream>
using namespace std;



int main() {
	int a , b, c , sum = 0;
	int one = 1;
	sum += one;
	
	while (sum != 0){
	cin >> a;
	cin >> b;
	cin >> c;
	sum = a + b + c;
	}
	cout << a << ", " << b << ", " << c << endl;
	return 0;
}

