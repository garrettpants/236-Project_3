//
// Created by garre on 10/18/2022.
//

#ifndef INC_236_PROJECT_1_P2RULES_H
#define INC_236_PROJECT_1_P2RULES_H
#include <string>
#include <sstream>
#include <iostream>
#include <ostream>
#include <vector>
#include "Parameter.h"
#include "Predicate.h"

using namespace std;

class P2Rules {
private:
    Predicate* headPredicate;
    vector<Predicate*> rulesBody;
public:
    P2Rules() = default;
    void setHeadPredicate(Predicate* headPred) {
        this->headPredicate = headPred;
    }
    void addBodyPredicate(Predicate* bodyPredicate) {
        this->rulesBody.push_back(bodyPredicate);
    }
    string ruleToString(){
        stringstream ss;

        ss << "  " << headPredicate->predToString() << " :- ";
        for(unsigned int i = 0; i < rulesBody.size(); i++){
            ss << rulesBody.at(i)->predToString();
            if(i != rulesBody.size()-1){
                ss << ",";
            }
        }
        return ss.str();
    }

    string toString() {
        return string();
    }
};

#endif //INC_236_PROJECT_1_P2RULES_H
