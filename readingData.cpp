//
// Created by Laliv on 27/12/2019.
//

#include "readingData.h"

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


vector<string> ReadingData::getWordsVector()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance->words;
}

unordered_map<string,VarStruct*> ReadingData::getNameToVariableMap()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance->nameToVariableMap;
}

unordered_map<string,VarStruct*> ReadingData::getSimToVariableMap()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance->simToVariableMap;
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

void ReadingData::setShouldRun(bool b) {
    instance->should_run = b;
}

bool ReadingData::getShouldRun() {
    return instance->should_run;
}

void ReadingData::addToNameMap(string name, VarStruct* varStruct) {
    nameToVariableMap[name] = varStruct;
}

void ReadingData::addToSimMap(string name, VarStruct* varStruct) {
    simToVariableMap[name] = varStruct;
}

//int ReadingData::findInNameMap(const string& name) {
//    if (nameToVariableMap.find(name) != nameToVariableMap.end()) {
//        return 1;
//    }
//    return 0;
//}
//int ReadingData::findInSimMap(const string& name) {
//    if (simToVariableMap.find(name) != simToVariableMap.end()) {
//        return 1;
//    }
//    return 0;
//}
//void ReadingData::updateInNameMap(const string& name, double val) {
//    nameToVariableMap.find(name)->second->setVal(val);
//}
//
//void ReadingData::updateInSimMap(const string& name, double val) {
//    simToVariableMap.find(name)->second->setVal(val);
//}

/**
 * This method gets a vector of double type values as input
 * and by iterating over the simulator to variable map, for every element in
 * the map, i.e. <key, value> pair, it gets its relevant simulator path name,
 * represented as sim, then it gets the appropriate index it has in the values
 * sent by the simulator, and with the help of the indexMap that was initialized with
 * a pair of <key, value> pairs where the key is the sim path and the value is its
 * appropriate index, the method will set the appropriate value in the sim to var map.
 * */
void ReadingData::updateFromSimulator (vector<double> vector) {
    int index;
    string sim;
    for (auto& element: simToVariableMap) {
        sim = element.second->getSim();
        index = indexMap.find(sim)->second;
        element.second->setVal(vector.at(index));
    }
}