//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_SCHEMES_H
#define LEXER_CPP_SCHEMES_H

#include "Automaton.h"

class SCHEMES : public Automaton
{
public:
    SCHEMES() : Automaton(TokenType::SCHEMES) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == 'S') {
            index++;
            inputRead++;
            S1(input);
        }
        else {
            Serr();
        }
    }

    void S1(const std::string& input) {
        if (input[index] == 'c') {
            index++;
            inputRead++;
            S2(input);
        }
        else {
            Serr();
        }
    }

    void S2(const std::string& input) {
        if (input[index] == 'h') {
            index++;
            inputRead++;
            S3(input);
        }
        else {
            Serr();
        }
    }

    void S3(const std::string& input) {
        if (input[index] == 'e') {
            index++;
            inputRead++;
            S4(input);
        }
        else {
            Serr();
        }
    }

    void S4(const std::string& input) {
        if (input[index] == 'm') {
            index++;
            inputRead++;
            S5(input);
        }
        else {
            Serr();
        }
    }

    void S5(const std::string& input) {
        if (input[index] == 'e') {
            index++;
            inputRead++;
            S6(input);
        }
        else {
            Serr();
        }
    }

    void S6(const std::string& input) {
        if (input[index] == 's') {
            inputRead++;
        }
        else {
            Serr();
        }
    }

};



#endif //LEXER_CPP_SCHEMES_H
