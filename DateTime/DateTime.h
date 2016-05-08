
#ifndef PROGRAMOZAS_ELSO_BEADANDO_DATETIME_H
#define PROGRAMOZAS_ELSO_BEADANDO_DATETIME_H

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "../BaseClass.h"

class DateTime: public BaseClass {

public: // custom exceptions
    class DateTimeInitializationException: public std::exception{
        virtual const char* what() const throw()
        {
            return "Incorrect Date Time format";
        }
    };

    private:

        int time_in_min = -1;
        friend bool operator<(DateTime const &d1 , DateTime const &d2 ){return d1.time_in_min < d2.time_in_min;}
    public:
        DateTime(const char*);
        virtual ~DateTime(){};
        virtual std::string toString() const;
        bool isvalid() const { return time_in_min > 0;};


};


inline bool operator==( DateTime const &d1 , DateTime const &d2 ) { return !(d1<d2 || d2<d1); }
inline bool operator!=( DateTime const &d1 , DateTime const &d2 ) { return d1<d2 || d2<d1; }
inline bool operator<=( DateTime const &d1 , DateTime const &d2 ) { return !(d2<d1); }
inline bool operator>=( DateTime const &d1 , DateTime const &d2 ) { return !(d1<d2); }
inline bool operator>( DateTime const &d1 , DateTime const &d2 )  { return d2<d1; }


#endif //PROGRAMOZAS_ELSO_BEADANDO_DATETIME_H
