
#include <iostream>
#include "Entry.h"
#include "EntryLister.h"
#include "SET.h"

using namespace std;

Entry read(ifstream & f) {
    string buffer;
    std::stringstream ss;
    getline(f, buffer, '\n');

    ss << buffer;
    const int n = 4;
    std::string s [n];
    for(int i = 0; i < n; ++i ){
        ss >> s[i];
        if(ss.fail()){
            // throw exception
        }
    }
    return Entry(s[0], s[1], s[2], s[3]);
};


//TODO: csak_belepot megszamolni
int main(int argc, char* argv[]){

    string fp = argv[argc-1];

    auto s = SET<Entry>();

    auto f = ifstream(fp);

    while(!f.eof()){
        auto e = read(f);
        if (e.getLeave().isvalid()){
            if (!s.pop(e)) {
                cerr << e << endl;
            }
        }else{
            if (s.push(e)){
                cerr << e << endl;
            };
        }
    }
    cout << s.toString() << endl;



//    int count = 0;
//    EntryLister el(f);
//
//    if(el.getFirst().get()->getLeave().isvalid()){
//        cout << el.linecount-1  << " " << el.getFirst().get()->toString() << endl;
//    }
//
//    for(;!el.end();el.next()){
//        if(!el.getSecond().get()->getLeave().isvalid()){
//            ++count;
//        }
//        if(el.isTheSame()){
//            if(el.getFirst().get()->getLeave().isvalid() && el.getSecond().get()->getLeave().isvalid()){
//                cout << el.linecount << " " << el.getSecond().get()->toString() << endl;
//            }
//            else if (el.getSecond().get()->getLeave().isvalid()){
//                --count;
//            }
//        }
//        else if((!el.isTheSame())){
//            if (el.getSecond().get()->getLeave().isvalid()) {
//                cout << el.linecount << " " << el.getSecond().get()->toString() << endl;
//            }
//        }
//    }
//    cout << count << endl;
//
//    f.close();


    return 0;
}
