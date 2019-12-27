//
// Created by Laliv on 27/12/2019.
//

#ifndef EX3_READINGDATA_H
#define EX3_READINGDATA_H

#include <vector>
#include <string>
#include <unordered_map>
#include "varStruct.h"

using namespace std;

class ReadingData
{
private:
    /* Here will be the instance stored. */
    static ReadingData* instance;

    /* Private constructor to prevent instancing. */
    ReadingData();

    /*index that says where are we in the reading*/
    int index;

    /*vector of the instructions separate to words*/
    vector<string>* words;

    /*map from name to varStruct*/
    unordered_map<string,varStruct>* nameToVariableMap;

    /*map from sim address to varStruct*/
    unordered_map<string,varStruct>* simToVariableMap;

public:
    /* Static access method. */
    static ReadingData* getInstance();

    static unordered_map<string,varStruct>* getNameToVariableMap();

    static unordered_map<string,varStruct>* getSimToVariableMap();

    static vector<string>* getWordsVector();

    static void setWords(vector<string>* v);

    static int getInd();

    static void incInd(int add);
};


#endif //EX3_READINGDATA_H
