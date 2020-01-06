#include "Lexer.h"
#include <fstream>
#include <string>

using namespace std;

/**
 * get a file and breaks all the text into separate parts.
 * @param fileName the file name.
 * @return vector of words.
 */
vector<string> Lexer::Lex(const string fileName) {
    vector<string> words;

    ifstream objFile;
    objFile.open("fly.txt");

    //try to open file
    try {
        if (!objFile.is_open()) {
            throw ("file not opened");
        }
    } catch (const char *e) {
        throw e;
    }

    string line;

    bool inExp, inString, inSimAddress;

    //read line by line
    while(std::getline(objFile, line)) {
        string word = "";
        inExp = false;
        inString = false;
        inSimAddress = false;
        //read each letter
        for (auto x : line)
        {
            if(x == '{') {
                inExp = false;
            }
            if (inExp == false && inString == false && (x == ' ' | x == '(' | x == ')' | x == ',' | x == '\t' | x == '=' | (x == '{' && word != "")))
            {
                if(x == '=') {
                    inExp = true;
                    word = word + x;
                }

                if(x == '{') {
                    words.push_back(word);
                    word = x;
                }

                if(word == "sim") {
                    inSimAddress = true;
                }

                if(word != "" && word != "sim") {
                    words.push_back(word);
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
                } else if(word != "" || x != '/') {

                    if(!inSimAddress || x != '\"') {
                        word = word + x;
                    }
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


