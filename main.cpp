#include "lexer.h"
#include "parser.h"
int main(int argc, char* argv[]) {
    // receive input file name
    const char* file_name = argv[1];
    Lexer lexer;
    // pass file through lexer
    vector<string> vector = lexer.lex(file_name);
    // parse file
    Parser parser(vector);
    return 0;
}
