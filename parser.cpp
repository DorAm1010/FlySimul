//
// Created by Laliv on 23/12/2019.
//
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
    
    //creates all types of commands and insert them into cmdMap.
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
    cmdMap.insert({"While", &whle});
    cmdMap.insert({"If", &iff});

    readingData->setShouldRun(true);

    int index = readingData->getInd();

    //while there is still something to read, execute the next command.
    //asume we are alwayes reading a word representing a command,
    //aka all the index had been incremented correctly.
    while (index < vector->size()) {
        if(readingData->findInNameMap(vector->at(index)) == 1) {
            c = cmdMap.find("assign")->second;
        } else {
            c = cmdMap.find(vector->at(index))->second;

            if(c == NULL) {
                throw("word is not a valid command");
            }
        }

        c->execute();

        //get the new index after executing the command.
        index = readingData->getInd();
    }

    readingData->setShouldRun(false);

    //join the threads
    dynamic_cast<OpenDataServer*>(cmdMap.at("openDataServer"))->joinThread();
    dynamic_cast<ConnectControlClient*>(cmdMap.at("connectControlClient"))->joinThread();

}
