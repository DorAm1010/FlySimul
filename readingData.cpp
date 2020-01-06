//
// Created by Laliv on 27/12/2019.
//

#include <iostream>
#include <mutex>
#include "readingData.h"

using namespace std;

/* Null, because instance will be initialized on demand. */
ReadingData* ReadingData::instance = 0;

ReadingData* ReadingData::getInstance()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance;
}

/**
 * Set name to index map, i.e. information sent from simulator,
 * this map assists the sim to variable map with the update.
 **/
ReadingData::ReadingData()
{
    nameToIndexMap["instrumentation/airspeed-indicator/indicated-speed-kt"] = 1;
    nameToIndexMap["sim/time/warp"] = 2;
    nameToIndexMap["controls/switches/magneto"] = 3;
    nameToIndexMap["instrumentation/heading-indicator/offset-deg"] = 4;
    nameToIndexMap["instrumentation/altimeter/indicated-altitude-ft"] = 5;
    nameToIndexMap["instrumentation/altimeter/pressure-alt-ft"] = 6;
    nameToIndexMap["instrumentation/attitude-indicator/indicated-pitch-deg"] = 7;
    nameToIndexMap["instrumentation/attitude-indicator/indicated-roll-deg"] = 8;
    nameToIndexMap["instrumentation/attitude-indicator/internal-pitch-deg"] = 9;
    nameToIndexMap["instrumentation/attitude-indicator/internal-roll-deg"] = 10;
    nameToIndexMap["instrumentation/encoder/indicated-altitude-ft"] = 11;
    nameToIndexMap["instrumentation/encoder/pressure-alt-ft"] = 12;
    nameToIndexMap["instrumentation/gps/indicated-altitude-ft"] = 13;
    nameToIndexMap["instrumentation/gps/indicated-ground-speed-kt"] = 14;
    nameToIndexMap["instrumentation/gps/indicated-vertical-speed"] = 15;
    nameToIndexMap["instrumentation/heading-indicator/indicated-heading-deg"] = 16;
    nameToIndexMap["instrumentation/magnetic-compass/indicated-heading-deg"] = 17;
    nameToIndexMap["instrumentation/slip-skid-ball/indicated-slip-skid"] = 18;
    nameToIndexMap["instrumentation/turn-indicator/indicated-turn-rate"] = 19;
    nameToIndexMap["instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 20;
    nameToIndexMap["controls/flight/aileron"] = 21;
    nameToIndexMap["controls/flight/elevator"] = 22;
    nameToIndexMap["controls/flight/rudder"] = 23;
    nameToIndexMap["controls/flight/flaps"] = 24;
    nameToIndexMap["controls/engines/engine/throttle"] = 25;
    nameToIndexMap["controls/engines/current-engine/throttle"] = 26;
    nameToIndexMap["controls/switches/master-avionics"] = 27;
    nameToIndexMap["controls/switches/starter"] = 28;
    nameToIndexMap["engines/active-engine/auto-start"] = 29;
    nameToIndexMap["controls/flight/speedbrake"] =  30;
    nameToIndexMap["sim/model/c172p/brake-parking"] = 31;
    nameToIndexMap["controls/engines/engine/primer"] = 32;
    nameToIndexMap["controls/engines/current-engine/mixture"] = 33;
    nameToIndexMap["controls/switches/master-bat"] = 34;
    nameToIndexMap["controls/switches/master-alt"] = 35;
    nameToIndexMap["engines/engine/rpm"] = 36;
}


vector<string>* ReadingData::getWordsVector()
{
    return &instance->words;
}

unordered_map<string,VarStruct*>* ReadingData::getNameToVariableMap()
{
    return &instance->nameToVariableMap;
}

unordered_map<string,VarStruct*>* ReadingData::getSimMap()
{
    return &instance->simToVariableMap;
}

void ReadingData::setWords(vector<string> v)
{
    instance->words = v;
}

int ReadingData::getInd()
{
   return instance->index;
}

void ReadingData::incInd(int add)
{
    instance->index += add;
}

void ReadingData::setInd(int i) {
    instance->index = i;
}

void ReadingData::setShouldRun(bool b) {
    instance->should_run = b;
}

bool ReadingData::getShouldRun() {
    return instance->should_run;
}

void ReadingData::addToNameMap(const string& name, VarStruct* varStruct) {
    nameToVariableMap[name] = varStruct;
}

void ReadingData::addToSimMap(const string& name, VarStruct* varStruct) {
    simToVariableMap[name] = varStruct;
}

void ReadingData::addToPrivateVarsMap(const string& name, VarStruct* varStruct) {
    privateVarsMap[name] = varStruct;
}

int ReadingData::findInNameMap(const string& name) {
    if (nameToVariableMap.find(name) != nameToVariableMap.end()) {
        return 1;
    }
    return 0;
}
int ReadingData::findInPrivateVarsMap(const string& name) {
    if (privateVarsMap.find(name) != privateVarsMap.end()) {
        return 1;
    }
    return 0;
}
void ReadingData::updateInNameMap(const string& name, double val) {
    nameToVariableMap.find(name)->second->setVal(val);
}

void ReadingData::updateInPrivateVarsMap(const string& name, double val) {
    privateVarsMap.find(name)->second->setVal(val);
}

/**
 * This method gets a vector of double type values as input
 * and by iterating over the simulator to variable map, for every element in
 * the map, i.e. <key, value> pair, it gets its relevant simulator path name,
 * represented as sim, then it gets the appropriate index it has in the values
 * sent by the simulator, and with the help of the indexMap that was initialized with
 * a pair of <key, value> pairs where the key is the sim path and the value is its
 * appropriate index, the method will set the appropriate value in the sim to var map.
 * */
void ReadingData::updateFromSimulator (vector<double>* vector) {
    int newValIndex;
    string sim;
    mutex mutex;

    for (auto& element: simToVariableMap) {
        mutex.lock();
        sim = element.second->getSim();
        newValIndex = nameToIndexMap.find(sim)->second - 1;
        element.second->setVal(vector->at(newValIndex));
        mutex.unlock();
    }
}

queue<string>* ReadingData::getMessages() {
    return &instance->messages;
}

void ReadingData::addToMessages(const string& message) {
    messages.push(message);
}

VarStruct* ReadingData::returnVarStruct(const string& var) {
    return nameToVariableMap.find(var)->second;
}

std::unordered_map<std::string, VarStruct *> *ReadingData::getPrivateVarsMap() {
    return &instance->privateVarsMap;
}
