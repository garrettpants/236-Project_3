//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_ID_H
#define LEXER_CPP_ID_H

#include "Automaton.h"

class ID : public Automaton
{
public:
    ID() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (isalpha(input[index])) {
            inputRead++;
            index++;
            S1(input);
        } else if (input[index] == '\n' || input[index] == ' ' || !isalnum(input[index])) {
            index++;
        }
        else {
            Serr();
        }
    }

    void S1(const std::string& input) {
        if (isalnum(input[index])) {
            inputRead++;
            index++;
            S1(input);
        } else if (input[index] == '\n' || input[index] == ' ') {
            index++;
        } else if (!isalpha(input[index])) {
            index++;
        } else {
            Serr();
        }
    }
};

#endif //LEXER_CPP_ID_H