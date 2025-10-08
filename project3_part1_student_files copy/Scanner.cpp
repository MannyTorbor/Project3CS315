//
// Created by Ali Kooshesh on 9/27/25.
//

#include "Scanner.hpp"

#include <utility>
#include <iostream>
#include <fstream>

#include "utils.hpp"
#include <cctype>

using namespace std;


Scanner::Scanner(filesystem::path inputPath) : inputPath_(inputPath) {}

string Scanner::readWord(istream& in) {
    string word;
    char ch;

    while (in.get(ch)) {
        if (isalpha(ch)) {
            word += tolower(ch);
        } else if (ch == '\'' && !word.empty()) {
            int nextChar = in.peek();
            if (isalpha(nextChar)) {
                word += '\'';
            } else {
                in.putback(ch);
                break;
            }
        } else {
            if (!word.empty()) {
                in.putback(ch);
                break;
            }
        }
    }

    return word;
}

error_type Scanner::tokenize(vector<string>& words) {
    ifstream inputFile(inputPath_);
    if (!inputFile.is_open()) {
        return FILE_NOT_FOUND;
    }

    words.clear();
    string word;

    while (!(word = readWord(inputFile)).empty()) {
        words.push_back(word);
    }

    inputFile.close();
    return NO_ERROR;
}

error_type Scanner::tokenize(vector<string>& words,
                             const filesystem::path& outputFile) {
    error_type result = tokenize(words);
    if (result != NO_ERROR) {
        return result;
    }

    return writeVectorToFile(outputFile.string(), words);
}
