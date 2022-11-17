#include "jumble.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

JumblePuzzle :: JumblePuzzle() {
    jumble = nullptr;
    size = 0;
    dir = 0;
    row = 0;
    col = 0;
}

JumblePuzzle :: JumblePuzzle(const JumblePuzzle& copy) {
    size = copy.getSize();
    row = copy.getRowPos();
    col = copy.getColPos();
    dir = copy.getDirection();

    jumble = new char*[size];
    for (int i = 0; i < size; i++) {
        jumble[i] = new char[size];
    }

    // could be a problem, check type def
    char** copyJumble = copy.getJumble();

    for (int i = 0; i < size ; i++) {
        for (int j = 0; j < size; j++) {
            jumble[i][j] = copyJumble[i][j];
        }
    }
}

JumblePuzzle :: JumblePuzzle(const string& word, const string& difficulty) {
    srand(time(nullptr));
    size = word.length();
    if (size < 3 || size > 10) {
        throw BadJumbleException("hidden word must be between 3 and 10 letterslong");
    }
    setSize(difficulty);
    setJumblePuzzle(word);
}

JumblePuzzle& JumblePuzzle :: operator=(const JumblePuzzle& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < size; i++) {
            delete[] jumble[i];
        }
        delete[] jumble;

        size = rhs.getSize();
        row = rhs.getRowPos();
        col = rhs.getColPos();
        dir = rhs.getDirection();

        if (rhs.getJumble()) {
            jumble = new char*[size];
            for (int i = 0; i < size; i++) {
                jumble[i] = new char[size];
            }

            char** rhsJumble = rhs.getJumble();
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    jumble[i][j] = rhsJumble[i][j];
                }
            }
        }
    }
    return *this;
}

JumblePuzzle :: ~JumblePuzzle() {
    for (int i = 0; i < size; i++) {
        delete[] jumble[i];
    }
    delete[] jumble;
}

void JumblePuzzle :: setJumblePuzzle(const string& word) {
    jumble = new char*[size];
    for (int i = 0; i < size; i++) {
        jumble[i] = new char[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            jumble[i][j] = rand() % 26 + 'a';
        }
    }
    row = rand() % size;
    col = rand() % size;

    jumble[row][col] = word[0];

    bool isPlaced = false;
    while (!isPlaced) {
        dir = getRandomDirection();
        if (dir == 'n') {
            for (unsigned int i = 1; i < word.length(); i++) {
                if ((row - i) >= 0) {
                    jumble[row - i][col] = word[i];
                } else {
                    break;
                }

                if ((i + 1) == word.length()) {
                    isPlaced = true;
                }
            }
        } else if (dir == 'e') {
            for (unsigned int i = 1; i < word.length(); i++) {
                if ((col + 1) < word.length()) {
                    jumble[row][col - 1] = word[i];
                } else {
                    break;
                }
                if ((i + 1) == word.length()) {
                    isPlaced = true;
                }
            }
        } else if (dir == 's') {
            for (unsigned int i = 1; i < word.length(); i++) {
                if ((row + i) < word.length()) {
                    jumble[row + i][col] = word[i];
                } else {
                    break;
                }
                if ((i + 1) == word.length()) {
                    isPlaced = true;
                }
            }
        }
        else { // dir == 'w'
            for (unsigned int i = 1; i < word.length(); i++) {
                if ((col - 1) >= 0) {
                    jumble[row][col - i] = word[i];
                }
                else {
                    break;
                }
                if ((i + 1) == word.length()) {
                    isPlaced = true;
                }
            }
        }
    }
}

void JumblePuzzle :: setSize(const string& difficulty) {
    if (difficulty == "easy") {
        size *= 2;
    }
    else if (difficulty == "medium") {
        size *= 3;
    }
    else if (difficulty == "hard") {
        size *= 4;
    }
    else {
        throw BadJumbleException("enetered difficulty must be either 'easy', 'medium' or 'hard'");
    }
}

char JumblePuzzle :: getRandomDirection() const{
    switch(rand() % 4) {
        case 0:
            return 'n';
            break;
        case 1:
            return 'e';
            break;
        case 2:
            return 's';
            break;
        case 3:
            return 'w';
            break;
    }
    return 0;
}

char** JumblePuzzle :: getJumble() const{
    char**  jumbleCopy = new char*[size];
    for (int i = 0; i < size; i++){
        jumbleCopy[i] = new char[size];
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            jumbleCopy[i][j] = jumble[i][j];
        }
    }

    return jumbleCopy;
}

int JumblePuzzle :: getSize() const{ return size; }
int JumblePuzzle :: getRowPos() const{ return row; }
int JumblePuzzle :: getColPos() const{ return col; }
char JumblePuzzle :: getDirection() const{ return dir; }

BadJumbleException :: BadJumbleException(const string& output) : message(output) {
}

string& BadJumbleException :: what() {
    return message;
}

