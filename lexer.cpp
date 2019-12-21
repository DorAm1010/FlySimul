#include "Lexer.h"
#include <fstream>
#include <string>

using namespace std;


vector<string> Lexer::Lex(const string fileName) {
    vector<string> words;

    ifstream objFile;
    objFile.open("fly.txt");

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


