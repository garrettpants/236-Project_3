//
// Created by garre on 9/29/2022.
//

#ifndef LEXER_CPP_TOKEN_H
#define LEXER_CPP_TOKEN_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    END_OF_FILE
};

class Token {
private:


    string tokenToString(TokenType T) {
        switch (T) {
            case TokenType::COMMA:
                return "COMMA";
            case TokenType::PERIOD:
                return "PERIOD";
            case TokenType::Q_MARK:
                return "Q_MARK";
            case TokenType::LEFT_PAREN:
                return "LEFT_PAREN";
            case TokenType::RIGHT_PAREN:
                return "RIGHT_PAREN";
            case TokenType::COLON:
                return "COLON";
            case TokenType::COLON_DASH:
                return "COLON_DASH";
            case TokenType::MULTIPLY:
                return "MULTIPLY";
            case TokenType::ADD:
                return "ADD";
            case TokenType::SCHEMES:
                return "SCHEMES";
            case TokenType::FACTS:
                return "FACTS";
            case TokenType::RULES:
                return "RULES";
            case TokenType::QUERIES:
                return "QUERIES";
            case TokenType::ID:
                return "ID";
            case TokenType::STRING:
                return "STRING";
            case TokenType::COMMENT:
                return "COMMENT";
            case TokenType::UNDEFINED:
                return "UNDEFINED";
            case TokenType::END_OF_FILE:
                return "EOF";
            default:
                return "ERROR";
        }
    }

public:

    TokenType type;
    string description;
    unsigned int lineNum;

    Token(TokenType type, string description, unsigned int lineNum) {
        this->type = type;
        this->description = description;
        this->lineNum = lineNum;
    }
    string toString() {
        stringstream ss;
        ss << "(" << tokenToString(type) << ",\"" << description << "\"," << lineNum << ")";
        return ss.str();
    }

    TokenType getType() {
        return type;
    }

    const string &getDescription() const {
        return description;
    }

};



/*
Token::Token() {
    this->return TokenType::UNDEFINED;
    this->description = "Value";
    this->lineNum = 1;
}

Token::Token(TokenType type, string description, int line) {
    this->return type;
    this->description = description;
    this->lineNum = lineNum;
}
*/


#endif //LEXER_CPP_TOKEN_H
