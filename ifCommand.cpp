//
// Created by dor on 1/3/20.
//
#include "readingData.h"


int IfCommand::execute() {
    unordered_map<string, Command*> commands;
    ReadingData* readingData = ReadingData::getInstance();
    PrintCommand printCommand;
    SleepCommand sleepCommand;
    // AssignValueCommand assignValueCommand;
    commands.insert({{"Print", &printCommand}, {"Sleep", &sleepCommand}});
    for (auto& element : *readingData->getNameToVariableMap()) {
        // commands[element.first] = &assignValueCommand;
    }
    condition = verify();

    if (condition) {
        while (readingData->getWordsVector()->at(readingData->getInd()) != "}") {
            if (commands.find(readingData->getWordsVector()->at(readingData->getInd())) != commands.end()) {
                commands.at(readingData->getWordsVector()->at(readingData->getInd()))->execute();
            } else {
                readingData->incInd(1);
            }
        }
        return 1;
    } else {
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
    readingData->incInd(1);
    string left_expression = readingData->getWordsVector()->at(readingData->getInd());

    readingData->incInd(1);
    string condition_operator = readingData->getWordsVector()->at(readingData->getInd());

    readingData->incInd(1);
    string right_expression = readingData->getWordsVector()->at(readingData->getInd());

//    double left_ex_val = evaluate(left_expression);
//    double right_ex_val = evaluate(right_expression);
//
//    if (condition_operator == ">"){
//        if (left_ex_val > right_ex_val) {
//            condition_is_maintained = true;
//        }
//    } else if (condition_operator == ">="){
//        if (left_ex_val >= right_ex_val) {
//            condition_is_maintained = true;
//        }
//    } else if (condition_operator == "<"){
//        if (left_ex_val < right_ex_val) {
//            condition_is_maintained = true;
//        }
//    } else if (condition_operator == "<="){
//        if (left_ex_val <= right_ex_val) {
//            condition_is_maintained = true;
//        }
//    } else if (condition_operator == "=="){
//        if (left_ex_val == right_ex_val) {
//            condition_is_maintained = true;
//        }
//    } else if (condition_operator == "!="){
//        if (left_ex_val != right_ex_val) {
//            condition_is_maintained = true;
//        }
//    }
}