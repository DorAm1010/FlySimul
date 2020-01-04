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
#include "Expression.h"

using namespace std;

/**
 * Interface for classes that handle a single command.
 */
class Command {
public:
    virtual void execute()=0;
};

/**
 * interface for classes that needs to evaluate expressions.
 */
class EvaluateCommand: public Command {
protected:
    double evaluate(string expString);
};

/**
 * handling open and run data server that will communicate with the fly simulator.
 */
class OpenDataServer : public Command {
    void processInfo(char* );
    void openServer(int );
public:
    void execute();
};

/**
 * handling connecting to fly simulator as a client and send to it instruction.
 */
class ConnectControlClient : public Command {
    void messageSim();
public:
    void execute();
};

/**
 * command that handles a definition of a new variable.
 */
class DefineVarCommand : public EvaluateCommand {
public:
    void execute();
};

/**
 * command that handles printing.
 */
class PrintCommand : public EvaluateCommand {
public:
    void execute();
};


/**
 * assigning new value to a existing variable.
 */
class AssignValueCommand: public EvaluateCommand {
public:
    void execute();
};

class WhileCommand: public EvaluateCommand {
public:
    void execute();
};

class IfCommand: public EvaluateCommand {
public:
    void execute();
};

class SleepCommand: public EvaluateCommand {
public:
    void execute();
};
#endif //FLYSIM_COMMAND_H