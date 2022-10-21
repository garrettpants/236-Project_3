//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_PERIOD_H
#define LEXER_CPP_PERIOD_H

#include "Automaton.h"


class PERIOD : public Automaton {
public:
    PERIOD() : Automaton(TokenType::PERIOD) {}

    void S0(const std::string &input) {
        if (input[index] == '.') {
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};




#endif //LEXER_CPP_PERIOD_H