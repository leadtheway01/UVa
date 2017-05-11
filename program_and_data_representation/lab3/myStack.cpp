//Wright Kim
//09/13/15
//myStack.cpp

#include "postfixCalculator.h"
#include "myStack.h"
#include "stackNode.h"
#include <cstdlib>
#include <iostream>
using namespace std;

myStack::myStack(){

}

void myStack::push(int x){
	stackNode *temp = new stackNode();
	temp -> next = head -> next;
	head -> next = temp;
	temp -> value = x;
}

void myStack::pop(){
	stackNode *temp;
	temp = head -> next;
	head -> next = (head -> next) -> next;
	delete temp;
}

int myStack::top() const{
	
	return (head -> next) -> value;
}

bool myStack::empty(){
	if(head -> next == NULL){ //if temp's next is pointing NULL, it is empty
		return true;
	} else {
		return false;
	}
}