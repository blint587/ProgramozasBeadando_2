
#ifndef PROGRAMOZAS_ELSO_BEADANDO_DATETIME_H
#define PROGRAMOZAS_ELSO_BEADANDO_DATETIME_H

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

class DateTime {

    private:
        int time_in_min = -1;
        friend bool operator<(DateTime const &d1 , DateTime const &d2 ){return d1.time_in_min < d2.time_in_min;}
    public:
        DateTime(const char*);
        ~DateTime(){};
        std::string toString() const;

};

inline bool operator==( DateTime const &d1 , DateTime const &d2 ) { return !(d1<d2 || d2<d1); }
inline bool operator!=( DateTime const &d1 , DateTime const &d2 ) { return d1<d2 || d2<d1; }
inline bool operator<=( DateTime const &d1 , DateTime const &d2 ) { return !(d2<d1); }
inline bool operator>=( DateTime const &d1 , DateTime const &d2 ) { return !(d1<d2); }
inline bool operator>( DateTime const &d1 , DateTime const &d2 )  { return d2<d1; }


#endif //PROGRAMOZAS_ELSO_BEADANDO_DATETIME_H
