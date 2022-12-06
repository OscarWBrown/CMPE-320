//
// Created by oscar on 2022-12-04.
//

#ifndef CMPE320_A4_SHAPESGOOD_H
#define CMPE320_A4_SHAPESGOOD_H
#include <iostream>
#include <string>
using namespace std;

// simple parent class for all regular polygons
class Shape {
public:
    Shape();
    Shape(const int l, const int w);
    virtual ~Shape();
    int getLength();
    int getWidth();
    virtual void draw() { cout << "/nUsing shape class"; }

private:
    int length;
    int width;

};

// parent class for all polygons
class Square : public Shape {
public:
    Square(const int l, const int w, const string& bc);
    ~Square();
    void draw();
    string getBorderColour();

private:
    string borderColour;

};

// parent class for all filled polygons
class FilledSquare : public Square {
public:
    FilledSquare(const int l, const int w, const string& bc, const string& fc);
    ~FilledSquare();
    void draw();
    string getFillColour();
private:
    string fillColour;

};

// parent class for all filled polygons with text
class FilledTextSquare : public FilledSquare {
public:
    FilledTextSquare(const int l, const int w, const string& bc, const string& fc, string txt);
    ~FilledTextSquare();
    void draw();
    string getText();

private:
    string text;

};

// inherits from square class
class Circle : public Square {
public:
    Circle(const int l, const int w, const string& bc);
    ~Circle();
    void draw();
private:
    string borderColour;

};

// inherits from filled square class
class FilledCircle : public FilledSquare {
public:
    FilledCircle(const int l, const int w, const string& bc, const string& fc);
    ~FilledCircle();
    void draw();
private:
    string fillColour;

};

// inherits from square class
class Arc : public Square {
public:
    Arc(const int l, const int w, const string& bc);
    ~Arc();
    void draw();
private:
    string borderColour;

};

#endif //CMPE320_A4_SHAPESGOOD_H
