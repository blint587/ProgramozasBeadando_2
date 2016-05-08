//
// Created by KlingonW on 2016-05-08.
//

#ifndef PROGRAMOZAS_MASODIK_BEADANDO_ENTRY_H
#define PROGRAMOZAS_MASODIK_BEADANDO_ENTRY_H

#include "DateTime.h"
#include "../BaseClass/BaseClass.h"
#include <string>

class Entry{

    private:
        DateTime enter;
        std::string name;
        std::string id;
        DateTime leave;


    public:
        virtual ~Entry(){
        };
        Entry(std::string ent, std::string name, std::string id, std::string leave=""):enter(ent.c_str()), name(name),
                                                                                    id(id), leave(leave.c_str()){
        };
        std::string toString() const;
};


#endif
