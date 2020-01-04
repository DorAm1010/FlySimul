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
        bool inExp = false;
        bool inString = false;
        for (auto x : line)
        {
            if (inExp == false && inString == false && (x == ' ' | x == '(' | x == ')' | x == ',' | x == '\t' | x == '='))
            {
                if(x == '=') {
                    inExp = true;
                    word = word + x;
                }

                if(word != "" && word != "sim") {
                    words.push_back(word);
                  //  inExp = false;
                    //inString = false;
                }
                word = "";

            }
            else
            {
                if(x == '\"') {
                    if(inString == false) {
                        inString = true;
                    } else {
                        inString = false;
                    }
                }
                if(inExp == true) {
                    if(x != ' ') {
                        word = word + x;
                    }
                }else if(word != "\"" | x != '/') {
                    word = word + x;
                }
            }
        }
        if(word != "") {
            words.push_back(word);
        }

    }

    objFile.close();
    return words;
}


