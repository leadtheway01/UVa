
#include <iostream>
using namespace std;

char returnChar(char c, char d);
char returnCharRef(char &c, char &d);
int main() {
	char c = 34;
	char d = 31;
	returnChar(c, d);		// char c is still 'a'
	//cout << c << endl;
	
	returnCharRef(c, d);	// char c is now changed to A
	//cout << c << endl;	
	return 0;
}
char returnChar(char c, char d) {
	return c + d;
	//cout << c << endl;
}
char returnCharRef(char &c, char &d) {
	return c + d;
	//cout << c << endl;
}