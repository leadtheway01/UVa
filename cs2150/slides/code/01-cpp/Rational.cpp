// File Rational.cpp

#include "Rational.h"
#include <iostream>
using namespace std;

// default constructor: initialize to 0/1
Rational::Rational() : num(0), den(1) {
}

// destructor : more on these later...
Rational::~Rational() {
}

// create and initialize a new Rational object
Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        cout << "Denominator is zero" << endl;
    }
    int g = gcd(numerator, denominator);
    num = numerator   / g;
    den = denominator / g;
}

// return string representation of (this)
void Rational::print() {
    if (den == 1) {
        cout << num << "" << endl;
    } else {
        cout << num << "/" << den << endl;
    }
}

// return (this * b)
Rational Rational::times(Rational b) {
    return Rational(num * b.num, den * b.den);
}


// return (this + b)
Rational Rational::plus(Rational b) {
    int numerator   = (num * b.den) + (den * b.num);
    int denominator = den * b.den;
    return Rational(numerator, denominator);
}

// return (1 / this)
Rational Rational::reciprocal() {
    return Rational(den, num);
}

// return (this / b)
Rational Rational::divides(Rational b) {
    return times(b.reciprocal());
}


/*************************************************************************
 *  Helper functions
 *************************************************************************/

// return gcd(m, n)
int Rational::gcd(int m, int n) {
    if (0 == n)
        return m;
    else
        return gcd(n, m % n);
}
