/**
 * Lexer header.
 * */
#ifndef FLYSIMUL_COMMAND_H
#define FLYSIMUL_COMMAND_H

#include <string>
#include <vector>

class Lexer{
public:
    std::vector<std::string> lex(std::string fileName);
};
#endif // FlySimul lexer.h