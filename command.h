/**
 * Command header containing declarations of command abstract class
 * implementing classes, and of course the command abstract class itself.
 * */

#ifndef FLYSIM_COMMAND_H
#define FLYSIM_COMMAND_H

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include "mutex"

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

class connectControlClient : public Command {
    int execute();
    void messageSim(int );
};

class DefineVarCommand : public Command {
    int execute();
};
#endif //FLYSIM_COMMAND_H