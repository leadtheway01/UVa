//Wright Kim
//wdk7bj
//heap.h

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"
using namespace std;

class heap {
public:
	heap();
	void insert(node *hNode);
	void percolateUp(int heapSize);
	node* deleteMin();
	void percolateDown(int root);
	void huffmanEnc(heap *hNode);
	int heapSize();
	void prefix(node* root, string code);
	void insertMap(char c, string s);
	string bitFromMap(char c);
	
private:
	vector<node *> heapVec;
	map<char, string> m;
};


#endif