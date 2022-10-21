//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_MULTIPLY_H
#define LEXER_CPP_MULTIPLY_H

#include "Automaton.h"

class MULTIPLY : public Automaton
{
public:
    MULTIPLY() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '*') {
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};




#endif //LEXER_CPP_MULTIPLY_H
