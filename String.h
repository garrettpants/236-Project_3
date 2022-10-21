//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_STRING_H
#define LEXER_CPP_STRING_H

#include "Automaton.h"

class STRING : public Automaton
{
private:
    void S1(const std::string& input) {
        if (index >= input.size()) {
            type = TokenType::UNDEFINED;
            return;
        } else if (input[index] != '\'') {
            if (input[index] == '\n') {
                newLines++;
            }
            index++;
            inputRead++;
            S1(input);
        } else if (input[index] == '\'') {
            index++;
            inputRead++;
            if (input[index] == '\'') {
                index++;
                inputRead++;
                S1(input);
            }
        }
        else {
            Serr();
        }
    }

public:
    STRING() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '\'') {
            index++;
            inputRead++;
            S1(input);
        }
        else {
            Serr();
        }
    }
};



#endif //LEXER_CPP_STRING_H
