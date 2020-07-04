//
// Created by zamfirescu on 14.05.2020.
//

#ifndef TEMA_3_POO_CONTCURENT_H
#define TEMA_3_POO_CONTCURENT_H

#include <iostream>
#include "ContBancar.h"

class ContCurent: public ContBancar{
    static double cost_tranzactie; /// se reprezinta in procente din suma transferata
    static int nr_tranz_gratis_initial;
    int nr_tranzactii_gratis = nr_tranz_gratis_initial;

public:
    ContCurent() = default;
    void retragere(double suma);
    void depunere( double  suma);

    friend std::ostream &operator<<(std::ostream &os, const ContCurent &curent);
    friend std::istream &operator>>(std::istream &in, ContCurent &curent);
};


#endif //TEMA_3_POO_CONTCURENT_H
