#include <iostream>
#include <vector>
#include <string>
#include "insultgenerator_20owb.h"
using namespace std;

//InsultGenerator::InsultGenerator() {}


// load all source phrases into three separate vectors
// throw exception if file cannot be read

void InsultGenerator :: initialize() {

    string row;
    ifstream inputInsults("InsultsSource.txt");
    // check if file can be read
    if (inputInsults.fail()) {
        throw FileException("\nfile error");
    }
    stringstream ssInsults;
    // load all insults into single vector
    // check that it is not the end of the list
    while (!inputInsults.eof()) {
        getline(inputInsults, row);
        ssInsults.clear();
        ssInsults.str(" ");
        ssInsults << row;
        // parse file and copy insults into single vector
        // check there is data to read from string-stream
        while (ssInsults >> row) {
            allC.push_back(row);
        }
    }
    // copy insults from single vector to three separate vectors corresponding to inout file columns
    for (int i = 0; i < allC.size(); i += 3) {
        c1.push_back(allC[i]);
        c2.push_back(allC[i + 1]);
        c3.push_back(allC[i + 2]);
    }
    inputInsults.close();
}

// returns single randomly generated insult
string InsultGenerator :: talkToMe() {

    // generate three random numbers used for three separate indices of the vectors containing insults
    int rand1, rand2, rand3;
    rand1 = (rand() % 49);
    rand2 = (rand() % 49);
    rand3 = (rand() % 49);
    string insult1 = c1[rand1];
    string insult2 = c2[rand2];
    string insult3 = c3[rand3];
    string singleInsult;
    singleInsult = "Thou " + insult1 + " "  + insult2 + " " + insult3 + "!";
    return singleInsult;
}

// generates and returns the requested number of insults
vector<string> InsultGenerator :: generate(const int n) {

    // check the requested number of insults is within range
    if (n <1 || n > 10000) {
        throw NumInsultsOutOfBounds("\nnumber of insults invalid");
    }
    else {
        set<string> nInsults;
        // individually generate specified number of insults
        while (n > nInsults.size()) {
            string insult(talkToMe());
            nInsults.insert(insult);
        }
        // change to iterate
//        iterator<string> insultsIterator = nInsults.iterator();
//        while (insultsIterator.hasNext()) {
//
//        }
        vector<string> insults(nInsults.begin(), nInsults.end());
        return insults;
    }
}
// generates, returns and saves to a supplied filename, the requested number of insults
vector<string> InsultGenerator :: generateAndSave(string file, const int n) {

    ofstream savedInsults("savedInsults.txt");
    set<string> nInsults;
    // check that requested number of insults is within range
    if (n < 1) {
        throw NumInsultsOutOfBounds("\nnumber of insults invalid");
    }
        // individually generate specified number of insults and simultaneously save to created file
    else {
        while (n > nInsults.size()) {
            string insult(talkToMe());
            nInsults.insert(insult);
            savedInsults << insult;
            savedInsults << "\n";
        }
        vector<string> insults(nInsults.begin(), nInsults.end());
        return insults;
    }
}

FileException :: FileException (const string& message) : message(message) {}
string& FileException :: what() {return message; }

NumInsultsOutOfBounds :: NumInsultsOutOfBounds(const string& message) : message(message) {}
string& NumInsultsOutOfBounds :: what() {return message; }




