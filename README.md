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
Listázza ki a hibás sorait az állománynak (azokat a sorokat, ahol egy olyan
személy belépését regisztrálták, aki még nem távozott) és számolja meg azokat a
személyeket, akik jelenleg benn vannak a vállalatnál (beléptek, de még nem
távoztak)

Megjegyzés:
Hibás az a sor ahhol olyan ember távozását regisztrálják akinek nincs regisztrált belépése.


Probléma:
A főprogram fordítható mind windows mind linux alapú környzetben GCC fordítóval.
Azonban windows alapú környezetekben legalább GCC v5.1.0 szükséges.
(MinGW GCC v5.3.0:  http://nuwen.net/mingw.html)
