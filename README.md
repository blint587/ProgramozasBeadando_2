# Programozas második beadandó

## Feladat:
Egy vállalat portaszolgálatán feljegyzik a belépő és kilépő személyek adatait.
Belépéskor rögzítik az aktuális időpontot, a belépő nevét és azonosítására szolgáló
igazolványszámot, távozáskor pedig a fenti három adat mellé kerül a kilépés
időpontja. A napi adatokat azonosító szerint, azon belül belépési idő szerint
növekvően rendezve egy szöveges állományban tárolják. Feltehetjük, hogy az
állomány helyesen van kitöltve, annak egy sorában három vagy négy olyan sztringet
találunk, amelyeknek belsejében nincs elválasztó jel, ugyanakkor tetszőleges számú
elválasztó jel határolja azokat.

Példa bemente:
10:30 Gipsz_Jakab 1234567A 10:45
08:35 Gyanus_Moric 1x1x1x1x1x
08:35 Gyanus_Moric 1x1x1x1x1x 08:45
08:55 Gyanus_Moric 1x1x1x1x1x
08:45 Szer_Elek 33332222
08:45 Szer_Elek 33332222 09:15

Listázza ki a hibás sorait az állománynak (azokat a sorokat, ahol egy olyan
személy belépését regisztrálták, aki még nem távozott) és számolja meg azokat a
személyeket, akik jelenleg benn vannak a vállalatnál (beléptek, de még nem
távoztak)

Entry:
    DateTime enter
    string name
    string id
    DateTime leave


A = (x: Entry*, n:N, y: Entry*, be:{}, ki:{})

Ef = (x = x', x: ↑)

Uf =( be = ⊕ <e> & ki = ⊕ <e> → y = be \ ki → n = |y|
          e∊x'         e∊x'
        belepes(e)  kilepes(e))

belepes(e):=
 ___________________________________________________
|                                                   |
|                   x.First()                       |
|___________________________________________________|
|                                                   |
|                                                   |
|    _______________________________________________|
|   |                                               |
|   |                                               |
|   |                                               |
|   |                                               |
|   |                                               |
|   |                                               |
|   |                                               |
|   |                                               |
|   |                                               |
|   |                                               |
|___|_______________________________________________|




Fordítás:
A főprogram fordítható mind windows mind linux alapú környzetben GCC fordítóval.
Azonban windows alapú környezetekben legalább GCC v5.1.0 szükséges.
(MinGW GCC v5.3.0:  http://nuwen.net/mingw.html)
