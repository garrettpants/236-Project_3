#include "Colon.h"
#include "ColonDash.h"
#include "Comma.h"
#include "Period.h"
#include "Q_Mark.h"
#include "Left_Paren.h"
#include "Right_Paren.h"
#include "Multiply.h"
#include "Add.h"
#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"
#include "Queries.h"
#include "ID.h"
#include "String.h"
#include "Comment.h"
#include "Automaton.h"
#include "Token.h"
#include "Lexer.h"
#include <vector>

using namespace std;

Lexer::~Lexer() {
    automata.clear();
    tokens.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new COLON);
    automata.push_back(new COLON_DASH);
    automata.push_back(new COMMA);
    automata.push_back(new PERIOD);
    automata.push_back(new Q_MARK);
    automata.push_back(new LEFT_PAREN);
    automata.push_back(new RIGHT_PAREN);
    automata.push_back(new MULTIPLY);
    automata.push_back(new ADD);
    automata.push_back(new SCHEMES);
    automata.push_back(new FACTS);
    automata.push_back(new RULES);
    automata.push_back(new QUERIES);
    automata.push_back(new ID);
    automata.push_back(new STRING);
    automata.push_back(new COMMENT);
    //automata.push_back(new UNDEFINED());
}

vector<Token*> Lexer::Run() {
    unsigned int lineNum = 1;
    while (!input.empty()) {
        unsigned int maxRead = 0;
        Automaton *maxAutomaton = automata.at(0);

        while (isspace(input[0])) {
            if (input[0] == '\n') {
                lineNum++;
            }
            else if (isspace(input.size() == 0)) {
                break;
            }
            input.erase(0,1);
        }

        //Whitespace
        for (Automaton* currAutomaton : automata) {
            unsigned int startRead = currAutomaton->Start(input);
            if (startRead > maxRead) {
                maxRead = startRead;
                maxAutomaton = currAutomaton;
            }
        }
        if (maxRead == 0 && !input.empty()) {
            maxRead = 1;
            tokens.push_back(new Token(TokenType::UNDEFINED, input.substr(0,1), lineNum));
        }
        else if (maxRead > 0) {
            Token* AB = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNum);
            if (AB->getType() != TokenType::COMMENT) {
                tokens.push_back(AB);
            }
            lineNum += maxAutomaton->NewLinesRead();
        }
        input.erase(0, maxRead);
    }
    tokens.push_back(new Token(TokenType::END_OF_FILE, "", lineNum));
    //print(tokens);
    return tokens;
}

void Lexer::print(const vector <Token*> &tokens) {
    for (Token* token: tokens) {
        cout << token->toString() << '\n';
    }
    unsigned int count = tokens.size();
    cout << "Total Tokens = " << count;
}

const vector <Token*> &Lexer::getLexer() const {
    return tokens;
}