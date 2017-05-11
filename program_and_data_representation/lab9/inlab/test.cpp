
#include <iostream>
#include <cstdlib>
using namespace std;

class A {
public:
	A(){}
	~A(){}
	virtual void foo(){
		cout << "A" << endl;
	}
	virtual void add(){

	}
};
class B : public A {
public:
	B(){}
	~B(){}
	virtual void foo() {
		cout << "B" << endl;
	}
	virtual void add(){

	}
};

int main() {
	int which = rand() % 2;
	A *bar;
	if (which) {
		bar = new A();
	} else {
		bar = new B();
	}
	bar->foo();
	bar->add();
	return 0;
}