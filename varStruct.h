//
// Created by Laliv on 20/12/2019.
//
#include <string>

#ifndef EX3_VARSTRUCT_H
#define EX3_VARSTRUCT_H

using namespace std;

class VarStruct {
public:
    double val;
    bool needToChangeSim;
    string sim;
public:
    VarStruct(string s, double v, bool changeSim);
    void setVal(double new_val);
};

#endif //EX3_VARSTRUCT_H
