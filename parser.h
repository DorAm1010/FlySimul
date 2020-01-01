//
// Created by Laliv on 23/12/2019.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H

#include "readingData.h"

using namespace std;

class Parser{
    void initCommandsMap();
public:
    int index;
    unordered_map<string, Command*> cmdMap;
    vector<string> words;
    void Pars();
    Parser(vector<string>& v);
};
#endif //EX3_PARSER_H
