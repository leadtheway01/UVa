//Wright Kim
//09/13/15
//postfixCalculator.cpp

#include "postfixCalculator.h"
//#include <stack>
#include "myStack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//constructor
postfixCalculator::postfixCalculator(){
	
}

void postfixCalculator::add(){
	int x = s.top();		//stores the top value to x
	s.pop();				//removes x from stack
	int y = s.top();		//removes the next top value to y
	s.pop();				//removes y from stack
	int z = x + y;			//add x and y2
	s.push(z);				//push x + y = z to stack
}

void postfixCalculator::subtract(){
	int x = s.top();		//stores the top value to x
	s.pop();				//removes x from stack
	int y = s.top();		//stores the next top value to y
	s.pop();				//removes y from stack
	int z = y - x;			//subtract, z = x - y
	s.push(z);				//push z to stack
}

void postfixCalculator::multiple(){
	int x = s.top();		//stores the top value to x
	s.pop();				//removes x from stack
	int y = s.top();		//stores the next top value to y
	s.pop();				//removes y from stack
	int z = x * y;			//multiplication, z = x * y
	s.push(z);				//push x to stack
}

void postfixCalculator::division(){
	int x = s.top();		//stores the top value to x
	s.pop();				//removes x from stack
	int y = s.top();		//stores the next top value to y
	s.pop();				//removes y from stack
	int z = y / x;			//division, z = x / y
	s.push(z);				//push z to stack
}

void postfixCalculator::negate(){
	int x = s.top();		//stores the top value to x		
	s.pop();				//removes x from stack
	x = -x;					//negation, x = -x
	s.push(x);				//push x to stack
}

void postfixCalculator::pushNum(int i){
	s.push(i);				//push i value to stack
}

int postfixCalculator::getTopValue(){
	return s.top();			//returns top of stack
}