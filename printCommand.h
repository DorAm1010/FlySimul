//
// Created by dor on 1/5/20.
//

#ifndef FLYSIMUL_PRINTCOMMAND_H
#define FLYSIMUL_PRINTCOMMAND_H

#include "evaluateCommand.h"

class PrintCommand : public EvaluateCommand {
public:
    int execute();
};
#endif //FLYSIMUL_PRINTCOMMAND_H
