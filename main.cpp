/*
Egy vállalat portaszolgálatán feljegyzik a belépő és kilépő személyek adatait.
Belépéskor rögzítik az aktuális időpontot, a belépő nevét és azonosítására szolgáló
igazolványszámot, távozáskor pedig a fenti három adat mellé kerül a kilépés
időpontja. A napi adatokat azonosító szerint, azon belül belépési idő szerint
növekvően rendezve egy szöveges állományban tárolják. Feltehetjük, hogy az
állomány helyesen van kitöltve, annak egy sorában három vagy négy olyan sztringet
találunk, amelyeknek belsejében nincs elválasztó jel, ugyanakkor tetszőleges számú
elválasztó jel határolja azokat.

Listázza ki a hibás sorait az állománynak (azokat a sorokat, ahol egy olyan
személy belépését regisztrálták, aki még nem távozott) és számolja meg azokat a
személyeket, akik jelenleg benn vannak a vállalatnál (beléptek, de még nem
távoztak)!

 */

#include <iostream>
#ifdef WIN32
    #include <conio.h>
#endif
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Entry.h"

using namespace std;

Entry read(const char * fp);

int main(){
    auto e = read("F:\\egyetem\\BSc_programtervezo_informatikus\\programozas\\ProgramozasBeadando_2\\ProgramozasBeadando_2\\test.txt");
    cout << e << endl;

    return 0;
}

Entry read(const char * fp){

    string buffer;
    fstream f(fp);
    stringstream ss;
    getline(f, buffer, '\n');
    ss << buffer;
    string s1,s2,s3,s4;
     ss >> s1;
    ss >> s2;
    ss >> s3;
    ss >> s4;

    Entry e = Entry(s1, s2, s3, s4);

    f.close();
    return e;
}