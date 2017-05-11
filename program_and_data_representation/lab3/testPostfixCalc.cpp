//Wright Kim
//09/13/15
//testPostfixCalc.cpp

#include "postfixCalculator.h"
//#include <stack>
#include "myStack.h"
#include <cstdlib>
#include <iostream>
using namespace std;


int main() {
    postfixCalculator p;
  //test case 1
  /*
    p.pushNum (1);
    p.pushNum (2);
    p.pushNum (3);
    p.pushNum (4);
    p.pushNum (5);
    p.add();
    p.add();
    p.add();
    p.add();
  */

//test case 2
/*
    p.pushNum(20);
    p.pushNum(10);
    p.subtract();
    p.pushNum(-3);
    p.pushNum(10);
    p.subtract();
    p.subtract();
    p.pushNum(2);
    p.subtract();
*/

//test case 3
/*
	p.pushNum(-1);
 	p.pushNum(-2);
	p.pushNum(-5);
	p.pushNum(3);
	p.multiple();
	p.pushNum(2);
	p.pushNum(-2);
	p.multiple();
	p.multiple();
	p.multiple();
	p.multiple();
*/

//test case 4
/*
	p.pushNum(-1512);
	p.pushNum(-12);
	p.pushNum(-2);
	p.division();
	p.division();
	p.pushNum(-2);
	p.division();
	p.pushNum(3);
	p.division();
*/

//test case 5
/*
	p.pushNum(-1);
	p.negate();
	p.negate();
	p.negate();	
*/

	 while(cin.good()) {
        string s;
        cin >> s;
		if(s.compare("+") == 0){
			p.add();
			} else if(s.compare("-") == 0){
				p.subtract();
				} else if (s.compare("*") == 0){
					p.multiple();
					} else if (s.compare("/") == 0){
						p.division();
						} else if (s.compare("~") == 0){
							p.negate();
							}	else if (s == ""){
									break;
								} else {
									int a = atoi(s.c_str());
									p.pushNum(a);
									}  
    }
 
	cout << "Result is: " << p.getTopValue() << endl;
    return 0;
}
