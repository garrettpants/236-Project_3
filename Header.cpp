//
// Created by garre on 11/7/2022.
//

#include "Header.h"


vector<string> Header::projectHeader(vector<int> val) {
    vector<string> s;
    for(int i : val){
        s.push_back(header[i]);
    }
    return s;
}