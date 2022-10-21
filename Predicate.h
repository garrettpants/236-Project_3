//
// Created by garre on 10/12/2022.
//

#ifndef INC_236_PROJECT_1_PREDICATE_H
#define INC_236_PROJECT_1_PREDICATE_H
#include <string>
#include <sstream>
#include <ostream>
#include <vector>
#include "Parameter.h"

using namespace std;

class Predicate {
private:
    string ID;
public:
    vector<Parameter*> parameter;
    Predicate() = default;
    Predicate(string id, vector<Parameter*> paramVec) {
        ID = id;
        parameter = paramVec;
    }

    void stringPredAdd(Parameter* parameter1) {
        parameter.push_back(parameter1);
    }
    void addID(string id) {
        ID = id;
    }
    string predToString(){
        stringstream ss;

        ss << ID << "(";

        for (unsigned int i = 0; i < parameter.size(); i++) {
            ss << parameter.at(i)->parToString();
            if (i != parameter.size()-1) {
                ss << ",";
            }
        }
        ss << ")";
        return ss.str();
    }

    string toString() {
        return string();
    }
};

#endif //INC_236_PROJECT_1_PREDICATE_H
