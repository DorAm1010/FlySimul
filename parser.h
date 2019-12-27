//
// Created by Laliv on 23/12/2019.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H

#include <string>
#include <vector>

using namespace std;

class Parser{
public:
    static int index;
    static vector<string> words;
    void Pars();
    Parser(vector<string>& v){ words = v; index = 0;};
};
#endif //EX3_PARSER_H
