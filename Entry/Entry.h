//
// Created by KlingonW on 2016-05-08.
//

#ifndef PROGRAMOZAS_MASODIK_BEADANDO_ENTRY_H
#define PROGRAMOZAS_MASODIK_BEADANDO_ENTRY_H

#include "DateTime.h"
#include "../BaseClass/BaseClass.h"
#include <string>

class Entry: public BaseClass{

    private:

        private:
        DateTime enter;
        std::string name;
        std::string id;
        DateTime leave;


    public:
        virtual ~Entry(){
//            std::cout << "Destructing: " << toString() << std::endl;
        };
        Entry(std::string ent, std::string name, std::string id, std::string leave=""):enter(ent.c_str()), name(name),
                                                                                    id(id), leave(leave.c_str()){
//        std::cout << "Constructing: " << toString() << std::endl;
        };
        virtual std::string toString() const;

        const DateTime &getEnter() const {return enter;}
        const std::string &getName() const {return name;}
        const std::string &getId() const {return id;}
        const DateTime &getLeave() const {return leave;}

};
inline bool operator== (Entry & e1, Entry & e2){ return e1.getId() == e2.getId();}

#endif
