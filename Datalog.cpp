//
// Created by garre on 10/19/2022.
//

#include "Datalog.h"
#include "Parameter.h"
#include "Predicate.h"
#include "P2Rules.h"

Datalog::~Datalog() {
    tokens.clear();
}

void Datalog::match(TokenType type) {
    if (type == tokens[index]->getType()) {
        index++;
    } else {
        throw tokens[index];
    }
};


void Datalog::parser(vector<Token*> input) {
    tokens = input;
    try {
        match(TokenType::SCHEMES);
        match(TokenType::COLON);
        scheme();
        schemeList();
        match(TokenType::FACTS);
        match(TokenType::COLON);
        factList();
        match(TokenType::RULES);
        match(TokenType::COLON);
        ruleList();
        match(TokenType::QUERIES);
        match(TokenType::COLON);
        query();
        queryList();
        match(TokenType::END_OF_FILE);
        cout << "Success!\n";
        print();
    }
    catch (Token *error) { //Looks like Failure is being called anyways
        cout << "Failure!\n";
        cout << tokens[index]->toString(); //TODO double check correct index
    }
}

void Datalog::print() {
    //schemes
    int countScheme = schemes.size();
    cout << "Schemes(" << countScheme << "):\n";
    for (Predicate* schemes1: schemes) {
        cout << "  " << schemes1->predToString() << '\n';
    }
    //facts
    int countFact = facts.size();
    cout << "Facts(" << countFact << "):\n";
    for (Predicate* facts1: facts) {
        cout << "  " << facts1->predToString() << '.'<< '\n';
    }
    //rules
    int countRule = rules.size();
    cout << "Rules(" << countRule << "):\n";
    for (P2Rules* rules1: rules) {
        cout << rules1->ruleToString() << '.' << '\n';
    }
    //queries
    int countQueries = queries.size();
    cout << "Queries(" << countQueries << "):\n";
    for (Predicate* queries1: queries) {
        cout << "  " << queries1->predToString() << "?" << '\n';
    }
    //domain
    int countDomain = domain.size();
    cout << "Domain(" << countDomain << "):\n";
    //Todo for each Predicate in the facts, Take all the parameters in the predicate and push them onto the set
    for (string domain1: domain) {
        cout << "  " << domain1 <<'\n';
    }
}

TokenType Datalog::peek() {
    tokens[index+1];
    return tokens[index]->getType();
}

void Datalog::scheme() {
    match(TokenType::ID);
    Predicate* newPred = new Predicate;
    newPred->addID(tokens[index-1]->getDescription());
    match(TokenType::LEFT_PAREN);

    if (peek()==TokenType::ID) {
        Parameter* parameter1 = new Parameter(tokens[index]->getDescription());
        newPred->stringPredAdd(parameter1);
    }
    match(TokenType::ID);
    idList(newPred);
    match(TokenType::RIGHT_PAREN);
    schemes.push_back(newPred);
}

void Datalog::schemeList() {
    if (peek() == TokenType::FACTS) {
        return;
    } else {
        scheme();
        schemeList();
    }
}

void Datalog::fact() {
    match(TokenType::ID);
    Predicate* newPred = new Predicate;
    newPred->addID(tokens[index-1]->getDescription()); //TODO check if you need to adjust tokens[x]
    match(TokenType::LEFT_PAREN);
    if (peek() == TokenType::STRING) {
        Parameter* parameter1 = new Parameter(tokens[index]->getDescription());
        domain.insert(parameter1->parToString());
        newPred->stringPredAdd(parameter1);
    }
    match(TokenType::STRING);

    stringList(newPred);
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);
    facts.push_back(newPred);
}

void Datalog::factList() {
    if (peek() == TokenType::RULES) { //the bane of my existence
        return;
    } else {
        fact();
        factList();
    }
}

void Datalog::rule() {
    P2Rules* rules1 = new P2Rules();
    Predicate* newHeadPred = new Predicate;
    headPredicate(newHeadPred);
    rules1->setHeadPredicate(newHeadPred);

    match(TokenType::COLON_DASH);
    Predicate* bodyPred = new Predicate;
    predicate(bodyPred);
    rules1->addBodyPredicate(bodyPred);

    predicateList(rules1);

    match(TokenType::PERIOD);
    rules.push_back(rules1);
}

void Datalog::ruleList() {
    if (peek() == TokenType::QUERIES) {
        return;
    } else {
        rule();
        ruleList();
    }
}

void Datalog::query() {
    Predicate* newPred = new Predicate;
    if (peek() == TokenType::ID) {
    }
    predicate(newPred);
    match(TokenType::Q_MARK);
    queries.push_back(newPred);
}

void Datalog::queryList() {
    if (peek() == TokenType::END_OF_FILE) {
        return;
    } else {
        query();
        queryList();
    }
}

void Datalog::stringList(Predicate* predPtr) {
    if (peek() == TokenType::RIGHT_PAREN) {
        return;
    } else {
        match(TokenType::COMMA);
        if(peek() == TokenType::STRING) {
            Parameter* p = new Parameter(tokens[index]->getDescription());
            domain.insert(p->parToString());
            predPtr->stringPredAdd(p);
        }
        match(TokenType::STRING);
        stringList(predPtr);
    }
}

void Datalog::idList(Predicate* predPtr) {
    if (peek() == TokenType::RIGHT_PAREN) {
        return;
    } else {
        match(TokenType::COMMA);
        if (peek() == TokenType::ID) {
            Parameter* p = new Parameter(tokens[index]->getDescription());
            predPtr->stringPredAdd(p);
        }
        match(TokenType::ID);
        idList(predPtr);
    }
}

void Datalog::headPredicate(Predicate *predPtr) {
    if (peek() == TokenType::ID) {
        predPtr->addID(tokens[index]->getDescription());
    }
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    if (peek() == TokenType::ID) {
        Parameter* p = new Parameter(tokens[index]->getDescription());
        predPtr->stringPredAdd(p);
    }
    match(TokenType::ID);
    idList(predPtr);
    match(TokenType::RIGHT_PAREN);
}

void Datalog::predicate(Predicate* predPtr) {
    if (peek() == TokenType::ID) {
        predPtr->addID(tokens[index]->getDescription());
    }
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    parameter(predPtr);
    parameterList(predPtr);
    match(TokenType::RIGHT_PAREN);
}

void Datalog::predicateList(P2Rules *rules1) {
    if (peek() == TokenType::PERIOD) {
        return;
    } else {
        match(TokenType::COMMA);
        Predicate* predAdd = new Predicate();
        predicate(predAdd);
        rules1->addBodyPredicate(predAdd);
        predicateList(rules1);
    }
}

void Datalog::parameter(Predicate* predPtr) {
    if (tokens[index]->getType() == TokenType::ID) {
        if (peek() == TokenType::ID) {
            Parameter* p = new Parameter(tokens[index]->getDescription());
            predPtr->stringPredAdd(p);
        }
        match(TokenType::ID);
    } else {
        if (peek() == TokenType::STRING) {
            Parameter* parameter1 = new Parameter(tokens[index]->getDescription());
            predPtr->stringPredAdd(parameter1);
        }
        match(TokenType::STRING);
    }
}

void Datalog::parameterList(Predicate *predPtr) {
    if (peek() == TokenType::RIGHT_PAREN) {
        return;
    } else {
        match(TokenType::COMMA);
        parameter(predPtr);
        parameterList(predPtr);
    }
}





/*
}

void match(TokenType T) { //build match function
    if (T == tokens[index1]->type) {
        if (T == TokenType::STRING && currentState == TokenType::Facts) {
            domainList.insert(tokens[index1]->description);
        }
        index1++;
    }
    else {
        throw (tokens[index1]);
    }
} */

/*
DatalogProgram* Parse() {
    try {
        DatalogProgram *program = new DatalogProgram;
        Scheme(tokens, program);
        Facts(tokens, program);
        Rules(tokens, program);
        Queries(tokens, program);
        return program;
    } catch (Token* error) {
           // TODO error->failure(error->toString(), error->getDescription(), error)]
           exit(0);
    }
}
 Datalog::Parser(vector<Token *> tokenVector) {
    this->tokens = tokenVector;
}
 */


