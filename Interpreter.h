#include <queue>
#include <iostream>
#include <map>
#include <vector>
#include "Expression.h"

class Interpreter {

private:
    std::vector <double>* valuesVec;
    std::vector <std::string>* variableVec;
    int operatorPre(std::string c);
    Expression* produceExpression(std::queue <std::string> q);
public :
    Interpreter();
    Expression* interpret(std::string exString);
    void setVariables(std::string s);
    virtual ~Interpreter();
};