//Wright Kim
//wdk7bj
//dheap.h

#ifndef DHEAP_H
#define DHEAP_H

#include <vector>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include "dnode.h"
using namespace std;

class dheap {
public:
	dheap();
	node* huffmanDec(node *root, string prefix, string character);
	node *returnDec(node *root, node *huffman, string allbits);
};

#endif