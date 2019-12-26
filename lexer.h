#ifndef FLYSIM_COMMAND_H
#define FLYSIM_COMMAND_H

#include <string>
#include <vector>
using namespace std;

class Lexer{
private:

public:
    vector<string> lex(const string fileName);
};
#endif // FlySimul lexer.h