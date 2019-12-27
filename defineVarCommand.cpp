//
// Created by Laliv on 20/12/2019.
//
#include "Command.h"
#include "readingData.h"
#include <vector>
#include <string>

using namespace std;

int DefineVarCommand:: execute() {
    vector<string>* argVec = ReadingData::getWordsVector();
    int ind = ReadingData::getInd();
}