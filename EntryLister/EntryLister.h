#ifndef PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H
#define PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H

#include <memory>
#include <fstream>
#include "Entry.h"
#include <iostream>

using namespace std;

class EntryLister: public BaseClass {
    private:
        std::ifstream f;
        Entry read();

    //TODO: convert to smart pointers
    public:
        Entry First;
        Entry Second;
        //TODO: Check if file is open
        EntryLister(const char *);
        EntryLister(std::string);
        virtual ~EntryLister(){f.close();}

        virtual string toString() const{
            return First.toString() + " - " +Second.toString();
        }

        void next() {
            First = Second;
            Second = read();
        }
        bool end() const {return f.eof();};

};




#endif //PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H
