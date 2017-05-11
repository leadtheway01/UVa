
#include <iostream>
#include "object.h"
#include "test.h"

using namespace std;

int main() {
	object ob, ob2;

	ob.i = 1;
	ob.c = 'A';
	ob.f = 2.1;
	ob.d = 3.1;

	ob.your.height = 6;
	ob.your.weight = 180;

	ob.set(5);
	ob2.set(10);
	ob.get();

	
	return 0;
}