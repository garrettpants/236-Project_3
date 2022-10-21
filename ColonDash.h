//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_COLONDASH_H
#define LEXER_CPP_COLONDASH_H

#include "Automaton.h"

class COLON_DASH : public Automaton
{
private:


public:
    COLON_DASH() : Automaton(TokenType::COLON_DASH) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == ':') {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    }

    void S1(const std::string& input) {
        if (input[index] == '-') {
            inputRead++;
            index++;
        }
        else {
            Serr();
        }
    }
};

#endif //LEXER_CPP_COLONDASH_H