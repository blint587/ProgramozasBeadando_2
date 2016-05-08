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
távoztak)
 */

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
