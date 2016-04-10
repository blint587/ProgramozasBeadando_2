/*
Feljegyeztük, hogy egymás követő hétvégeken hány Forintot nyertünk vagy veszítettünk a
lóversenyen. Volt-e olyan napunk, amikor úgy nyertünk, hogy a megelőző k hétvégén
mindig veszítettünk?
*/


#include <iostream>
#include <vector>
#include "HorseRaceBalance.h"
#include "read_in/ReadIn.h"
#include <fstream>

using namespace std;


int main(){

    unsigned  int n;

    cin >> n;

    fstream f ("/media/balint/Data1/egyetem/BSc_programtervezo_informatikus/programozas/ProgramozasBeadando_1/test.txt");
    if (f.is_open()) {
        auto v = read_in_vector(n, f, c, "", false);

        for (unsigned int i = 0; i < n; ++i) {
            cout << v[i] << endl;
        }

        f.close();
    }

    return 0;
}
