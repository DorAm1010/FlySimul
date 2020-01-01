/**
 * Lexer class that is in charge of processing the information in input file.
 * */
#include "lexer.h"
#include <fstream>
#include <string>

using namespace std;

/**
 * This method reads line by line the input file, fileName, that has
 * a set  of instructions on how to fly the plane in the simulator.
 * */
vector<string> Lexer::lex(const string fileName) {
    vector<string> words;

    ifstream objFile;
    objFile.open(fileName);

    try {
        if (!objFile.is_open()) {
            throw ("file not opened");
        }
    } catch (const char *e) {
        throw e;
    }

    string line;

    while(std::getline(objFile, line)) {
        string word = "";
        for (auto x : line)
        {
            if (x == ' ' | x == '(' | x == ')' | x == ',' | x == '\t' | x == '=')
            {
                if(word != "") {
                    words.push_back(word);
                }
                word = "";
            }
            else
            {
                word = word + x;
            }
        }
        if(word != "") {
            words.push_back(word);
        }

    }

    objFile.close();
    return words;
}


