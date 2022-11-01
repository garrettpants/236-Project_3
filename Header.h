//
// Created by garre on 10/21/2022.
//

#ifndef INC_236_PROJECT_3_HEADER_H
#define INC_236_PROJECT_3_HEADER_H
#include "Database.h"

class Header {
private:
    vector<string> attributes;
public: //TODO find void types
    void getAllAttribute();
    void getSingleAttribute();
    void setAllAttributes();
    void setSingleAttribute();
};

#endif //INC_236_PROJECT_3_HEADER_H
