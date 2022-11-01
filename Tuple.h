//
// Created by garre on 10/21/2022.
//

#ifndef INC_236_PROJECT_3_TUPLE_H
#define INC_236_PROJECT_3_TUPLE_H
#include "Database.h"
#include <string>
#include <vector>

class Tuple {
public:
    vector<string> values;

    Tuple(vector<string> s) {
        values = s;
    }

    vector <string> projectTuple(vector<int> val);

    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }
};

#endif //INC_236_PROJECT_3_TUPLE_H
