//
// Created by garre on 11/7/2022.
//

#include "Tuple.h"

using namespace std;

vector<string> Tuple::projectTuple(vector<int> val) {
    vector<string> s;
    for(int i : val){
        s.push_back(values[i]);
    }
    return s;
}