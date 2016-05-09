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




    private:
        unique_ptr<Entry> First;
        unique_ptr<Entry> Second;

    public:
        EntryLister(const char *);
        EntryLister(std::string);

        const unique_ptr<Entry> &getFirst() const {return First;}
        const unique_ptr<Entry> &getSecond() const {return Second;}


    virtual ~EntryLister(){f.close();}
        virtual string toString() const;

        void next();
        bool end() const {return f.eof();};

};




#endif //PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H
