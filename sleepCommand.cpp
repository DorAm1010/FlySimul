//
// Created by dor on 1/3/20.
//

#include <thread>
#include "readingData.h"
// #include "ex1.cpp"
/**
 * Sleep command makes main thread sleep for as long as input value is
 * according to its value interpreted by evaluate command.
 * */
int SleepCommand::execute() {
    ReadingData* readingData = ReadingData::getInstance();
    // increment to get to sleep func argument
    readingData->incInd(1);
    string sleep = readingData->getWordsVector()->at(readingData->getInd());
    unsigned int expression = 0;
    // double expression = (unsigned int) evaluate(sleep)
    std::this_thread::sleep_for(std::chrono::milliseconds(expression));

    // increment to have index stand at next command
    readingData->incInd(1);
}