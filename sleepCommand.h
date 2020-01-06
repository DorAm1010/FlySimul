//
// Created by dor on 1/5/20.
//
#ifndef FLYSIMUL_SLEEPCOMMAND_H
#define FLYSIMUL_SLEEPCOMMAND_H

#include "evaluateCommand.h"
/**
 * Sleep command makes main thread sleep for as long as input value is
 * according to its value interpreted by evaluate command.
 * */
class SleepCommand : public EvaluateCommand {
public:
    int execute();
};
#endif //FLYSIMUL_SLEEPCOMMAND_H
