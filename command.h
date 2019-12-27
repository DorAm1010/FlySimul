
//
// Created by dor on 12/20/19.
//

#ifndef FLYSIM_COMMAND_H
#define FLYSIM_COMMAND_H

#include <string>
#include <vector>
#include <map>
#include "varStruct.h"

using namespace std;
class Command {
protected:
    virtual int execute()=0;
public:
    static map<string,varStruct> varMap;
};

class openDataServer : public Command {
    int execute();
};

class DefineVarCommand : public Command {
    int execute();
};
#endif //FLYSIM_COMMAND_H