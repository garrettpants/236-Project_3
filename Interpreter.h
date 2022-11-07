//
// Created by garre on 11/7/2022.
//

#ifndef INC_236_PROJECT_3_INTERPRETER_H
#define INC_236_PROJECT_3_INTERPRETER_H

#include "Datalog.h"
#include "Database.h"
#include "Relation.h"
#include <vector>

class Interpreter {

public:

    Interpreter(Datalog* datalog) {
        data = new Database();
        d = datalog;
    }
    Database* data;
    Datalog* d;

    void get();
    void setSchemes();
    void setFacts();
    void handleQuery();

   vector<string> getParams(Predicate *item);

    Relation *evaluatePredicate(const Predicate* p, std::vector<std::string> para);
};

#endif //INC_236_PROJECT_3_INTERPRETER_H
