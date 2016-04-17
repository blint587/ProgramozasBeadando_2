/*
Feljegyeztük, hogy egymás követő hétvégeken hány Forintot nyertünk vagy veszítettünk a
lóversenyen. Volt-e olyan napunk, amikor úgy nyertünk, hogy a megelőző k hétvégén
mindig veszítettünk?
*/


#include <iostream>
#include <vector>
#include "HorseRaceBalance.h"
#include "read_in/ReadIn.h"

using namespace std;

vector<double> read_from_file(std::string);


int main(){

    int input_type;
    cout << "Please provide what type of input ypu would like to use!\n1. File input.\n2. Console input."
                    "\nAnything will close the program!" << endl;
    cin >> input_type;
    if (1 == input_type){
        cout << "Please provide the file path!" << endl;
        string filepath;
        cin >> filepath;
        read_from_file(filepath);

    }else if(2 == input_type){
        cout << "You can start typing the input data!\n"
                        "If you are finished entering the data press "
#ifdef WIN32
        "Ctrl + Z."
#else
        "Ctrl + D."
#endif
        << endl;

        read_in_vector(cin, c, "Pleas provide a valid double!\n");
    }


    char z;
    cin >> z;
    return 0;
}

vector<double> read_from_file(string file_path) {
    fstream f (file_path.c_str());
    vector<double> v;
    if (f.is_open()) {
        v = read_in_vector(f, c, "");
        f.close();
    }
    return v;
}

