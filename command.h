//
// Created by dor on 12/20/19.
//

#ifndef FLYSIM_COMMAND_H
#define FLYSIM_COMMAND_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Command {
protected:
    virtual int execute()=0;
};

class openDataServer : public Command {
    void processInfo(char* );
    void openServer(int );
    int execute();
};

class connectClientImpl : public Command {
    int execute();
    void messageSim(int );
};
#endif //FLYSIM_COMMAND_H
