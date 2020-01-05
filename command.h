/**
 * Command header containing declarations of command abstract class
 * implementing classes, and of course the command abstract class itself.
 * */

#ifndef FLYSIM_COMMAND_H
#define FLYSIM_COMMAND_H

#include <string>
#include <vector>
#include <mutex>
#include "Expression.h"

using namespace std;

/**
 * Interface for classes that handle a single command.
 */
class Command {
public:
    virtual int execute()=0;
};

/**
 * interface for classes that needs to evaluate expressions.
 */
class EvaluateCommand: public Command {
protected:
    double evaluate(const string& expString);
};

class OpenDataServer : public Command {
    void processInfo(char* );
    void openServer(int );
    std::thread open_server_thread;
public:
    int execute();
    void joinThread();
};

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

/**
 * assigning new value to a existing variable.
 */
class AssignValueCommand: public EvaluateCommand {
public:
    int execute();
};

class DefineVarCommand : public EvaluateCommand {
public:
    int execute();
};

class PrintCommand : public EvaluateCommand {
public:
    int execute();
};

class SleepCommand : public EvaluateCommand {
public:
    int execute();
};

class IfCommand : public EvaluateCommand {
    bool condition;
    bool verify();
public:
    int execute();
};

class WhileCommand : public EvaluateCommand {
public:
    IfCommand ifCommand;
    int execute();
};
#endif //FLYSIM_COMMAND_H