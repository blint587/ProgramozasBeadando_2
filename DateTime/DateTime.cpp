//
// Created by KlingonW on 2016-05-08.
//

#include "DateTime.h"


DateTime::DateTime(const char * s) {
    char *p1 = strchr(s, ':');

    if( p1 ){
        this->time_in_min = atoi(s) * 60;
        this->time_in_min += atoi(p1+1);
    }

}

std::string DateTime::toString() const {
    std::stringstream s;
    s << time_in_min/60 << ':' << time_in_min%60;
    return s.str();
}

std::ostream& operator<<(std::ostream& os, const DateTime &d){
    os << d.toString();
    return os;
}
