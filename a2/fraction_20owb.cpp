// Oscar Brown

#include "fraction_20owb.h"
#include <iostream>
#include <string>
using namespace std;

int gcd(int n, int d); // declare gcd function

// exception class
FractionException :: FractionException(const string& o) : output(o) {}
string& FractionException :: what() { return output; }

// class constructors
Fraction :: Fraction(): N(0), D(1) { }
Fraction :: Fraction(int n): N(n), D(1) { }
Fraction :: Fraction(int n, int d) {
    if(d == 0) {
        throw FractionException("\ndenominator cannot equal 0\n");
    }
    int divisor = gcd(abs(n), abs(d));
    if (d < 0) {
        N = -(n / divisor);
        D = -(d / divisor);
    }
    else {
        N = n / divisor;
        D = d / divisor;
    }
}

// local gcd function
int gcd(int n, int d) {
    if (d <= n && n % d == 0) {
        return d;
    }
    else if (n < d) {
        return gcd(d, n);
    }
    else {
        return gcd(d, n % d);
    }
}

// class accessors
int Fraction :: numerator() const { return N ; }
int Fraction :: denominator() const { return D; }

// overload unary negation
Fraction Fraction :: operator-() {
    if (N < 0 && D < 0) {
        return {N, D};
    }
    else {
        return {-N, D};
    }
}
// overload unary pre-increment
Fraction& Fraction :: operator++() {
    N = N + D;
    return *this;
}
// overload unary post-increment
Fraction Fraction :: operator++(int unused) {
    Fraction copy(N, D);
    N = N + D;
    return copy;
}
// overload binary addition (fraction, fraction)
Fraction operator+(const Fraction& left, const Fraction& right) {
    if (left.denominator() == right.denominator()) {
        return {(left.numerator() + right.numerator()), left.denominator()};
    }
    else {
        return {((left.numerator() * right.denominator()) + (right.numerator() * left.denominator())), (left.denominator() * right.denominator())};
    }
}
// overload binary addition (fraction, integer)
Fraction operator+(const Fraction& left, int i) {
    return {left.numerator() + (i * left.denominator()), left.denominator()};
}
// overload binary addition (integer, fraction)
Fraction operator+(int i, const Fraction& right) {
    return {right.numerator() + (i * right.denominator()), right.denominator()};
}
// overload binary subtraction (fraction, fraction)
Fraction operator-(const Fraction& left, const Fraction& right) {
    if (left.denominator() == right.denominator()) {
        return {(left.numerator() - right.numerator()), left.denominator()};
    }
    else {
        return {((left.numerator() * right.denominator()) - (right.numerator() * left.denominator())), (left.denominator() * right.denominator())};
    }
}
// overload binary subtraction (fraction, integer)
Fraction operator-(const Fraction& left, int i) {
    return {left.numerator() - (i * left.denominator()), left.denominator()};
}
// overload binary subtraction (integer, fraction)
Fraction operator-(int i, const Fraction& right) {
    return {(i * right.denominator()) - right.numerator(), right.denominator()};
}
// overload binary multiplication (fraction, fraction)
Fraction operator*(const Fraction& left, const Fraction& right) {
    return {(left.numerator() * right.numerator()), (left.denominator() * right.denominator())};
}
// overload binary division (fraction, fraction)
Fraction operator/(const Fraction& left, const Fraction& right) {
    return {(left.numerator() * right.denominator()), (left.denominator() * right.numerator())};
}
// overload binary addition and assignment
Fraction& Fraction :: operator+=(const Fraction& right) {
    Fraction copy = Fraction(N, D);
    copy= copy + right;
    N = copy.N;
    D = copy.D;
    return *this;
}
// overload boolean equality
bool operator==(const Fraction& left, const Fraction& right) {
    return ((left.numerator() == right.numerator()) && (left.denominator() == right.denominator()));
}
// overload boolean inequality
bool operator!=(const Fraction& left, const Fraction& right) {
    return ((left.numerator() != right.numerator()) || (left.denominator() != right.denominator()));
}
// overload boolean lhs greater-than rhs comparator
bool operator>(const Fraction& left, const Fraction& right) {
    return (left.numerator() * right.denominator()) > (right.numerator() * left.denominator());
}
// overload boolean lhs less-than rhs comparator
bool operator<(const Fraction& left, const Fraction& right) {
    return (left.numerator() * right.denominator()) < (right.numerator() * left.denominator());
}
// overload boolean lhs greater-than-or-equal-to rhs
bool operator>=(const Fraction& left, const Fraction& right) {
    return (left.numerator() * right.denominator()) >= (right.numerator() * left.denominator());
}
// overload boolean lhs less-than-or-equal-to rhs
bool operator<=(const Fraction& left, const Fraction& right) {
    return (left.numerator() * right.denominator()) <= (right.numerator() * left.denominator());
}
// overload output operator
ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.N << "/" << f.D;
    return out;
}
// overload input operator
istream& operator>>(istream& in, Fraction& f) {



    string input;
    string slash = "/";
    in >> input;
    f.N = stoi(input.substr(0, input.find(slash)));
    input.erase(0, input.find(slash) + slash.length());
    f.D = stoi(input);
    if (f.D == 0) {
        throw FractionException("\ndenominator cannot be 0\n");
    }
    if (f.N == f.D) {
        f.D = 1;
    }
    return in;
}




