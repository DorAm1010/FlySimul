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
    virtual int execute(vector<string> )=0;
};

class openDataServer : public Command {
    unordered_map<string, int> val_map;
    void processInfo(char* );
    void openServer(int );
    int execute(vector<string> );
};
#endif //FLYSIM_COMMAND_H
