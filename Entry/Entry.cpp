#include "Entry.h"


std::string Entry::toString() const{
    std::stringstream ss;

    std::cout << enter << " " << name << " " << id << " " << (leave.isvalid()? leave.toString():"");
    return ss.str();
}
