//
// Created by dor on 1/3/20.
//

#include <thread>
#include "readingData.h"
#include "sleepCommand.h"
using namespace std;

/**
 * Execute sleep command.
 **/
int SleepCommand::execute() {
    ReadingData* readingData = ReadingData::getInstance();
    // increment to get to sleep func argument
    readingData->incInd(1);
    string sleep = readingData->getWordsVector()->at(readingData->getInd());
    auto expression = (unsigned int) evaluate(sleep);
    this_thread::sleep_for(std::chrono::milliseconds(expression));

    // increment to have index stand at next command
    readingData->incInd(1);
}