#include <iostream>
#include "lexer.h"
#include "parser.h"
int main(int argc, char* argv[]) {
    // TODO - compile time argument file
    // receive input file name
    ReadingData* readingData = ReadingData::getInstance();
    const char* file_name = argv[0];
    Lexer lexer;
    // pass file through lexer
    readingData->setWords(lexer.lex(file_name));
    // parse file
    Parser parser;

    try {
        parser.Pars();
    } catch (const char* e) {
        std::cout << e << std::endl;
    }


    return 0;
}
