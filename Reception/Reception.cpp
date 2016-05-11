#include "Reception.h"

void Reception::read(std::istream &f) {
    std::string buffer;
    std::stringstream ss;
    getline(f, buffer, '\n');

    ss << buffer;
    const int n = 4;
    std::string s[n];
    for (int i = 0; i < n; ++i) {
        ss >> s[i];
        if (ss.fail()) {
            // throw exception
        }
    }
    current = std::make_unique<Entry>(s[0], s[1], s[2], s[3]);
}

Reception::Reception(std::istream &instr) { // abstraction of First
    read(instr); // abstraction of First
    while (!instr.eof()) { // abstraction of End

        if (this->current.get()->getLeave().isvalid()) {
            s.pop(*this->current.get());
        }
        else {
            s.push(*this->current.get());
        }
        read(instr); // abstraction of Next
    }
}
