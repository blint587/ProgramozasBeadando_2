#ifndef PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H
#define PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H

#include <memory>
#include <fstream>
#include "Entry.h"
#include <iostream>
#include <istream>
#include <string>

using namespace std;

class EntryLister: public BaseClass {
    private:
        istream *f ;
        Entry read();
        unique_ptr<Entry> First;
        unique_ptr<Entry> Second;
    public:

        int linecount = 0; // move to private and implement getter
        EntryLister(istream&);
        const unique_ptr<Entry> & getFirst() const {return First;}
        const unique_ptr<Entry> & getSecond() const {return Second;}

        bool isTheSame() const;


        virtual ~EntryLister(){};
        virtual string toString() const;

        void next();
        bool end() const {return f->eof();};

};




#endif //PROGRAMOZAS_ELSO_BEADANDO_ENTRYLISTER_H
