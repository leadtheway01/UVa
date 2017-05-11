
#include <iostream>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int i);

int main() {
	int i, j = 0;
	double tot, n = 0;
	timer *t = new timer();

	cout << "enter integer: ";
	cin >> i;
	cout << "enter number of times to call subroutines: ";
	cin >> n;
	cout << "\n";

	// to time the subroutines
	t->start();
	for (j = 0; j < n; j++) {
		threexplusone(i);
	}
	t->stop();

	tot = t->getTime();
	tot /= n;				// to get the average time
	cout << "Total number of steps: " << threexplusone(i) << "\n";
	cout << "Average time for each subroutines: " << tot << " seconds" << endl;
return 0;
}