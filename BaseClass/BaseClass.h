//
// Created by KlingonW on 2016-05-08.
//

#ifndef PROGRAMOZAS_ELSO_BEADANDO_BASECLASS_H
#define PROGRAMOZAS_ELSO_BEADANDO_BASECLASS_H

#include <string>
#include <iostream>

class BaseClass {
protected:
    virtual std::string toString() const=0;
    friend std::ostream&operator<< (std::ostream & os , const BaseClass &b){
        os << b.toString();
        return os;
    }
public:
    virtual ~BaseClass(){};

};


#endif //PROGRAMOZAS_ELSO_BEADANDO_BASECLASS_H
