//
// Created by dor on 1/5/20.
//

#ifndef FLYSIMUL_CONNECTCONTROLCLIENT_H
#define FLYSIMUL_CONNECTCONTROLCLIENT_H
#include <thread>
#include "command.h"
/**
 * handling connecting to fly simulator as a client and send to it instruction.
 */
class ConnectControlClient : public Command {
    void messageSim(int);
    std::thread connect_thread;
public:
    int execute();
    void joinThread();
};
#endif //FLYSIMUL_CONNECTCONTROLCLIENT_H
