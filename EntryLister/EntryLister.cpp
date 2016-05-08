#include "EntryLister.h"

EntryLister::EntryLister(const char * fp):f(fp) {
    read(First);
    read(Second);
}

EntryLister::EntryLister(std::string fp):EntryLister::EntryLister(fp.c_str()){}

void EntryLister::read(shared_ptr<Entry> E) {
    string buffer;
    std::stringstream ss;
    getline(f, buffer, '\n');
//    std::cout << buffer << endl;

    ss << buffer;
    std::string s1, s2, s3, s4;
    ss >> s1;
    ss >> s2;
    ss >> s3;
    ss >> s4;
    E = make_shared<Entry>(Entry(s1, s2, s3, s4));
}





