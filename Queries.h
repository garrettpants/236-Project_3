//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_QUERIES_H
#define LEXER_CPP_QUERIES_H

#include "Automaton.h"

class QUERIES : public Automaton
{
public:
    QUERIES() : Automaton(TokenType::QUERIES) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == 'Q') {
            index++;
            inputRead++;
            S1(input);
        } else {
            Serr();
        }
    }

    void S1(const std::string& input) {
        if (input[index] == 'u') {
            index++;
            inputRead++;
            S2(input);
        } else {
            Serr();
        }
    }

    void S2(const std::string& input) {
        if (input[index] == 'e') {
            index++;
            inputRead++;
            S3(input);
        } else {
            Serr();
        }
    }

    void S3(const std::string& input) {
        if (input[index] == 'r') {
            index++;
            inputRead++;
            S4(input);
        } else {
            Serr();
        }
    }

    void S4(const std::string& input) {
        if (input[index] == 'i') {
            index++;
            inputRead++;
            S5(input);
        } else {
            Serr();
        }
    }

    void S5(const std::string& input) {
        if (input[index] == 'e') {
            index++;
            inputRead++;
            S6(input);
        } else {
            Serr();
        }
    }

    void S6(const std::string& input) {
        if (input[index] == 's') {
            index++;
            inputRead++;
        } else {
            Serr();
        }
    }
};



#endif //LEXER_CPP_QUERIES_H
