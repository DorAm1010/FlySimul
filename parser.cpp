//
// Created by Laliv on 23/12/2019.
//
#include "parser.h"
#include "readingData.h"
/* Somewhere here setShouldRun to true, set to false when done*/

Parser::Parser() {
    readingData = ReadingData::getInstance();
    this->words = readingData->getWordsVector();
    this->index = readingData->getInd();

    DefineVarCommand* define;
    PrintCommand* print;
    AssignValueCommand* assign;
    OpenDataServer* server;
    ConnectControlClient* client;
    SleepCommand* sleep;
    WhileCommand* whle;
    IfCommand* iff;

    cmdMap.insert({"var", define});
    cmdMap.insert({"Print", print});
    cmdMap.insert({"assign", assign});
    cmdMap.insert({"OpenDataServer", server});
    cmdMap.insert({"ConnectControlClient", client});
    cmdMap.insert({"Sleep", sleep});
    cmdMap.insert({"While", whle});
    cmdMap.insert({"If", iff});
}


void Parser::Pars() {
    Command* c;
    while (index < words.size()) {
        if(this->readingData->findInNameMap(words.at(index)) == 1) {
            c = cmdMap.find("assign")->second;
        } else {
            c = cmdMap.find(this->words.at(this->index))->second;

            if(c == NULL) {

            }
        }

        c->execute();
    }
}