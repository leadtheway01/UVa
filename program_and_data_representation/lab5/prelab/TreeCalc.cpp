// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations
//Wright Kim
//wdk7bj
//TreeCalc.cpp
#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <cstdlib>
//#include <cctype>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
    cleanTree(mystack.top());
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if(ptr != NULL){
    cleanTree(ptr->left);      //recursivly delete left children   
    cleanTree(ptr->right);     //recursivly delete right children
    delete ptr;
    }
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode *treeNode = new TreeNode(val);         //create new node that passes val which is a reference value
    
    bool check = isdigit((treeNode->value)[0]);         //to check whether the reference value is int or operator
    if((treeNode->value).size() > 1){
        check = true;
    }
    if(check == false){                             //chcek if passed reference value is an operator
        TreeNode *new_treeNode = new TreeNode((treeNode->value));
        TreeNode *x = mystack.top();                //get the very top value
        mystack.pop();                              //remove that value from stack
        TreeNode *y = mystack.top();                //get next top value
        mystack.pop();                              //remove that value from stack

        new_treeNode->value = treeNode->value;      //set new treeNode value to the current value
        new_treeNode->left = y;                     //x is the left child                    
        new_treeNode->right = x;                    //y is the right child
        mystack.push(new_treeNode);                 //push new treeNode back to stack
} else if(check == true){                           //check if passed reference value is integer
    mystack.push(treeNode);                         //push the integer value to the stack mystack
} else exit(0);
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
    if(ptr != NULL){                     
        cout << (ptr->value) << " ";          
        printPrefix(ptr->left);                   
        printPrefix(ptr->right);
    }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
    if(ptr!= NULL){
        if(ptr->left != NULL) cout << "( ";
        printInfix(ptr->left);
        cout << (ptr->value) << " ";
        printInfix(ptr->right);
        if(ptr->right != NULL) cout << ") ";
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
    if(ptr!= NULL){
        printPostfix(ptr->left);
        printPostfix(ptr->right);
        cout << (ptr->value) << " "; 
    }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
        printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
        printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
        printPrefix(mystack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
    bool check = isdigit((ptr->value)[0]);         //to check whether the reference value is int or operator
    if((ptr->value).size() > 1){                   
        check = true;
    }
    if(check){
        return atoi(ptr->value.c_str());

    } else{
            if(ptr->value == "+"){
                return calculate(ptr->left) + calculate(ptr->right);
            }
            else if(ptr->value == "-"){
                return calculate(ptr->left) - calculate(ptr->right);
            } 
            else if(ptr->value == "*"){
                return calculate(ptr->left) * calculate(ptr->right);
            } 
            else if(ptr->value == "/"){
                return calculate(ptr->left) / calculate(ptr->right);
            }
            else exit(0);
//what if final result is not an interger?
    }
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    i = calculate(mystack.top());
    return i;
}
