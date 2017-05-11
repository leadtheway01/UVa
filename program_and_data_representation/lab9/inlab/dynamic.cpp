
#include <iostream>
using namespace std;



class parent {
public:
	parent(){}
	~parent(){}
	virtual void print(){
		cout << "parent" << endl;
	}
	virtual void add() {
		cout << "parent add" << endl;
	}
};
class child : public parent {
public:
	child(){}
	~child(){}
	virtual void print() {
		cout << "child" << endl;
	}
	virtual void add() {
		cout << "child add" << endl;
	}
};
int main() {
	parent *p;
	p = new child();
	p->print();
	p->add();
	return 0;
}

