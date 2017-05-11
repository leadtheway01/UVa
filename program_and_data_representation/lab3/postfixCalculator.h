//Wright Kim
//09/13/15
//postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

//#include <stack>
#include "myStack.h"
#include <cstdlib>
using namespace std;

class postfixCalculator {
public:
	//constructor
	postfixCalculator();

	void add();
	void subtract();
	void multiple();
	void division();
	void negate();
	void pushNum(int i);
	int getTopValue();

private:
	myStack s;
};


#endif