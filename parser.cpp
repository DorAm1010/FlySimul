//
// Created by Laliv on 23/12/2019.
//
#include <iostream>
#include "parser.h"
#include "ifCommand.h"
#include "printCommand.h"
#include "assignValue.h"
#include "sleepCommand.h"
#include "whileCommand.h"
#include "defineVar.h"
#include "openDataServer.h"
#include "connectControlClient.h"

using namespace std;

/**
 * read the text (that is already divided to words), and executes
 * the commands according to order.
 */
void Parser::Pars() {
    unordered_map<std::string, Command*> cmdMap;
    vector<string>* vector;
    Command* c;
    ReadingData* readingData = ReadingData::getInstance();
    DefineVarCommand define;
    PrintCommand print;
    AssignValueCommand assign;
    SleepCommand sleep;
    WhileCommand whle;
    IfCommand iff;
    ConnectControlClient client;
    OpenDataServer server;

    vector = readingData->getWordsVector();

    cmdMap.insert({"var", &define});
    cmdMap.insert({"Print", &print});
    cmdMap.insert({"assign", &assign});
    cmdMap.insert({"openDataServer", &server});
    cmdMap.insert({"connectControlClient", &client});
    cmdMap.insert({"Sleep", &sleep});
    cmdMap.insert({"while", &whle});
    cmdMap.insert({"if", &iff});

    readingData->setShouldRun(true);

    int index = readingData->getInd();

    while (index < vector->size()) {
        if(readingData->findInNameMap(vector->at(index)) == 1) {
            c = cmdMap.find("assign")->second;
        } else {
            if (index == 137) {
                cout<< "meow" << endl;
            }
            c = cmdMap.find(vector->at(index))->second;

            if(c == NULL) {
                throw("word is not a valid command");
            }
        }

        c->execute();

        index = readingData->getInd();
    }

    readingData->setShouldRun(false);

    dynamic_cast<OpenDataServer*>(cmdMap.at("openDataServer"))->joinThread();
    dynamic_cast<ConnectControlClient*>(cmdMap.at("connectControlClient"))->joinThread();

}