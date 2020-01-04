//
// Created by Laliv on 20/12/2019.
//
#include <string>

#ifndef EX3_VARSTRUCT_H
#define EX3_VARSTRUCT_H

using namespace std;

class VarStruct {
    double val;
    string sim;
public:
    void setSim(const string &sim);

    const string &getSim() const;

    void setVal(double new_val);

    double getVal();
};

#endif //EX3_VARSTRUCT_H
