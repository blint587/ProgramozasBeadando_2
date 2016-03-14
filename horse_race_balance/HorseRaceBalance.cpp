//
// Created by Balint on 2016.03.13..
//

#include <vector>
#include "HorseRaceBalance.h"
#include <iostream>

HorseRaceBalance::HorseRaceBalance(std::vector<double> & incomes, bool zero_is_a_loss):_incomes(incomes),
                                                                                       _zero_is_a_loss(zero_is_a_loss){
}

HorseRaceBalance::HorseRaceBalance(std::vector<double> & incomes): HorseRaceBalance(incomes, true) {
}


double HorseRaceBalance::balance() const {

    double sum = 0;
    for(auto pwin = this->_incomes.begin(); pwin < this->_incomes.end(); pwin++){
        sum += * pwin;
    }
    return sum;
}

bool HorseRaceBalance::won_affter_loisng_(int const k) const {
    unsigned int count_of_loss = 0;
    bool is_it = false;
    if (this->_incomes.size() > 0) { // protection against indexing problems
        auto p_current = this->_incomes.begin();

        while (!is_it && p_current < this->_incomes.end() - 1) {

            if ((*p_current <= 0. && this->_zero_is_a_loss) || (*p_current < 0. && !this->_zero_is_a_loss)) {
                ++count_of_loss;
            }
            else {
                count_of_loss = 0;
            }
            p_current++;
            if (*p_current > 0. && this->_zero_is_a_loss) {
                is_it = (k <= count_of_loss);
            }
            else if (*p_current >= 0. && !this->_zero_is_a_loss) {
                is_it = (k <= count_of_loss);
            }
        }
    }

    return is_it;
}
