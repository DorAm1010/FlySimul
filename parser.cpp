//
// Created by Laliv on 23/12/2019.
//
#include "parser.h"
#include "readingData.h"
/* Somewhere here setShouldRun to true, set to false when done*/

Parser::Parser(vector<string> &v) {
    this->words = v;
    this->index = 0;
}

void Parser::initCommandsMap() {
    size_t i = 0;
    ReadingData* readingData = ReadingData::getInstance();
    while (i < words.size()) {
        if (words.at(i) == "openDataServer") {
            openDataServer openDataServer;
            Command* c = &openDataServer;
            cmdMap["openDataServer"] = c;
            i++;
        } else if (words.at(i) == "connectControlClient") {
            connectControlClient connectControlClient;
            Command* c1 = &connectControlClient;
            cmdMap["connectControlClient"] = c1;
            i++;
        } else if (words.at(i) == "var") {
            i++;
            if(words.at(i) == "->"){
                i++;
                readingData->getNameToVariableMap()[words.at(i)] = VarStruct()
            }// insert to program to simulator wrap map

        }
    }
}

void Parser::Pars() {
    initCommandsMap();
    while (index < words.size()) {
        Command c = map.get(this->words.at(this->index));
    }
}