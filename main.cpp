
#include <iostream>
#include "Entry.h"
#include "EntryLister.h"

using namespace std;



int main(){
    EntryLister el("F:\\egyetem\\BSc_programtervezo_informatikus\\programozas\\ProgramozasBeadando_2\\ProgramozasBeadando_2\\test.txt");

    for(; !el.end(); el.next()){
        cerr << el << endl;
    }



    return 0;
}
