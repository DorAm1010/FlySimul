//
// Created by Laliv on 27/12/2019.
//

#ifndef EX3_READINGDATA_H
#define EX3_READINGDATA_H

#include "varStruct.h"
#include "command.h"
#include <unordered_map>

using namespace std;

class ReadingData {
private:
    /* Here will be the instance stored. */
    static ReadingData *instance;

    /* Private constructor to prevent instancing. */
    ReadingData();

    /*index that says where are we in the reading*/
    int index;

    /*vector of the instructions separate to words*/
    vector<string> words;

    /*map from name to VarStruct*/
    unordered_map<string, VarStruct *> nameToVariableMap;

    /*map from sim address to VarStruct*/
    unordered_map<string, VarStruct *> simToVariableMap;

    /*should the program still run*/
    bool should_run;

    // information map about existing vars that update the simulator
    unordered_map<string, int> indexMap;

    unordered_map<string, int> nameToIndexMap;

    unordered_map<string, VarStruct*> privateVarsMap;

    vector<string> messages;

public:
/* Static access method. */
    static ReadingData *getInstance();

    unordered_map<string, VarStruct *>* getNameToVariableMap();

    unordered_map<string, VarStruct *>* getSimToVariableMap();

    vector<string>* getWordsVector();

    void setWords(vector<string> v);

    int getInd();

    void incInd(int add);

    void setShouldRun(bool b);

    bool getShouldRun();

    void addToNameMap(string, VarStruct *);

    void addToSimMap(string, VarStruct *);

    void addToPrivateVarsMap(string, VarStruct *);

    int findInNameMap(const string&);

    int findInSimMap(const string&);

    int findInPrivateVarsMap(const string& name);

    void updateInNameMap(const string&, double);

    void updateInPrivateVarsMap(const string& name, double val);

    void updateInSimMap(const string&, double);

    void updateFromSimulator(vector<double>);

    void addToMessages(string);

    vector<string>* getMessages();

    VarStruct* returnVarStruct(string);
};


#endif //EX3_READINGDATA_H
