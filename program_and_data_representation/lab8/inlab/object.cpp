
#include <iostream>
#include "object.h"

using namespace std;

int object::get() {
	return a;
}
void object::set(int i) {
	this->a = i;
}
