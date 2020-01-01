//
// Created by Laliv on 20/12/2019.
//
#include "command.h"
#include "readingData.h"

using namespace std;

int DefineVarCommand:: execute() {
    vector<string>* argVec = ReadingData::getWordsVector();
    int ind = ReadingData::getInd();
}