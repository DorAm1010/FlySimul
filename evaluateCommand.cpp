//
// Created by Laliv on 03/01/2020.
//
#include <mutex>
#include "readingData.h"
#include "Interpreter.h"
#include "evaluateCommand.h"
using namespace std;
/**
 * Evaluate input expression string to a double type.
 **/
double EvaluateCommand::evaluate(const string& expString) {
        Expression* expression;
        ReadingData* rd = ReadingData::getInstance();
        mutex mutex;
        unordered_map<string, VarStruct*>* VarMap = rd->getNameToVariableMap();
        unordered_map<string, VarStruct*>* privateVarMap = rd->getPrivateVarsMap();
        unordered_map<string, VarStruct*>* SimMap = rd->getSimMap();
        Interpreter* interpreter = new Interpreter();

        string vars = "";
        bool isFirst = true;

        for(auto itr = VarMap->cbegin(); itr != VarMap->cend(); ++itr) {
            mutex.lock();
            if(expString.find(itr->first) != std::string::npos) {
                if(isFirst) {
                    vars += itr->first + "=" + to_string(itr->second->getVal());
                    isFirst = false;
                } else {
                    vars += ";" + itr->first + "=" + to_string(itr->second->getVal());
                }
            }
            mutex.unlock();
        }

    for(auto itr = privateVarMap->cbegin(); itr != privateVarMap->cend(); ++itr) {
        mutex.lock();
        if(expString.find(itr->first) != std::string::npos) {
            if(isFirst) {
                vars += itr->first + "=" + to_string(itr->second->getVal());
                isFirst = false;
            } else {
                vars += ";" + itr->first + "=" + to_string(itr->second->getVal());
            }
        }
        mutex.unlock();
    }

    for(auto itr = SimMap->cbegin(); itr != SimMap->cend(); ++itr) {
        mutex.lock();
        if(expString.find(itr->first) != std::string::npos) {
            if(isFirst) {
                vars += itr->first + "=" + to_string(itr->second->getVal());
                isFirst = false;
            } else {
                vars += ";" + itr->first + "=" + to_string(itr->second->getVal());
            }
        }
        mutex.unlock();
    }

        interpreter->setVariables(vars);
        expression = interpreter->interpret(expString);
        return expression->calculate();
}

