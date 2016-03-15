# Programozas első beadandó

## Feladat:
Feljegyeztük, hogy egymás követő hétvégeken hány Forintot nyertünk vagy veszítettünk a
lóversenyen. Volt-e olyan napunk, amikor úgy nyertünk, hogy a megelőző **k** hétvégén
mindig veszítettünk?

Probléma:
A főprogram fordítható mind windows mind linux alapú környzetben gcc fordítóval.
Azonban gtest nem fordítható windows alapú környezetben (MinGW 3.20): https://github.com/google/googletest/issues/708.
Így az 'egyég testek' csak Linux alapú környezetben futtathtók.
