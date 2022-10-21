//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_RULES_H
#define LEXER_CPP_RULES_H

#include "Automaton.h"

class RULES : public Automaton
{
public:
    RULES() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == 'R') {
            index++;
            inputRead++;
            S1(input);
        }
        else {
            Serr();
        }
    }

    void S1(const std::string& input) {
        if (input[index] == 'u') {
            index++;
            inputRead++;
            S2(input);
        }
        else {
            Serr();
        }
    }

    void S2(const std::string& input) {
        if (input[index] == 'l') {
            index++;
            inputRead++;
            S3(input);
        }
        else {
            Serr();
        }
    }

    void S3(const std::string& input) {
        if (input[index] == 'e') {
            index++;
            inputRead++;
            S4(input);
        }
        else {
            Serr();
        }
    }

    void S4(const std::string& input) {
        if (input[index] == 's') {
            inputRead++;
        }
        else {
            Serr();
        }
    }
};



#endif //LEXER_CPP_RULES_H
