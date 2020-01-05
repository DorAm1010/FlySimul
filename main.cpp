#include <iostream>
#include "lexer.h"
#include "parser.h"
int main(int argc, char* argv[]) {
    // TODO - compiletime argument file
    // receive input file name
    ReadingData* readingData = ReadingData::getInstance();
    //const char* file_name = argv[1];
    Lexer lexer;
    // pass file through lexer
    readingData->setWords(lexer.lex("fly.txt"));
    // parse file
    Parser parser;

    try {
        parser.Pars();
    } catch (const char* e) {
        std::cout << e << std::endl;
    }


    return 0;
}
