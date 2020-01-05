//
// Created by dor on 1/5/20.
//
#ifndef FLYSIMUL_SLEEPCOMMAND_H
#define FLYSIMUL_SLEEPCOMMAND_H

#include "evaluateCommand.h"

class SleepCommand : public EvaluateCommand {
public:
    int execute();
};
#endif //FLYSIMUL_SLEEPCOMMAND_H
