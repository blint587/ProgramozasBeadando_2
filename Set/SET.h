//
// Created by KlingonW on 2016-05-09.
//

#ifndef PROGRAMOZAS_ELSO_BEADANDO_SET_H
#define PROGRAMOZAS_ELSO_BEADANDO_SET_H

#include <vector>
#include <sstream>


template <typename T>
class SET {
    private:
        std::vector<T> s;
        int finde(T e){
            bool it_has = false;
            int i = 0;
            while(!it_has && i < size()){
                it_has = (e == s[i]);
                ++i;
            }
            if(!it_has){
                i = -1;
            }
            return i;
        }
    public:

        bool push(T e){
            bool it_has = has(e);
            if (!it_has){
                s.push_back(e);
            }
            return it_has;

        };

        bool has(T e){
            return finde(e) > -1;

        };

        bool pop(T e){
            int i = finde(e);

            if (i > -1){
                s.erase(s.begin()+(i-1));
            }
            return i > -1;
        };


        int size(){
            return s.size();
        };

        std::string toString(){
            std::stringstream ss;
            ss << "[ ";
            for(auto i = s.begin(); i < s.end(); i++){
                ss << *i << ", ";
            }
            ss << "]";
            return ss.str();
        }

};





#endif //PROGRAMOZAS_ELSO_BEADANDO_SET_H
