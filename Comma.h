//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_COMMA_H
#define LEXER_CPP_COMMA_H

#include "Automaton.h"


class COMMA : public Automaton
{
public:
    COMMA() : Automaton(TokenType::COMMA) {}

    void S0(const std::string& input) {
        if (input[index] == ',') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};

#endif //LEXER_CPP_COMMA_H