//Wright Kim
//wdk7bj
//dnode.h

#ifndef DNODE_H
#define DNODE_H

#include <iostream>
using namespace std;

class node {
public:
	node();
	string s;
	string bitcode;
	node *left, *right;
};

#endif