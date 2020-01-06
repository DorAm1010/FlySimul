//
// Created by dor on 1/3/20.
//
#include <mutex>
#include "readingData.h"
#include "ifCommand.h"
#include "printCommand.h"
#include "assignValue.h"
#include "sleepCommand.h"

using namespace std;
/**
 * Execute every command in scope from opening curly brackets
 * until closing brackets.
 **/
int IfCommand::execute() {
    unordered_map<string, Command*> commands;
    mutex mutex;
    string command;
    ReadingData* readingData = ReadingData::getInstance();
    PrintCommand printCommand;
    SleepCommand sleepCommand;
    AssignValueCommand assignValueCommand;
    // insert every command this if commands' execute needs to know
    commands.insert({{"Print", &printCommand}, {"Sleep", &sleepCommand}});
    for (auto& element : *readingData->getNameToVariableMap()) {
        mutex.lock();
        commands[element.first] = &assignValueCommand;
        mutex.unlock();
    }
    for (auto& element : *readingData->getPrivateVarsMap()) {
        mutex.lock();
        commands[element.first] = &assignValueCommand;
        mutex.unlock();
    }

    condition = false;
    condition = verify();

    if (condition) {
        // while scope hasn't ended
        command = readingData->getWordsVector()->at(readingData->getInd());
        while (command != "}") {
            // if command is found at map
            if (commands.find(command) != commands.end()) {
                // every command increments to index in the vector
                // appropriately to what it needs to use, so all command
                // string should be is a string of a command
                commands.at(command)->execute();
                command = readingData->getWordsVector()->at(readingData->getInd());
            } else {
                throw "If command error";
            }
        }
        return 1;
    } else {
        // skip if scope
        while (readingData->getWordsVector()->at(readingData->getInd()) != "}") {
            readingData->incInd(1);
        }
        readingData->incInd(1);
        return 0;
    }
}

/**
 * Verify condition is maintained.
 * */
bool IfCommand::verify() {

    ReadingData *readingData = ReadingData::getInstance();
    string left_expression = readingData->getWordsVector()->at(readingData->getInd());
    readingData->incInd(1);

    string condition_operator = readingData->getWordsVector()->at(readingData->getInd());
    readingData->incInd(1);

    string right_expression = readingData->getWordsVector()->at(readingData->getInd());
    readingData->incInd(2);

    double left_ex_val = evaluate(left_expression);
    double right_ex_val = evaluate(right_expression);

    if (condition_operator == ">"){
        if (left_ex_val > right_ex_val) {
            return true;
        }
    } else if (condition_operator == ">="){
        if (left_ex_val >= right_ex_val) {
            return true;
        }
    } else if (condition_operator == "<"){
        if (left_ex_val < right_ex_val) {
            return true;
        }
    } else if (condition_operator == "<="){
        if (left_ex_val <= right_ex_val) {
            return true;
        }
    } else if (condition_operator == "=="){
        if (left_ex_val == right_ex_val) {
            return true;
        }
    } else if (condition_operator == "!="){
        if (left_ex_val != right_ex_val) {
            return true;
        }
    }
    return false;
}