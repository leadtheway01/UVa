//Wright Kim
//wdk7bj
//node.h

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class node {
public:
	node();
	char c;
	int freq;
	node *left, *right;
};

#endif