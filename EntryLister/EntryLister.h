//
// Created by KlingonW on 2016-05-08.
//

#ifndef PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H
#define PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H

#include <memory>
#include <fstream>
#include "Entry.h"
#include <iostream>

using namespace std;

class EntryLister {
    private:
        std::ifstream f;
        void read(shared_ptr<Entry>);

    public:
        shared_ptr<Entry> First;
        shared_ptr<Entry> Second;

        EntryLister(const char *);
        EntryLister(std::string);
        virtual ~EntryLister(){
            f.close();
        }

        void next() {
            First = Second;
            read(Second);
        }
        bool end() const {return f.eof();};

};




#endif //PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H
