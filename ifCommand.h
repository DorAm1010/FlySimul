//
// Created by dor on 1/5/20.
//

#ifndef FLYSIMUL_IFCOMMAND_H
#define FLYSIMUL_IFCOMMAND_H

#include "evaluateCommand.h"

class IfCommand : public EvaluateCommand {
    bool condition;
    bool verify();
public:
    int execute();
};
#endif //FLYSIMUL_IFCOMMAND_H
