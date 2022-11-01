//
// Created by garre on 10/21/2022.
//

#ifndef INC_236_PROJECT_3_RELATION_H
#define INC_236_PROJECT_3_RELATION_H
#include "Header.h"
#include "Tuple.h"
#include "Database.h"
#include <set>
#include <string>


class Relation {
private:
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

Relation *Relation::selectIndex(int p, string v) {
    set<Tuple> tup;
    for (Tuple t : relation) {
        if (t.values[p] == v) {
            tup.insert(t);
        }
    }

    Relation* rel = new Relation(this->name, this->header);
    rel->relation = tup;
    return rel;
}

Relation *Relation::selectMatch(int p1, int p2) {
    set<Tuple> tup;
    for (Tuple t : relation) {
        if (t.values[p1] == t.values[p2]) {
            tup.insert(t);
        }
    }

    Relation* rel = new Relation(this->name, this->header);
    rel->relation = tup;
    return rel;
}

Relation *Relation::project(vector<int> columns) {
    vector<string> h = header->projectHeader(columns);
    Header* head = new Header(h);
    Relation* rel = new Relation(this->name, head);
    set<Tuple> tups;
    for (Tuple t : relation) {
        vector<string> s = t.projectTuple(columns);
        Tuple tup(s);
        tups.insert(tup);
    }

    rel->relation = tups;
    return rel;
}

Relation *Relation::rename(vector<string> attributes) {
    Header* h = new Header(attributes);
    Relation* rel = new Relation(this->name, h);
    rel->relation = this->relation;
    return rel;
}

#endif //INC_236_PROJECT_3_RELATION_H
