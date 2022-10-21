//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_LEXER_H
#define LEXER_CPP_LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"


class Lexer
{
private:
    vector<Automaton*> automata;
    vector<Token*> tokens;
    string input;
    void CreateAutomata();

public:
    Lexer(const string& input) {
        this->input = input;
        CreateAutomata();
        Run();
    }
    ~Lexer();

    const vector<Token*> &getLexer() const;

    vector<struct Token *> Run();

    static void print(vector <Token*> const &input);
};

#endif //LEXER_CPP_LEXER_H
