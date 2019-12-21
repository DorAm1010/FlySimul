
#include "command.h"
#include <pthread.h>
int openDataServer::execute(vector<string> vec) {
    int port = stod(vec.at(0));
    std::pthread t1(openServer, port);
    t1.join();
    return 2;
}