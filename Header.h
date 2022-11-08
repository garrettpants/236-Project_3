//
// Created by garre on 10/21/2022.
//

#ifndef INC_236_PROJECT_3_HEADER_H
#define INC_236_PROJECT_3_HEADER_H
#include <string>
#include <vector>

using namespace std;

class Header {
public:
    vector<string> header;
    Header(vector<string> s) {
        header = s;
    }

    vector<string> projectHeader(vector<int> val);
};

#endif //INC_236_PROJECT_3_HEADER_H
