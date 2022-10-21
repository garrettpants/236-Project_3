//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_ADD_H
#define LEXER_CPP_ADD_H

#include "Automaton.h"


class ADD : public Automaton
{
public:
    ADD() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '+') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};


#endif //LEXER_CPP_ADD_H