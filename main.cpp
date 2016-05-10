
#include <iostream>
#include "Reception.h"


using namespace std;


//TODO: csak_belepot megszamolni
int main(int argc, char* argv[]){

    string fp = argv[argc-1];
    auto f = ifstream(fp); // acquiring resource

    Reception r(f);

    cout << r.wrong_entrys() << endl;

    cout << r.nr_people_in() << endl;


    f.close(); // releasing resource






    return 0;
}
