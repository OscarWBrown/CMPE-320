// Oscar Brown

#ifndef CMPE320_A2_FRACTION_20OWB_H
#define CMPE320_A2_FRACTION_20OWB_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class FractionException {
public:
    FractionException(const string&);
    string& what();
private:
    string output;
};

class Fraction {
public:
    // declare fields
    int D; // denominator
    int N; // numerator

    // declare constructors
    Fraction();
    Fraction(int d);
    Fraction(int n, int d);

    // declare accessors
    int numerator() const;
    int denominator() const;

    // overload unary operations
    Fraction operator-();
    Fraction& operator++();
    Fraction operator++(int);

    // overload binary operators
    // + and - are overloaded for three cases: fraction{operator}fraction, fraction{operator}integer, integer{operator}fraction
    friend Fraction operator+(const Fraction& left, const Fraction& right);
    friend Fraction operator+(const Fraction& left, int i);
    friend Fraction operator+(int i, const Fraction& right);
    friend Fraction operator-(const Fraction& left, const Fraction& right);
    friend Fraction operator-(const Fraction& left, int i);
    friend Fraction operator-(int i, const Fraction& left);
    friend Fraction operator*(const Fraction& left, const Fraction& right);
    friend Fraction operator/(const Fraction& left, const Fraction& right);
    Fraction& operator+=(const Fraction& right);

    // overload comparison operators
    // boolean operators are each overloaded for combinations of three cases: fraction{operator}fraction, fraction{operator}integer, integer{operator}fraction
    friend bool operator==(const Fraction& left, const Fraction& right);
    friend bool operator!=(const Fraction& left, const Fraction& right);
    friend bool operator>(const Fraction& left, const Fraction& right);
    friend bool operator<(const Fraction& left, const Fraction& right);
    friend bool operator>=(const Fraction& left, const Fraction& right);
    friend bool operator<=(const Fraction& left, const Fraction& right);

    // overload input and output operators
    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);

};

#endif //CMPE320_A2_FRACTION_20OWB_H
