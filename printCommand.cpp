//
// Created by dor on 1/2/20.
//
#include <iostream>
#include "readingData.h"
// #include "ex1.cpp"

int printCommand::execute() {
    ReadingData* readingData = ReadingData::getInstance();
    string print = readingData->getWordsVector().at(readingData->getInd());
    // if argument has quotes its something to be printed without it
    if(print[0] == '"') {
        cout << print.substr(1, print.length() - 2) << endl;
    } else {
        // is an expression and needs to be added to interpreter
    }
}