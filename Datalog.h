//
// Created by garre on 10/19/2022.
//

#ifndef INC_236_PROJECT_1_DATALOG_H
#define INC_236_PROJECT_1_DATALOG_H

#include <vector>
#include "Token.h"
#include "Parameter.h"
#include "Predicate.h"
#include "P2Rules.h"
#include <set>

class Datalog {
protected:
    unsigned int index = 0;
public:
    Datalog(){};
    vector<Predicate*> facts;
    vector<P2Rules*> rules;
    vector<Predicate*> queries;
    vector<Predicate*> schemes;
    set<string> domain;
    void parser(vector<Token*>);
    ~Datalog();
    //DatalogProgram* datalogProgram();

private:
    //DatalogProgram program;
    vector<Token*> tokens;

    void match(TokenType);
    void print();
    void scheme();
    void schemeList();
    void fact();
    void factList();
    void rule();
    void ruleList();
    void query();
    void queryList();
    void parameter(Predicate* predPtr);
    void predicate(Predicate* predPtr);
    void stringList(Predicate* predPtr);
    void idList(Predicate* predPtr);
    void headPredicate(Predicate* predPtr);
    void predicateList(P2Rules* rules1);
    void parameterList(Predicate* predPtr);
    TokenType peek();


};
#endif //INC_236_PROJECT_1_DATALOG_H
