//
// Created by dor on 1/5/20.
//

#ifndef FLYSIMUL_OPENDATASERVER_H
#define FLYSIMUL_OPENDATASERVER_H
#include <thread>
#include "command.h"

class OpenDataServer : public Command {
    void processInfo(char* );
    void openServer(int );
    std::thread open_server_thread;
public:
    int execute();
    void joinThread();
};

#endif //FLYSIMUL_OPENDATASERVER_H
