//
// Created by dor on 12/31/19.
//
#include "varStruct.h"
using namespace std;

/**
* set the value of the variable.
* @param new_val the new value of the variable.
**/
void VarStruct::setVal(double new_val) {
    this->val = new_val;
}

/**
* set the simulator address of the variable.
* @param _sim the new simulator address of the variable.
**/
void VarStruct::setSim(const string &_sim) {
    VarStruct::sim = _sim;
}

/**
* get the simulator address.
* @return simulator address.
**/
const string &VarStruct::getSim() const {
    return sim;
}

/**
* get the variable value.
* @return variable value.
**/
double VarStruct::getVal() {
    return val;
}
