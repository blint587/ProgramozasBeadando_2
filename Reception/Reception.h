
#ifndef PROGRAMOZAS_ELSO_BEADANDO_RECEPTION_H
#define PROGRAMOZAS_ELSO_BEADANDO_RECEPTION_H


#include <sstream>
#include <Entry.h>
#include <fstream>
#include <iostream>
#include <memory>
#include <SET.h>

class Reception {

private:
    std::unique_ptr<Entry> current;
    std::stringstream results;
    SET<Entry> s = SET<Entry>();
    void read(std::istream &f);

public:
    Reception(std::istream & instr);
    int nr_people_in(){return s.size();}
    std::string wrong_entrys(){return s.toString();}

};


#endif //PROGRAMOZAS_ELSO_BEADANDO_RECEPTION_H
