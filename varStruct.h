//
// Created by Laliv on 20/12/2019.
//
#ifndef FLYSIMUL_VARSTRUCT_H
#define FLYSIMUL_VARSTRUCT_H

#include <string>

class VarStruct {
    double val;
    std::string sim;
public:
    void setSim(const std::string &sim);

    const std::string &getSim() const;

    void setVal(double new_val);

    double getVal();
};

#endif //EX3_VARSTRUCT_H
