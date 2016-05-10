#include "Reception.h"

Entry Reception::read(std::istream &f) {
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
    ++linecount;
    return Entry(s[0], s[1], s[2], s[3]);
}

Reception::Reception(std::istream &instr){
    while(!instr.eof()){
        auto e = read(instr);
        if (e.getLeave().isvalid()) {
            if (!s.pop(e)) {
                results << linecount << " " <<  e << std::endl;
            }
        } else {
            if (s.push(e)) {
                results << linecount << " " << e << std::endl;
            };
        }
    }
}