//
// Created by dor on 1/3/20.
//
#include "readingData.h"
#include "whileCommand.h"

/**
 * The while command executes rely on its if command member field
 * because a while command is essentially an if command repeating itself
 * while its condition is maintained.
 * */
int WhileCommand::execute() {
    ReadingData* readingData = ReadingData::getInstance();
    int start_index, current_index;
    // get index to point to start of condition
    readingData->incInd(1);
    start_index = readingData->getInd();
    // if command execute returns 1 if condition worked 0 otherwise
    while (ifCommand.execute()) {
        // index currently pointed to after while scope was executed
        current_index = readingData->getInd();
        // essentially decrementing the index to point back to where condition starts
        // if start_index is x and current is y -> z = y + (x - y) = x = start_index
        readingData->incInd(start_index - current_index);
    }
    return 0;
}