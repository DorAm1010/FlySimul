//
// Created by Laliv on 23/12/2019.
//
#include "parser.h"
/* Somewhere here setShouldRun to true, set to false when done*/

/**
 * constructor. initialize all the information that is needed for
 * reading including the map that contains all of possible commands.
 */
Parser::Parser() {
    readingData = ReadingData::getInstance();
    this->words = readingData->getWordsVector();

    DefineVarCommand define;
    PrintCommand print;
    AssignValueCommand assign;
    SleepCommand sleep;
    WhileCommand whle;
    IfCommand iff;

    cmdMap.insert({"var", &define});
    cmdMap.insert({"Print", &print});
    cmdMap.insert({"assign", &assign});
    cmdMap.insert({"OpenDataServer", &server});
    cmdMap.insert({"ConnectControlClient", &client});
    cmdMap.insert({"Sleep", &sleep});
    cmdMap.insert({"While", &whle});
    cmdMap.insert({"If", &iff});
}


/**
 * read the text (that is already divided to words), and executes
 * the commands according to order.
 */
void Parser::Pars() {
    Command* c;
    int index = readingData->getInd();
    readingData->setShouldRun(true);
   // OpenDataServer* openDataServer = (OpenDataServer)cmdMap.find("OpenDataServer")->second;
    ConnectControlClient* connectControlClient;
    while (index < words->size()) {
        if(this->readingData->findInNameMap(words->at(index)) == 1) {
            c = cmdMap.find("assign")->second;
        } else {
            c = cmdMap.find(this->words->at(index))->second;

            if(c == NULL) {
                throw("word is not a valid command");
            }
        }

        c->execute();
        index = readingData->getInd();
    }
    readingData->setShouldRun(false);
    server.joinThread();
    client.joinThread();
}