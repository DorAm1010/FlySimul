//
// Created by Laliv on 03/01/2020.
//
#include <iostream>
#include "readingData.h"
#include "assignValue.h"

using namespace std;

/**
 * assign new value to an existing variable.
 */
int AssignValueCommand::execute() {
    // get singleton with global information
    ReadingData* rd = ReadingData::getInstance();
    // get current index on lexed vector of strings from input file
    int ind = rd->getInd();
    string sim, value;
    // lexed vector
    vector<string>* words = rd->getWordsVector();
    // appropriate value to assign from the vector
    double newVal = evaluate((*words)[ind + 2]);  //stod((*words)[ind + 2]);
    // variables' name to assign value to
    string var = (*words)[ind];
    if(rd->findInNameMap(var) == 1) { // if found here add to messages that update simulator
        // update new value
        rd->updateInNameMap(var, newVal);
        // get relevant varStruct and add to messages in the format
        // set /field_address value \r\n
        VarStruct *s = rd->returnVarStruct(var);
        sim = s->getSim();
        value = to_string(newVal);
        string massage = "set /" + sim + " " + value + "\r\n";
        rd->addToMessages(massage);
    } else if(rd->findInPrivateVarsMap(var) == 1) {
        // is a variable that needs not update the simulator
        rd->updateInPrivateVarsMap(var, newVal);
    } else {
        throw "Unable to find variable";
    }

    rd->incInd(3);
}