//
// Created by garre on 10/21/2022.
//

#ifndef INC_236_PROJECT_3_RELATION_H
#define INC_236_PROJECT_3_RELATION_H
#include "Database.h"

class Relation {
private:
    string name;
    Header header;
    set<Tuples> tuples;
};

#endif //INC_236_PROJECT_3_RELATION_H
