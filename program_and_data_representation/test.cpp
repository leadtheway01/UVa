
#include <iostream>
using namespace std;

// int main() {
// 	char *c;
// 	*c = 'A';
// 	//delete c;
// 	cout << c << endl;
// 	return 0;
// }

// class foo {
// public:
// 	int *p;
// };

// int main() {
// 	foo *f = new foo();
// 	int arr[] = {42};
// 	f->p = &arr[0];
// 	cout << *(f->p) << endl;
// 	return 0;
// }

// union {
// 	float f;
// 	int i;
// 	double *p;
// } bar;

// int main() {
// 	//bar.i = -234;
// 	bar.f = -35.5;
// 	cout << bar.i << endl;
// 	cout << bar.p << endl;
// 	cout << sizeof(bar) << endl;
// 	return 0;
// }

// union {
// 	float f;
// 	unsigned int i;
// } bar;

// int main() {
// 	bar.i = 0xc2ad0000;
// 	cout << bar.i << endl;
// 	cout << bar.f << endl;
// 	cout << sizeof(bar) << endl;
// 	return 0;
// }

int main(){
	int *i = NULL;
	cout << *i << endl;
}