
#include <iostream>
#include "Reception.h"


using namespace std;



int main(int argc, char* argv[]){

    string fp;
    if (argc > 1) {
       fp = argv[argc - 1];
    }
    while (fp == ""){
        cout << "No input file path is available. Pleas provide input file path!" << endl;
        cin >> fp;
    }
    auto f = ifstream(fp); // acquiring resource

    if (f.is_open()){
        Reception r(f); // initiating solution object
        cout << "Numper of people in the company: " << r.nr_people_in() << endl << endl; //writing out result two
        cout << "The people in the company (time of entry - name - id): \n" << r.wrong_entrys() << endl; // writing out result one
    }else{
        cout << "No valid file was found at the given path!" << endl;
    }

    f.close(); // releasing resource

    return 0;
}
