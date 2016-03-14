#include <iostream>
#include <vector>
#include "HorseRaceBalance.h"

using namespace std;


int main(){

    vector<double> s = {0.,0.,0.,1.,2.,3.,4.};

    HorseRaceBalance hr = HorseRaceBalance(s, true);

    cout << hr.won_affter_loisng_(2) << endl;
    return 0;
}
