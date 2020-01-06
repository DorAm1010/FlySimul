#include <queue>
#include <iostream>
#include <map>
#include <vector>
#include "Expression.h"

/**
* this class interpret a string that represent an expression,
* into a real expression that can be evaluated after.
* in case of variables in expression, assign values to 
* all variables using setVariables method.
**/
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
