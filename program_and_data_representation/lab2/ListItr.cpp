//Wright Kim
//09/11/15
//ListItr.cpp
#include "ListNode.h"
#include "List.h"
using namespace std;

//constructor
ListItr::ListItr(){
	current = new ListNode();
}		       

//one parameter constructor
ListItr::ListItr(ListNode* theNode){
	current = theNode;
}

//returns true if past end position in list, else false
bool ListItr::isPastEnd() const{
	if(current -> next -> next == NULL){
		return true;
	} else {
		return false;
	}
}

//returns true if past first position in list, else false
bool ListItr::isPastBeginning() const{
 	if(current -> previous -> previous == NULL){
 		return true;
 	}else {
 		return false;
 	}
}

//advances current to next position in list (unless already past end of list)
void ListItr::moveForward(){
	current = current -> next;
}

//moves current back to previous position in list (unless already past
//beginning of list)	
void ListItr::moveBackward(){
	current = current -> previous;
}

//returns item in current position
int ListItr::retrieve() const{
  return current -> value;
}

