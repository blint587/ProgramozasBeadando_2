#include "EntryLister.h"

EntryLister::EntryLister( istream & is) {

    f = &is;

    First = make_unique<Entry>(read());
    Second = make_unique<Entry>(read());
}


Entry EntryLister::read() {
    string buffer;
    std::stringstream ss;
    getline(*f, buffer, '\n');

    ss << buffer;
    const int n = 4;
    std::string s [n];
    for(int i = 0; i < n; ++i ){
        ss >> s[i];
        if(ss.fail()){
            // throw exception
        }
    }
    ++linecount;
    return Entry(s[0], s[1], s[2], s[3]);
}

string EntryLister::toString() const{
    return to_string(linecount) + this->First.get()->toString() + " - " + this->Second.get()->toString();
}

void EntryLister::next(){
    First = move(Second);
    Second = make_unique<Entry>(read());
}

bool EntryLister::isTheSame() const {
    return First.get()->getId() == Second.get()->getId();
}





