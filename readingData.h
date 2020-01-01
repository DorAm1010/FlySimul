//
// Created by Laliv on 27/12/2019.
//

#ifndef EX3_READINGDATA_H
#define EX3_READINGDATA_H

#include "varStruct.h"
#include "command.h"

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
    vector<string> words;

    /*map from name to VarStruct*/
    unordered_map<string,VarStruct*> nameToVariableMap;

    /*map from sim address to VarStruct*/
    unordered_map<string, VarStruct*> simToVariableMap;

    /*should the program still run*/
    bool should_run;

    /*command map*/
    unordered_map<string, Command*> command_map;

public:
/* Static access method. */
    static ReadingData* getInstance();

    unordered_map<string,VarStruct*> getNameToVariableMap();

    unordered_map<string,VarStruct*> getSimToVariableMap();

    vector<string> getWordsVector();

    void setWords(vector<string> v);

    int getInd();

    void incInd(int add);

    void setShouldRun(bool b);

    bool getShouldRun ();

    void initMapsKeys();
};


#endif //EX3_READINGDATA_H
