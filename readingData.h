//
// Created by Laliv on 27/12/2019.
//

#ifndef EX3_READINGDATA_H
#define EX3_READINGDATA_H

#include "varStruct.h"
#include "command.h"

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

public:
/* Static access method. */
    /**
     * @return the only object of type ReadingData.
     */
    static ReadingData *getInstance();

    /**
     * @return map in which the key is the variable name and the value
     * is a struct that keep all the information about that variable.
     */
    unordered_map<string, VarStruct *> getNameToVariableMap();

    /**
     * @return  map in which the key is the variable simulator address and the value
     * is a struct that keep all the information about that variable.
     */
    unordered_map<string, VarStruct *> getSimToVariableMap();

    /**
     * @return vector of words, aka the text after lexering.
     */
    vector<string> getWordsVector();

    /**
     * gives an option to reset the text we read.
     * @param v new words vector.
     */
    void setWords(vector<string> v);

    /**
     * @return index of the word we are now reading.
     */
    int getInd();

    /**
     * @param add increase the index of reading by add.
     */
    void incInd(int add);

    /**
     * flag that represent if there is still something to read or should we stop.
     * @param b true if starting to read, false if we are done.
     */
    void setShouldRun(bool b);

    /**
     * flag that represent if there is still something to read or should we stop.
     * @return b true if we are still reading, false otherwise.
     */
    bool getShouldRun();

    /**
     * adds new variable to the <variableName, VarStruct> map.
     */
    void addToNameMap(string, VarStruct *);

    void addToSimMap(string, VarStruct *);

    int findInNameMap(const string&);
//
//    int findInSimMap(const string&);
//
    void updateInNameMap(const string&, double);
//
//    void updateInSimMap(const string&, double);

    VarStruct* returnVarStruct(string);

    void updateFromSimulator(vector<double>);

    void addToMassages(string) {};
};


#endif //EX3_READINGDATA_H
