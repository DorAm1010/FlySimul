//
// Created by dor on 12/31/19.
//
#include "varStruct.h"

void VarStruct::setVal(double new_val) {
    this->val = new_val;
}

void VarStruct::setNeedToChangeSim(bool needToChangeSim) {
    VarStruct::needToChangeSim = needToChangeSim;
}

void VarStruct::setSim(const string &sim) {
    VarStruct::sim = sim;
}

const string &VarStruct::getSim() const {
    return sim;
}

bool VarStruct::isNeedToChangeSim() const {
    return needToChangeSim;
}

double VarStruct::getVal() {
    return val;
}
