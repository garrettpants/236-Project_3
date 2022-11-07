//
// Created by garre on 11/7/2022.
//

#include "Header.h"
std::vector<std::string> Header::projectHeader(std::vector<int> val) {
    std::vector<std::string> s;
    for(int i : val){
        s.push_back(header[i]);
    }
    return s;
}