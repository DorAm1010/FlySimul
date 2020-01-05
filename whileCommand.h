//
// Created by dor on 1/5/20.
//

#ifndef FLYSIMUL_WHILECOMMAND_H
#define FLYSIMUL_WHILECOMMAND_H

#include "ifCommand.h"

class WhileCommand : public EvaluateCommand {
public:
    IfCommand ifCommand;
    int execute();
};
#endif //FLYSIMUL_WHILECOMMAND_H
