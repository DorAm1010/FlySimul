//
// Created by dor on 1/5/20.
//

#ifndef FLYSIMUL_ASSIGNVALUE_H
#define FLYSIMUL_ASSIGNVALUE_H

#include "evaluateCommand.h"

/**
 * assigning new value to a existing variable.
 */
class AssignValueCommand: public EvaluateCommand {
public:
    int execute();
};
#endif //FLYSIMUL_ASSIGNVALUE_H
