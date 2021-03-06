//
// Created by Laliv on 20/12/2019.
//
#include "readingData.h"
#include "ex1.h"
#include "defineVar.h"

using namespace std;
/**
 * Define a new variable and add it to the appropriate map.
 **/
int DefineVarCommand::execute() {
    // get singleton
    ReadingData* readingData = ReadingData::getInstance();
    // get to var name in vector
    readingData->incInd(1);
    string name = readingData->getWordsVector()->at(readingData->getInd());
    // make a new varStruct value
    VarStruct* varStruct = new VarStruct();

    // inc to get wrap direction string
    readingData->incInd(1);

    // wrap direction
    string wrap = readingData->getWordsVector()->at(readingData->getInd());

    // inc to get string the string that follows wrap
    readingData->incInd(1);

    // either its an address in the simulator or its an expression of some sort
    string sim_or_expression = readingData->getWordsVector()->at(readingData->getInd());

    if (wrap == "->") {
        // add to nameToVarMap
        varStruct->setSim(sim_or_expression);
        readingData->addToNameMap(name, varStruct);
    } else if (wrap == "<-") {
        // add to simToVarMap
        varStruct->setSim(sim_or_expression);
        readingData->addToSimMap(name, varStruct);
    } else if (wrap == "=") { // is =
            double val = evaluate(sim_or_expression);
            varStruct->setVal(val);
            readingData->addToPrivateVarsMap(name, varStruct);
    } else {
        throw("define var error");
    }

    readingData->incInd(1);
}

