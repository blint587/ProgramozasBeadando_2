
#include <iostream>
#include "Reception.h"


using namespace std;



int main(int argc, char* argv[]){

    string fp = argv[argc-1];
    auto f = ifstream(fp); // acquiring resource

    if (f.is_open()){
        Reception r(f); // initiating solution object
        cout << r.wrong_entrys() << endl; // writing out result one
        cout << r.nr_people_in() << endl; //writing out result two
    }

    f.close(); // releasing resource

    return 0;
}
