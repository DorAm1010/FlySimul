//
// Created by Laliv on 20/12/2019.
//
#include <string>

#ifndef EX3_VARSTRUCT_H
#define EX3_VARSTRUCT_H

using namespace std;

class varStruct {
    double val;
    bool needToChangeSim;
    string sim;
    varStruct(string s, double v, bool changeSim):val(v), needToChangeSim(changeSim),sim(s) {};
};


#endif //EX3_VARSTRUCT_H
