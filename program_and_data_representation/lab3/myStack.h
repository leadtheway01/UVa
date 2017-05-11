//Wright Kim
//09/13/15
//myStack.h

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include "stackNode.h"

using namespace std;

class myStack {
public:
	myStack();				//constructor
							//no need to worry copy constructor, destructor
	void push(int x);		//adds amvalue to the top of the stack
	void pop();				//removes a value of the top of the stack
	int top() const;		//returns a value of the top of the stack
	bool empty();			//checks for empty
		
private:
	stackNode *head;		//stackNode object pointer head
	friend class stackNode;
};

#endif