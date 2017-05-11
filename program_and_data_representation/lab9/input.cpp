
#include <iostream>

using namespace std;

int count(int i);
int main() {
	int i = 0;
	cout << "enter integer" << "\n";
	cin >> i;
	cout << count(i) << endl;
return 0;
}

int count(int i) {
	int counter = 0;
	if (i == 1){

	} else 
	if (i % 2 != 0) {
		i = (2*i + i) +1;
		counter = count(i) + 1;
	} else {
		i = i /2;
		counter = count(i) + 1;
	}
	return counter;
}