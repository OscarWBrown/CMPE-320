#ifndef INSULTGENERATOR_20OWB_H
#define INSULTGENERATOR_20OWB_H
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <set>
#include <exception>

using namespace std;

class FileException
{
public:
    FileException(const string& message);
    string& what();
private:
    string message;
};

class NumInsultsOutOfBounds
{
public:
    NumInsultsOutOfBounds(const string& message);
    string& what();
private:
    string message;
};

class InsultGenerator
{
public:
    void initialize();
    string talkToMe();
    vector<string> generate(int a);
    vector<string> generateAndSave(string file, int n);

private:
    vector<string> c1;
    vector<string> c2;
    vector<string> c3;
    vector<string> allC;
    set<string> insult;
};

#endif


