//Wright Kim
//wdk7bj
//heap.cpp

#include <iostream>
#include <stdlib.h>
#include "heap.h"

using namespace std;

//constructor
heap::heap() {
	node *hNode = new node();
	hNode->freq = -1;
	hNode->c = '#';
	heapVec.push_back(hNode);
}
void heap::insert(node *hnode) {
    // a vector push_back will resize as necessary
    heapVec.push_back(hnode);
    // move it up into the right position
    percolateUp(heapSize());	//origin: heapVec.size()
}

void heap::percolateUp(int heapSize) {
	heapSize -= 1;
	//heapSize = heapVec.size();
    node *tmpNode;
    
    for ( ; (heapSize > 1) && (heapVec[heapSize]->freq < heapVec[heapSize/2]->freq); heapSize /= 2 ) {
    	// if parent's freq is greater than child, swap
    	tmpNode = heapVec[heapSize];
    	heapVec[heapSize] = heapVec[heapSize / 2];
    	heapVec[heapSize / 2] = tmpNode;
    }
}

node* heap::deleteMin() {
	int heapSize = heapVec.size();
    // make sure the heap is not empty
    if ( heapSize == 1 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    node *tmpNode;
    tmpNode = heapVec[1];
    // move the last inserted position into the root
    heapVec[1] = heapVec[(heapSize-1)];
    // make sure the vector knows that there is one less element
    heapVec.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return tmpNode;
}

void heap::percolateDown(int root) {
	int heapSize = heapVec.size() - 1;
    // get the value to percolate down
    node *tmpNode;
    tmpNode = heapVec[root];
    // while there is a left child...
    while ( root*2 <= heapSize ) {
        int child = root*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heapSize) && (heapVec[child+1]->freq < heapVec[child]->freq) )
            child++;
        // if the child is greater than the node...
        if ( tmpNode->freq > heapVec[child]->freq ) {
            heapVec[root] = heapVec[child]; // move child up
            root = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    heapVec[root] = tmpNode;
}

// new node's (internal node) frequency should be 
// the addition of two children's frequency
void heap::huffmanEnc(heap *bheap) {
	int heapSize = bheap->heapSize();
	while (heapSize != 2) {
		node *huffman = new node();
		node *tmpNode;
	
		tmpNode = bheap->deleteMin();
		//cout << tmpNode->freq <<endl;	//working
		huffman->left = tmpNode;
		huffman->freq = tmpNode->freq;
		//cout << huffman->freq << endl;
		huffman->c = '#';
		tmpNode = bheap->deleteMin();
		//cout << tmpNode->freq <<endl;	//working
		huffman->right = tmpNode;
		huffman->freq += tmpNode->freq;
		//cout << huffman->freq << endl;
		bheap->insert(huffman);//automatically insert the huffman node
		heapSize = bheap->heapSize();
	}
}

int heap::heapSize() {
	return heapVec.size();
}
void heap::insertMap(char c, string s) {
	m[c] = s;
}
string heap::bitFromMap(char c) {
	return m[c];
}
void heap::prefix(node *root, string code){
	string zero = "0";
	string one = "1";
	if (root->left == NULL && root->right == NULL) {
		insertMap(root->c, code);
		if (root->c == ' ') {
			cout << "space" << " " << code << endl;
		} else 
		cout<< root->c << " " << code << endl;
		return;
	} 
	if (root->left) 
	prefix(root->left, code+zero);
	if(root->right)
	prefix(root->right, code+one);
	}

