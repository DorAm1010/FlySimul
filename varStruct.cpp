//
// Created by dor on 12/31/19.
//
#include "varStruct.h"
using namespace std;
void VarStruct::setVal(double new_val) {
    this->val = new_val;
}

void VarStruct::setSim(const string &_sim) {
    VarStruct::sim = _sim;
}

const string &VarStruct::getSim() const {
    return sim;
}

double VarStruct::getVal() {
    return val;
}