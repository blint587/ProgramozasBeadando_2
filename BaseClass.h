//
// Created by KlingonW on 2016-05-08.
//

#ifndef PROGRAMOZAS_ELSO_BEADANDO_BASECLASS_H
#define PROGRAMOZAS_ELSO_BEADANDO_BASECLASS_H

#include <string>

class BaseClass {
public:
    virtual std::string toString() const =0;
    virtual ~BaseClass(){};
protected:
    friend std::ostream& operator<<(std::ostream &os, const BaseClass &d){
        os << d.toString();
        return os;
    };

};


#endif //PROGRAMOZAS_ELSO_BEADANDO_BASECLASS_H
