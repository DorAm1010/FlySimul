//
// Created by Laliv on 03/01/2020.
//
#include "command.h"
#include "readingData.h"
#include "Interpreter.h"

double EvaluateCommand::evaluate(string expString) {

        Expression* expression;
        ReadingData* rd = ReadingData::getInstance();
        unordered_map<string, VarStruct*> VarMap = rd->getNameToVariableMap();
        Interpreter* interpreter = new Interpreter();

        string vars = "";
        bool isFirst = true;

        for(auto itr = VarMap.cbegin(); itr != VarMap.cend(); ++itr) {
            if(expString.find(itr->first) != std::string::npos) {
                if(isFirst) {
                    vars += itr->first + "=" + to_string(itr->second->getVal());
                    isFirst = false;
                } else {
                    vars += ";" + itr->first + "=" + to_string(itr->second->getVal());
                }
            }
        }

        interpreter->setVariables(vars);
        expression = interpreter->interpret(expString);
        return expression->calculate();



}

