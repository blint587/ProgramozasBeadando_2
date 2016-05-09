
#include <iostream>
#include "Entry.h"
#include "EntryLister.h"

using namespace std;



int main(){

    auto f = ifstream("F:\\egyetem\\BSc_programtervezo_informatikus\\programozas\\ProgramozasBeadando_2\\ProgramozasBeadando_2\\test.txt");


    int count = 0;
    EntryLister el(f);

    if(el.isTheSame()){
        if(el.getFirst().get()->getLeave().isvalid() && el.getSecond().get()->getLeave().isvalid()) {
            cout << el.linecount - 1 << " " << el.getFirst().get()->toString() << endl;
            cout << el.linecount << " " << el.getSecond().get()->toString() << endl;
        }
    }

    el.next();
    for(;!el.end(); el.next()){
        if(el.isTheSame()){
            if(el.getFirst().get()->getLeave().isvalid() && el.getSecond().get()->getLeave().isvalid()){
                cout << el.linecount << " " << el.getSecond().get()->toString() << endl;
            }
        }
        else if((!el.isTheSame() && el.getSecond().get()->getLeave().isvalid())){
            cout << el.linecount << " " << el.getSecond().get()->toString() << endl;
        }
    }
    cout << count << endl;

    f.close();


    return 0;
}
