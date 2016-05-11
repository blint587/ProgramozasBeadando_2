
#ifndef PROGRAMOZAS_ELSO_BEADANDO_RECEPTION_H
#define PROGRAMOZAS_ELSO_BEADANDO_RECEPTION_H


#include <c++/sstream>
#include <Entry.h>
#include <fstream>
#include <iostream>
#include <SET.h>

class Reception {

private:
    std::stringstream results;
    SET<Entry> s = SET<Entry>();
    Entry read(std::istream &f);

public:
    Reception(std::istream & instr);
    int nr_people_in(){return s.size();}
    std::string wrong_entrys(){return s.toString();}

};


#endif //PROGRAMOZAS_ELSO_BEADANDO_RECEPTION_H
