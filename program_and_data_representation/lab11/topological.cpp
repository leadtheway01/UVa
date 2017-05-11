
 /** \file topological.cpp
 * \details This program sorts classes in topological order
 * \author Wright Kim (wdk7bj)
 * \date 11/30/2015
 */

// included so we can use cout
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

/** @brief stores values
 *
 * Node class is to store string, interger, and Node type pointer values
 */ 
class Node {
public:
    Node();
    /*!to store class name*/
    string name; 
    /*!to store indegree value*/
    int indegree;
    /*!to store Node type pointer to point next node*/
    Node *next; 
};

/** @brief Node constructor
 *
 * This is a Node constructor to initialize values of Node object
 */
Node::Node() {
    /*!name = ""; to initialize string type name*/
    name = "";
    /*!indegree = 0; to initialize int type indegree*/
    indegree = 0;
    /*!next = NULL; to initialize Node type pointer next*/
    next = NULL;
}
//to return node inside vector with indegree0
/**@brief to return node with indegree value of 0
 *@return returns the node tht has indegree value of 0
 *@param vec vector of Node*
 */
Node* indegree0 (vector<Node*> vec) {
    int i = 0;
    /*!checks all of the vector's indegree values*/
    for (i = 0; i < vec.size(); i++){
        /*!if vector's node's indegree is 0, return that node*/
        if (vec[i]->indegree == 0){
            return vec[i];
        }
    } 
}

// we want to use parameters
/**@brief to do topological sort
 *
 * This is the main function
 *
 * Main function does 3 operation 
 * 1. stores all of the unique class names
 * 2. stores the direction edge of each class
 * 3. prints class in topological order
 */
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    
    vector<Node*> vec;


    string s1, s2;

    while (s1 != "0" && s2 != "0" ) {
    // index to determine whether increase the size of topinfo vector
    int k = 0;
    int j = 0;
    // read in two strings
    file >> s1;
    file >> s2;
    Node *node = new Node();
    // to store unique class names 
        for (int i = 0; i < vec.size(); i++){
            if (s1 != vec[i]->name && s1 != "0") {
                k++;
            } 
        }
        if (k == vec.size()) {
            vec.push_back(node);
            vec[k]->name = s1;
            vec[k]->indegree = 0;
        }
        Node *node1 = new Node();
        for (int i = 0; i < vec.size(); i++){
            if (s2 != vec[i]->name && s2 != "0") {
                j++;
            } 
        }
        if (j == vec.size()) {
            vec.push_back(node1);
            vec[j]->name = s2;
            vec[j]->indegree = 0;
        }

        // node with direction edge
       for (int i = 0; i < vec.size(); i++){
            if (s1 == vec[i]->name && s1 != "0") {
                Node *temp = new Node();
                temp = vec[i];
                Node *tmp;
                while (temp->next != NULL) {
                    tmp = temp->next;
                    temp = tmp;
                }
                Node *adj = new Node();
                temp->next = adj;
                adj->name = s2;
                adj->indegree = 0;
            }
       }
       // to increment indegree
        for ( int i = 0; i < vec.size(); i++) {
            if (s2 == vec[i]->name && s2 != "0") {
                vec[i]->indegree += 1;
            }
        }
    } //end of main while loop
    // cout << vec[0]->name << endl;
    // cout << vec[0]->next->name << endl;
    // cout << vec[0]->next->next->name <<endl;
    // cout << vec[3]->next->next->next->name << endl;
    // to test if s1 is stored properly: working
    for (int i = 0; i < vec.size(); i++){
        //cout << vec[i]->name << end;
        //cout << vec[i]->indegree <<endl;
        //cout << vec[i]->next->next->name << endl;
    }
    Node *temp;
    Node *tmp;
    int at;
    // to print out
    while (vec.size() != 0) {
        temp = indegree0(vec);
        for (int i = 0; i < vec.size(); i++){
            if (temp->name == vec[i]->name){
                at = i;
            }
        }
        cout << temp->name << " ";
        while (temp->next != NULL) {
            tmp = temp->next;
            for (int i = 0; i < vec.size(); i++){
                if (tmp->name == vec[i]->name) {
                    vec[i]->indegree -= 1;
                }
            }
            temp = tmp;
        }
        vec.erase(vec.begin()+at);
    }
    cout << endl;
    file.close();
}

