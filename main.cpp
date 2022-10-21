#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include "Lexer.h"
#include "Datalog.h"


using namespace std;

using std::cout; using std::cin;
using std::endl; using std::string;
//    char tmp[256];
//    getcwd(tmp, 256);
//    cout << "Current working directory: " << tmp << endl;


int main(int argc, char** argv) {

    //char tmp[256];
    //getcwd(tmp, 256);
    //cout << "Current working directory: " << tmp << endl;

    ifstream input(argv[1]);
    if (!input.is_open()) {
        cout << "File" << argv[1] << " could not be opened." << endl;
        return 1;
    }

    string output, line;
    stringstream ss;
    ss << input.rdbuf();
    string str = ss.str();
   /* while (getline(input, line)) {
        output += line + '\n';
    }*/

    Lexer* lexer = new Lexer(str);
    auto* datalog = new Datalog();
    datalog->parser(lexer->getLexer());
    delete lexer;

    return 0;
}