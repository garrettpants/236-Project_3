//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_COLON_H
#define LEXER_CPP_COLON_H

#include "Automaton.h"


class COLON : public Automaton
{
public:
    COLON() : Automaton(TokenType::COLON) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == ':') {
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};


#endif //LEXER_CPP_COLON_H