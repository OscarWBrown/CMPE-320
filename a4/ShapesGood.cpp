//
// Created by oscar on 2022-12-04.
//

#include "ShapesGood.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// simple parent class for all regular polygons
Shape :: Shape() : length(0), width(0) { }
Shape :: Shape(const int l, const int w) : length(l), width(w) { }
Shape :: ~Shape() { }
int Shape :: getLength() { return length; }
int Shape :: getWidth() { return width; }

// parent class for all polygons
Square :: Square(const int l, const int w, const string& bc) : borderColour(bc), Shape(l, w) { }
Square :: ~Square() { }
string Square :: getBorderColour() { return borderColour; }
void Square :: draw() {
    cout << "\nDrawing a " + getBorderColour() + " square.";
}

// parent class for all filled polygons
FilledSquare :: FilledSquare(const int l, const int w, const string& bc, const string& fc) : fillColour(fc), Square(l, w, bc) { }
FilledSquare :: ~FilledSquare() { }
string FilledSquare :: getFillColour() { return fillColour; }
void FilledSquare :: draw() {
    Square :: draw();
    cout << "With " + getFillColour() + " fill.";
}

// parent class for all filled polygons with text
FilledTextSquare :: FilledTextSquare(const int l, const int w, const string& bc, const string& fc, string txt) : text(txt), FilledSquare(l, w, bc, fc) { }
FilledTextSquare :: ~FilledTextSquare() { }
string FilledTextSquare :: getText() { return text; }
void FilledTextSquare :: draw() {
    FilledSquare :: draw();
    cout << "Containing the text: \""+ getText() + "\"!";
}

// inherits from square class
Circle :: Circle(const int l, const int w, const string& bc) : Square(l, w, bc) { }
Circle :: ~Circle() { }
void Circle :: draw() {
    cout << "\nDrawing a " + getBorderColour() + " circle.";
}

// inherits from filled square class
FilledCircle :: FilledCircle(const int l, const int w, const string& bc, const string& fc) : FilledSquare(l, w, bc, fc) { }
FilledCircle :: ~FilledCircle() { }
void FilledCircle :: draw() {
    cout << "\nDrawing a " + getBorderColour() + " circle. With " + getFillColour() + " fill.";
}

// inherits from square class
Arc :: Arc(const int l, const int w, const string& bc) : Square(l, w, bc) { }
Arc :: ~Arc() { }
void Arc :: draw() {
    cout << "\nDrawing a " + getBorderColour() + " arc.";
}
