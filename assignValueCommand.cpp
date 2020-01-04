//
// Created by Laliv on 03/01/2020.
//
#include "command.h"
#include "readingData.h"

using namespace std;

/**
 * assign new value to an existing variable.
 */
void AssignValueCommand::execute() {
    ReadingData* rd = ReadingData::getInstance();
    int ind = rd->getInd();
    vector<string> words = rd->getWordsVector();
    double newVal = stod(words[ind + 2]);
    rd->updateInNameMap(words[ind], newVal);
    VarStruct* s = rd->returnVarStruct(words[ind]);
    string massage = "set /" + s->getSim() + words[ind + 2] + "\r\n";
    rd->addToMassages(massage);

    rd->incInd(3);
}