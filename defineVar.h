//
// Created by dor on 1/5/20.
//

#ifndef FLYSIMUL_DEFINEVAR_H
#define FLYSIMUL_DEFINEVAR_H

#include "evaluateCommand.h"
class DefineVarCommand : public EvaluateCommand {
public:
    int execute();
};
#endif //FLYSIMUL_DEFINEVAR_H
