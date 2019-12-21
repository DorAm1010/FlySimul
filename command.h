//
// Created by dor on 12/20/19.
//

#ifndef FLYSIM_COMMAND_H
#define FLYSIM_COMMAND_H

#include <string>
#include <vector>

using namespace std;
class Command {
protected:
    virtual int execute(vector<string> )=0;
};

class openDataServer : public Command {
    int execute(vector<string> );
};
#endif //FLYSIM_COMMAND_H
