//
// Created by dor on 12/31/19.
//
#include "varStruct.h"
using namespace std;
void VarStruct::setVal(double new_val) {
    val = new_val;
}

void VarStruct::setSim(string _sim) {
    sim = _sim;
}

string VarStruct::getSim() const {
    return sim;
}

double VarStruct::getVal() {
    return val;
}