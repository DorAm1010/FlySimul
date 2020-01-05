//
// Created by Laliv on 03/01/2020.
//
#include "readingData.h"
#include "assignValue.h"

using namespace std;

/**
 * assign new value to an existing variable.
 */
int AssignValueCommand::execute() {
    ReadingData* rd = ReadingData::getInstance();
    int ind = rd->getInd();
    vector<string>* words = rd->getWordsVector();
    double newVal = stod((*words)[ind + 2]);
    string var = (*words)[ind];
    if(rd->findInNameMap(var) == 1) {
        rd->updateInNameMap(var, newVal);
        VarStruct *s = rd->returnVarStruct(var);
        string massage = "set /" + s->getSim() + (*words)[ind + 2] + "\r\n";
        rd->addToMessages(massage);
    } else if(rd->findInPrivateVarsMap(var) == 1) {
        rd->updateInPrivateVarsMap(var, newVal);
    }

    rd->incInd(3);
}