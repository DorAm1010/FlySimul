//
// Created by Laliv on 27/12/2019.
//

#ifndef FLYSIMUL_READINGDATA_H
#define FLYSIMUL_READINGDATA_H

#include "varStruct.h"
#include "command.h"
#include <unordered_map>
#include <vector>

class ReadingData {
private:
    /* Here will be the instance stored. */
    static ReadingData *instance;

    /* Private constructor to prevent instancing. */
    ReadingData();

    /*index that says where are we in the reading*/
    int index;

    /*vector of the instructions separate to words*/
    std::vector<std::string> words;

    /*map from name to VarStruct*/
    std::unordered_map<std::string, VarStruct *> nameToVariableMap;

    /*map from sim address to VarStruct*/
    std::unordered_map<std::string, VarStruct *> simToVariableMap;

    /*should the program still run*/
    bool should_run;

    // information map about existing vars that update the simulator
    std::unordered_map<std::string, int> nameToIndexMap;

    std::unordered_map<std::string, VarStruct*> privateVarsMap;

    std::vector<std::string> messages;

public:
/* Static access method. */
    static ReadingData *getInstance();

    std::unordered_map<std::string, VarStruct *>* getNameToVariableMap();

    std::vector<std::string>* getWordsVector();

    void setWords(std::vector<std::string> v);

    int getInd();

    void incInd(int add);

    void setShouldRun(bool b);

    bool getShouldRun();

    void addToNameMap(const std::string&, VarStruct *);

    void addToSimMap(const std::string&, VarStruct *);

    void addToPrivateVarsMap(const std::string&, VarStruct *);

    int findInNameMap(const std::string&);

    int findInPrivateVarsMap(const std::string& name);

    std::unordered_map<std::string, VarStruct*>* getPrivateVarsMap();

    void updateInNameMap(const std::string&, double);

    void updateInPrivateVarsMap(const std::string& name, double val);

    void updateFromSimulator(std::vector<double>);

    void addToMessages(const std::string&);

    std::vector<std::string>* getMessages();

    VarStruct* returnVarStruct(const std::string&);
};


#endif //EX3_READINGDATA_H
