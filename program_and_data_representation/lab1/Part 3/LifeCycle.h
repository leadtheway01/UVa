//Wright Kim
//wdk7bj
//09/02/15

#ifndef LifeCycle_H
#define LifeCycle_H
using namespace std;
#include <iostream>

class MyObject {
public:
    static int numObjs;
    MyObject(const char *n = "--default--");      // default constructor
    MyObject(const MyObject& rhs);                // copy constructor
    ~MyObject();                                  // destructor
    string getName() const {
        return name;
    }
    void setName(const string newName) {
        name = newName;
    }
    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

#endif
