//
// Created by dor on 1/2/20.
//
#include <iostream>
#include "readingData.h"
#include "printCommand.h"
using namespace std;

/**
 * Execute print command.
 **/
int PrintCommand::execute() {
    ReadingData* readingData = ReadingData::getInstance();
    string print;
    // get to argument of Print function
    readingData->incInd(1);
    print = readingData->getWordsVector()->at(readingData->getInd());
    double expression;

    // if argument has quotes its a message to be printed without it
    if(print[0] == '"') {
        cout << print.substr(1, print.length() - 2) << endl;
    } else {
        // otherwise it is an expression and needs to be interpreted
        expression = evaluate(print);
        cout << expression << endl;
    }
    readingData->incInd(1);
}