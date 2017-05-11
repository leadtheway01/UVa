//Wright Kim
//09/11/2015
//List.cpp
#include <iostream>
#include "ListItr.h"
#include "ListNode.h"
using namespace std;

//constructor
List::List(){
  count = int(); 		    //initalized count to 0
  head = new ListNode();	//initailzed pointer head of ListNode object
  tail = new ListNode();	//initalized pointer tail of ListNode object
  head->next=tail;			//head's next is pointing tail	
  tail->previous=head;		//tail's previous is pointing head
}

//copy constructor
List::List(const List& source){
	head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

//destructor: frees up any resources allocated during the use of an object
List::~List(){
	makeEmpty();	//removes everything but dummy head and tail
	delete head;	//removes dummy head
	delete tail;	//removes dummy tail
}

//equal operator: intened to copy the state of original into copy
List& List::operator=(const List& source){
	if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

//returns true if emty; else false
bool List::isEmpty() const{
  if(count == 0){
  	return true;	//return true if no list (count == 0)
  }else {
  	return false; 	//return false if there is list (!count == 0)
  }
}

//removes all items except blank head and tail
void List::makeEmpty(){
	ListItr temp = last();									//create List iterator temp
	while(!isEmpty()){
		remove((temp.current -> previous) -> value);
		count--;
	}
}

//returns an iterator that points to the ListNode in the first position
ListItr List::first(){
	ListItr temp(head -> next);
	return temp;
}

//returns an iterator that points to the ListNode in the last position
ListItr List::last(){
	ListItr temp(tail -> previous); 
	return temp;
}


//Inserts x after current iterator position p
void List::insertAfter(int x, ListItr position){
	ListNode *temp = new ListNode();				  	//temp is new node
	temp -> value = x;									//temp's value is x
	temp -> next = 	position.current -> next;			//temp's next is pointing the node after temp
	temp -> previous = position.current;				//temp's previous is pointing node before

	position.current -> next -> previous = temp;		//the node after temp's previous is pointing temp			
	position.current -> next = temp;					//the node before temp's next is pointing temp
	count++;
}

//inserts x before current iterator position p
void List::insertBefore(int x, ListItr position){
	ListNode *temp = new ListNode();					//temp is new node
	temp -> value = x;									//temp's value is x
	temp -> next = position.current;					//temp's next is pointing node after temp
	temp -> previous = position.current -> previous;	//temp's previous is pointing node before temp

	position.current -> previous -> next = temp;		//node before temp's next is pointing temp
	position.current -> previous = temp;				//previous of node after temp is pointing temp
	count++;											//increase count (node) by 1
}

//insert x at tail of list
void List::insertAtTail(int x){
	ListItr temp = last();
	insertAfter(x, temp);
}

//removes the first occurrence of x
void List::remove(int x){
	ListItr temp = find(x);
	temp.current -> previous -> next = temp.current -> next;
	temp.current -> next -> previous = temp.current -> previous;
	delete temp.current;
	count--;
	}

//returns an iterator that points to the first occurence of x, else return
//a iterator to the dummy tail node		
ListItr List::find(int x){
	ListItr temp = first();
	for(int i = 0 ; i < size(); i++){
		if(temp.current -> value == x){
			return temp;
		}
		temp.moveForward();
	}
	return temp;
}

//returns the number of elements in the list
int List::size() const{
  return count;
}

// printList: non-member function prototype
//prints list forwards when direction is true
//or backwards when direction is false
void printList(List& source, bool direction){
	List tempList;
	List &temp = tempList;
	temp = source;

	if(direction){
		ListItr temp1;
		temp1 = temp.first();
		for(int i = 0; i < temp.size(); i++){
			cout << temp1.retrieve() << endl;
			temp1.moveForward();
		}
	}else {
		ListItr temp2;
		temp2 = temp.last();
		for (int i = 0; i < temp.size(); i++){
			cout << temp2.retrieve() << endl;
			temp2.moveBackward();
		}
	}
}