//
// Created by Laliv on 20/12/2019.
//
#include "readingData.h"
#include "ex1.h"

using namespace std;

int DefineVarCommand::execute() {
    ReadingData* readingData = ReadingData::getInstance();
    string name = readingData->getWordsVector()->at(readingData->getInd());
    VarStruct varStruct;
    double expression;

    // inc to get wrap direction string
    readingData->incInd(1);

    string wrap = readingData->getWordsVector()->at(readingData->getInd());

    // inc to get string the string that follows wrap
    readingData->incInd(1);

    string sim_or_expression = readingData->getWordsVector()->at(readingData->getInd());

    if (wrap == "->") {
        // add to nameToVarMap
        varStruct.setSim(sim_or_expression);
        readingData->addToNameMap(name, &varStruct);
    } else if (wrap == "<-") {
        // add to simToVarMap
        varStruct.setSim(sim_or_expression);
        readingData->addToSimMap(name, &varStruct);
    } else { // is =
        // TODO - get double representation of val to update in map which means USE INTERPRETER CLASS FROM EX1
        if (readingData->findInNameMap(name)) {
            // format is var x = expression
            // expression = evaluate(sim_or_expression);
            // insert to symTable
        }
    }
    readingData->incInd(1);
}