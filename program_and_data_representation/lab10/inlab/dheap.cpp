//Wright Kim
//wdk7bj
//dheap.cpp

#include <iostream>
#include <stdlib.h>
#include "dheap.h"

using namespace std;

//constructor
dheap::dheap() {
	node *dNode = new node();
	dNode->bitcode = "";
	dNode->s = "";
}

// to create huffman tree
node *dheap::huffmanDec(node* root, string prefix, string character) {
	node* huffman = root;

	//cout << prefix << endl;
		// if first char of prefix is 0, go left
		if ( prefix.at(0) == '0') {
			//create internal node
			node *leftChild = new node();
			//copy and replace the left child node to new node
			if (root->left != NULL) {
				leftChild = root->left;
			}
			// if left child is null, add left child node
			root->left = leftChild;
			//remove first character from prefix
			prefix.erase(prefix.begin());
			//when reach leaf
			if (prefix.length() == 0) {
				leftChild->left = NULL;
				leftChild->right = NULL;
				leftChild->s = character;
				return huffman;
			}
			//at internal node, call recursively
			huffmanDec(leftChild, prefix, character);
		}  else { 
			//create internal node
			node *rightChild = new node();
			//copy and replace the right child node to new node
			if (root->right != NULL) {
				rightChild = root->right;
			}
			// if right child is null, add right child node
			root->right = rightChild;
			//remove first character from prefix
			prefix.erase(prefix.begin());
			//when reach leaf
			if (prefix.length() == 0) {
				rightChild->left = NULL;
				rightChild->right = NULL;
				rightChild->s = character;
				return huffman;
			}
			//at internal node, call recursively
			huffmanDec(rightChild, prefix, character);
		}
	return huffman;
}

// to print decoded text
node* dheap::returnDec(node* root, node *huffman, string allbits) {
	//if first char is 1, go right
	if (allbits.at(0) == '1') {
		//at leaf
		if (root->right->left == NULL && root->right->right == NULL) {
			//print char
			cout << root->right->s;
			//remove first char from allbits
			allbits.erase(allbits.begin());
			//while there is bits, call recursively
			if (allbits.length() != 0){
				returnDec(huffman, huffman, allbits);
			} else {
				return huffman;
			}
		} else { //at internal node
			//remove first char from allbits
			allbits.erase(allbits.begin());
			//at internal node, call recursively
			returnDec(root->right, huffman, allbits);
		}
	} else { //if first char is 0, go left
		// at leaf
		if (root->left->left == NULL && root->left->right == NULL) {
			cout <<root->left->s;
			//remove first char from allbits
			allbits.erase(allbits.begin());
			//while there is bits, call recursively
			if (allbits.length() != 0) {
				returnDec(huffman, huffman, allbits);
			} else {
				return huffman;
			}
		} else { //at internal node
			//remove first char from allbits
			allbits.erase(allbits.begin());
			//at internal node, call recursively
			returnDec(root->left, huffman, allbits);
		}
	}
	return huffman;
}

