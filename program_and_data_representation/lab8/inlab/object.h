

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "test.h"
using namespace std;

class object {
public:
	int i;
	char c;
	float f;
	double d;
	testCase your;
	
	int get();
	void set(int i);
	
private:
	int a;
};

#endif