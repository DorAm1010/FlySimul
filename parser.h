//
// Created by Laliv on 23/12/2019.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H

#include "readingData.h"

using namespace std;

class Parser{
private:
    int index;
    ReadingData* readingData;
    unordered_map<string, Command*> cmdMap;
    vector<string> words;
public:
    void Pars();
    Parser();
};
#endif //EX3_PARSER_H
