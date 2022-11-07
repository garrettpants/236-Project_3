//
// Created by garre on 11/7/2022.
//
#include <algorithm>
#include <iostream>
#include "Relation.h"

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
