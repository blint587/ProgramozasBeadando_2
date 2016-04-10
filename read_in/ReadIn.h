
#ifndef PROGRAMOZAS_ELSO_BEADANDO_READIN_H
#define PROGRAMOZAS_ELSO_BEADANDO_READIN_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>
#include "ReadIn.h"
#include <vector>

// function which determines if the input is correct
// current task indicates no limitation to the input

bool c(double){
    return true;
}

template<typename T>
T read_in_one(std::istream &s, bool correct(T), std::string const msg, bool const exit_if_error){
    T x;

    bool error; // variable which defines if there is an error
    std::string tmp; // temp variable to empty the input stream buffer into if error

    do{
        std::cout << msg;
        s >> x;
        error = s.fail() || s.peek() != '\n';
        if (error || !correct(x)){
            if (exit_if_error){
                // raise some exception
            }
            else {
            s.clear();
            getline(s, tmp, '\n');
            std::cout << "incorrect input: " << tmp << std::endl;
            }
        }

    }while (error || !correct(x));
    return x;
}

template<typename T>
std::vector<T> read_in_vector(unsigned int n, std::istream &s, bool correct(T), std::string const msg,
                              bool const exit_if_error){
    std::vector<T> v(n);

    for(unsigned int i = 0; i < n; ++i){
        v[i] = (read_in_one(s, correct, msg, exit_if_error));
    }
    return v;
};


#endif //PROGRAMOZAS_ELSO_BEADANDO_READIN_H
