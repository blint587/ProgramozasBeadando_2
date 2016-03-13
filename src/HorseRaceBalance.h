//
// Created by Balint on 2016.03.13..
//

#ifndef PROGRAMOZAS_ELSO_BEADANDO_HORSERACEBALANCE_H
#define PROGRAMOZAS_ELSO_BEADANDO_HORSERACEBALANCE_H

class HorseRaceBalance {

    private:
        // the list of the wins and loses ove the year
        std::vector<double> _incomes;

        // the task does not specifies if the income 0 is a win or a loss
        // by default 0 income is a loss
        bool _zero_is_a_loss;

    public:
        //default initializer, sets the _zero_is_a_loss to true
        HorseRaceBalance(std::vector<double>&);
        HorseRaceBalance(std::vector<double>&, bool);

        // gives bak the current balance
        double balance() const;
        bool won_affter_loisng_(int const) const;


};

#endif //PROGRAMOZAS_ELSO_BEADANDO_HORSERACEBALANCE_H
