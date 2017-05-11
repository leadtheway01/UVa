//Wright Kim
//09/13/15
//stackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
using namespace std;

class stackNode{

public:
	stackNode();

private:
	int value;
	stackNode *next;
	
	friend class myStack;
};

#endif