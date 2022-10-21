//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_COMMENT_H
#define LEXER_CPP_COMMENT_H

#include "Automaton.h"

class COMMENT : public Automaton
{
public:
    COMMENT() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '#') {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    }

    void S1(const std::string &input) {
        if (input[index] == '|') {
            inputRead++;
            index++;
            S3(input);
        } else if(input[index] != '|' && input[index] != '\n') {
            inputRead++;
            index++;
            S2(input);
        } else if (input[index] == '\n') {
            index++;
        }
        else {
            Serr();
        }
    }

    void S2(const std::string &input) {
        if (input[index] == '\n') {
            index++;
        }
        else if (input[index] != '\n') {
            inputRead++;
            index++;
            S2(input);
        }
        else {
            Serr();
        }
    }

    void S3(const std::string &input) {
        if (index >= input.size()) {
            type = TokenType::UNDEFINED;
            return;
        }
        else if (input[index] == '|') {
            inputRead++;
            index++;
            S4(input);
        }
        else if (input[index] != '|') {
            if (input[index] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S3(input);
        }
        else {
            Serr();
        }
    }

    void S4(const std::string &input) {
        if (index >= input.size()) {
            type = TokenType::UNDEFINED;
            return;
        }
        else if (input[index] == '#') {
            inputRead++;
            index++;
            //ends block comment, learn accept state and erase the string
        }
        else if (input[index] != '#' && input[index] != '\0') {
            if (input[index] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S3(input);
        }
        else {
            Serr();
        }
    }
};

#endif //LEXER_CPP_COMMENT_H
