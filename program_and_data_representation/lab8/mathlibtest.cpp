
#include <iostream>
#include <cmath>
using namespace std;

int product(int x, int y);
int power(int x, int y);

int main(){
	int x = 0;
	int y = 0;
	cout << "enter two integer numbers: " << "\n";
	cin >> x;
	cin >> y;

	cout << product(x, y) <<"\n";
	cout << power(x, y) << "\n";
}

int product(int x, int y){
	int retVal = 0;
	int i = 0;
	while( i < y){
		retVal+=x;
		i++;
	}
	//for (int i = 0; i < y; i++) {
	//	retVal+=x;
	//}
	return retVal;
}

int power(int x, int y) {
	int retVal;
	if (y == 0) {
		retVal = 1;
	} 
	else {
		retVal = x*power(x,y-1);
	}
	return retVal;
}