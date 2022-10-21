//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_RIGHT_PAREN_H
#define LEXER_CPP_RIGHT_PAREN_H

#include "Automaton.h"

class RIGHT_PAREN : public Automaton
{
public:
    RIGHT_PAREN() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == ')') {
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};



#endif //LEXER_CPP_RIGHT_PAREN_H