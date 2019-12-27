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
{}


vector<string>* ReadingData::getWordsVector()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance->words;
}

unordered_map<string,varStruct>* ReadingData::getNameToVariableMap()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance->nameToVariableMap;
}

unordered_map<string,varStruct>* ReadingData::getSimToVariableMap()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance->simToVariableMap;
}

void ReadingData::setWords(vector<string>* v)
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