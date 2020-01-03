//
// Created by Laliv on 20/12/2019.
//
#include "readingData.h"

using namespace std;

int DefineVarCommand:: execute() {
    ReadingData* readingData = ReadingData::getInstance();
    string name = readingData->getWordsVector().at(readingData->getInd());
    VarStruct varStruct;

    // inc to get wrap direction string
    readingData->incInd(1);

    string wrap = readingData->getWordsVector().at(readingData->getInd());

    // inc to get string the string that follows wrap
    readingData->incInd(1);

    string sim_or_expression = readingData->getWordsVector().at(readingData->getInd());

    if (wrap == "->") {
        // add to nameToVarMap
        varStruct.setNeedToChangeSim(true);
        varStruct.setSim(sim_or_expression);
        readingData->addToNameMap(name, &varStruct);
    } else if (wrap == "<-") {
        // add to simToVarMap
        varStruct.setNeedToChangeSim(false);
        varStruct.setSim(sim_or_expression);
        readingData->addToSimMap(name, &varStruct);
    } else { // is =
        // TODO - get double representation of val to update in map which means USE INTERPRETER CLASS FROM EX1
        // sim_or_expressions needs to be interpreted here i think
        // if expression starts with quotes its a
        // message is sent in this manner: "set sim value \r\n"
        // if (readingData->findInMap(name, ))
        // else meaning it wasnt found in map then its a new var initialized
    }
    readingData->incInd(1);
    return 0;
}