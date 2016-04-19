
#ifndef PROGRAMOZAS_ELSO_BEADANDO_READIN_H
#define PROGRAMOZAS_ELSO_BEADANDO_READIN_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>
#include "ReadIn.h"
#include <vector>


template<typename T>
T read_in(std::istream &s, bool correct(T), std::string const msg){
    T x;

    bool error; // variable which defines if there is an error
    std::string tmp; // temp variable to empty the input stream buffer into if error

    do{

        std::cout << msg;
        s >> x;
        error = s.fail() || (s.peek() != '\n' && s.peek() != ' ');
        if (error || !correct(x)){
            s.clear();
            getline(s, tmp, '\n');
            std::cout << "Incorrect input: " << tmp <<  " Please try again!" << std::endl;
        }

    }while (error || !correct(x));
    return x;
}

template<typename T>
bool read_in_one(std::istream &s, bool correct(T), std::string const msg, std::vector<T> &out_vector){
    T x;

    bool error; // variable which defines if there is an error
    std::string tmp; // temp variable to empty the input stream buffer into if error

    do{

        std::cout << msg;
        s >> x;
        if (s.eof()){
            s.clear();
            return false;
        }
        error = s.fail() || (s.peek() != '\n' && s.peek() != ' ');
        if (error || !correct(x)){
            s.clear();
            getline(s, tmp, '\n');
            std::cout << "Incorrect input: " << tmp << std::endl;
        }

    }while (error || !correct(x));
    out_vector.push_back(x);
    return !error;
}

template<typename T>
std::vector<T> read_in_vector(std::istream &s, bool correct(T), std::string const msg){
    std::vector<T> v;

    while(read_in_one(s,correct, msg, v));

    return v;
};


#endif //PROGRAMOZAS_ELSO_BEADANDO_READIN_H
