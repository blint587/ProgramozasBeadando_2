/*
Feljegyeztük, hogy egymás követő hétvégeken hány Forintot nyertünk vagy veszítettünk a
lóversenyen. Volt-e olyan napunk, amikor úgy nyertünk, hogy a megelőző k hétvégén
mindig veszítettünk?
*/


#include <iostream>
#include <vector>
#include <conio.h>
#include "HorseRaceBalance.h"
#include "read_in/ReadIn.h"

#include <sstream>

using namespace std;

vector<double> read_from_file(std::string);
bool correct_bool(bool);
bool correct_int(int);
bool correct_filepath(std::string);
bool correct_balance(double);

int main(){

    int input_type;
    bool is_zero_a_loss;
    vector<double> balance;
    int k;



    cout << "Please provide what type of input ypu would like to use!\n1. File input.\n2. Console input."
                    "\nAnything will close the program!" << endl;
    cin >> input_type;
    if (1 == input_type){
        string file_path;
        file_path = read_in<std::string>(cin, correct_filepath, "Please provide the file path!\n");
        balance = read_from_file(file_path);

    }else if(2 == input_type){
        cout << "You can start typing the input data!\n"
                        "If you are finished entering the data press "
#ifdef WIN32
        "Ctrl + Z."
#else
        "Ctrl + D."
#endif
        << endl;

        balance = read_in_vector(cin, correct_balance, "Pleas enter a weekly balance!\n");
    }
    else{
        exit(2);
    }

    is_zero_a_loss = read_in<bool>(cin, correct_bool, "Is a zero weekly balance a win ore a loss? (0: it is a win, 1: it is a loss)\n");

    k = read_in<int>(cin, correct_int, "Please provide the number of weekends (k) whereas losing 'k' times you won after."
            "\n(Is there such a series?)\n" );

    HorseRaceBalance hbalance = HorseRaceBalance(balance, is_zero_a_loss);
    string aw = (hbalance.won_affter_loisng_(k) == 1) ? "yes" : "no";
    cout << aw << endl;

    cerr << "\nPleas press a key to exit..." << endl;
    getch();
    return 0;
}

vector<double> read_from_file(string file_path) {
    fstream f (file_path.c_str());
    vector<double> v;
    if (f.is_open()) {
        v = read_in_vector(f, correct_balance, "");
        f.close();
    }
    return v;
}

bool correct_bool(bool){
    return true;
}

bool correct_int(int i){
    return (i > 0);
}

bool correct_filepath(string fp){
    ifstream f(fp.c_str());
    {
        f.close();
        return f.good();
    }
}

bool correct_balance(double d){
    return true;
}