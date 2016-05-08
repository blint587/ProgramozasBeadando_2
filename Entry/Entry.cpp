#include "Entry.h"


std::string Entry::toString() const{
    std::stringstream ss;

    ss << enter.toString() << " " << name << " " << id << " " << (leave.isvalid()?leave.toString():"");
    return ss.str();
}
