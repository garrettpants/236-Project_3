//
// Created by garre on 10/12/2022.
//

#ifndef INC_236_PROJECT_1_PARAMETER_H
#define INC_236_PROJECT_1_PARAMETER_H
#include <string>

using namespace std;

class Parameter {

public:
    string parameter;

    Parameter() = default;
    Parameter(string tempPar) {
        parameter = tempPar;
    }

    string parToString() {
        return parameter;
    }

    void stringParAdd(string addToPar) {
        parameter = addToPar;
    }

};
#endif //INC_236_PROJECT_1_PARAMETER_H
