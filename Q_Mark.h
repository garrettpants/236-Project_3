//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_Q_MARK_H
#define LEXER_CPP_Q_MARK_H

#include "Automaton.h"

class Q_MARK : public Automaton
{
public:
    Q_MARK() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '?') {
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};



#endif //LEXER_CPP_Q_MARK_H