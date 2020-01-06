//
// Created by dor on 1/5/20.
//

#ifndef FLYSIMUL_EVALUATECOMMAND_H
#define FLYSIMUL_EVALUATECOMMAND_H

#include "command.h"
/**
 * Father class for classes that needs to evaluate expressions.
 */
class EvaluateCommand: public Command {
protected:
    double evaluate(const std::string& expString);
};
#endif //FLYSIMUL_EVALUATECOMMAND_H
