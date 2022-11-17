#ifndef CMPE320_A3_JUMBLE_H
#define CMPE320_A3_JUMBLE_H
#include <string>
#pragma once

using namespace std;

typedef char* charArrayPtr;

class JumblePuzzle {
    public:
    // constructors
        // default
        JumblePuzzle();
        // copy
        JumblePuzzle(const JumblePuzzle& copy);
        // main
        JumblePuzzle(const string& word, const string& difficulty);

    // destructor
        ~JumblePuzzle();

    // overload operators
        // assignment
        JumblePuzzle& operator=(const JumblePuzzle&);

    // accessors
        int getSize() const;
        int getRowPos() const;
        int getColPos() const;
        char getDirection() const;
        char getRandomDirection() const;
        char** getJumble() const;

    // methods
        // sets size of jumble puzzle
        void setSize(const string& difficulty);
        // inserts hidden word into jumble puzzle
        void setJumblePuzzle(const string& word);

    private:
    // fields
        char** jumble;
        int size;
        int row;
        int col;
        int dir;

};

class BadJumbleException {
    public:
    // constructors
        // exception to display error
        BadJumbleException(const string& output);

    // methods
        // method to be called when thrown
        string& what();

    private:
    // field
        string message;
};

#endif //CMPE320_A3_JUMBLE_H
