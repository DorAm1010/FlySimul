//
// Created by Laliv on 03/01/2020.
//
#include <mutex>
#include "readingData.h"
#include "Interpreter.h"
#include "evaluateCommand.h"
using namespace std;

/**
* this method evaluates the value of an expression, according to the variables
* values that are saved in the maps from ReadingData. the expression is
* given as a string.
* @param expString the string representing the expression.
* the string should not contain spaces, and can contain
* unary minus or plus for a number or a variable.
**/
double EvaluateCommand::evaluate(const string& expString) {

        Expression* expression;
        ReadingData* rd = ReadingData::getInstance();
        mutex mutex;
        unordered_map<string, VarStruct*>* VarMap = rd->getNameToVariableMap();
        Interpreter* interpreter = new Interpreter();

        string vars = "";
        bool isFirst = true;

        for(auto itr = VarMap->cbegin(); itr != VarMap->cend(); ++itr) {
            if(expString.find(itr->first) != std::string::npos) {
                if(isFirst) {
                    mutex.lock();
                    vars += itr->first + "=" + to_string(itr->second->getVal());
                    mutex.unlock();
                    isFirst = false;
                } else {
                    mutex.lock();
                    vars += ";" + itr->first + "=" + to_string(itr->second->getVal());
                    mutex.unlock();
                }
            }
        }

        interpreter->setVariables(vars);
        expression = interpreter->interpret(expString);
        return expression->calculate();
}

