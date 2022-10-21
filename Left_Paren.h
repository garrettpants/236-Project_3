//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_LEFT_PAREN_H
#define LEXER_CPP_LEFT_PAREN_H

#include "Automaton.h"

class LEFT_PAREN : public Automaton
{
public:
    LEFT_PAREN() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '(') {
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};

#endif //LEXER_CPP_LEFT_PAREN_H
