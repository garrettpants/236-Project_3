//
// Created by garre on 10/21/2022.
//

#ifndef INC_236_PROJECT_3_RELATION_H
#define INC_236_PROJECT_3_RELATION_H
#include "Header.h"
#include "Tuple.h"
#include <set>
#include <string>


class Relation {
public:
    Relation(string v, Header* h) {
        name = v;
        header = h;
    }

    string name;
    Header* header;
    set<Tuple> relation;
    Relation* selectIndex (int p, string v);
    Relation* selectMatch (int p1, int p2);
    Relation* project (vector<int> columns);
    Relation* rename (vector<string> attributes);
};

#endif //INC_236_PROJECT_3_RELATION_H
