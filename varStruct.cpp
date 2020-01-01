//
// Created by dor on 12/31/19.
//
#include "varStruct.h"

VarStruct::VarStruct(string _s, double _val, bool _b) {
    this->needToChangeSim = _b;
    this->val = _val;
    this->sim = _s;
}

void VarStruct::setVal(double new_val) {
    this->val = new_val;
}
