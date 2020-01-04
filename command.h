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
    double evaluate(string expString);
};

class OpenDataServer : public Command {
    void processInfo(char* );
    void openServer(int );
public:
    int execute();
};

/**
 * handling connecting to fly simulator as a client and send to it instruction.
 */
class ConnectControlClient : public Command {
    void messageSim(int);
public:
    int execute();
};

/**
 * assigning new value to a existing variable.
 */
class AssignValueCommand: public EvaluateCommand {
    double evaluate(string);
public:
    int execute();
};

class DefineVarCommand : public EvaluateCommand {
    double evaluate(string);

public:
    int execute();
};

class PrintCommand : public EvaluateCommand {
    double evaluate(string);

public:
    int execute();
};

class SleepCommand : public EvaluateCommand {
    double evaluate(string);

public:
    int execute();
};

class IfCommand : public EvaluateCommand {
    bool condition;
    bool verify();
    double evaluate(string);

public:
    int execute();
};

class WhileCommand : public EvaluateCommand {
    double evaluate(string);

public:
    IfCommand ifCommand;
    int execute();
};
#endif //FLYSIM_COMMAND_H