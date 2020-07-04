//
// Created by zamfirescu on 08.05.2020.
//

#ifndef TEMA_3_POO_CONTECONOMII_H
#define TEMA_3_POO_CONTECONOMII_H

#include "ContBancar.h"
#include <iostream>

class ContEconomii: public ContBancar{
    double rata_dobanda;
    int tip_rata;
    std::vector<int> istoric_sold;
public:
    ContEconomii();

    friend std::ostream &operator<<(std::ostream &os, const ContEconomii &economii);
    friend std::istream &operator>>(std::istream &in, ContEconomii &economii);

    void setIstoricSold(const std::vector<int> &istoricSold);
    void depunere( int suma);
    int getTip_rata();
};


#endif //TEMA_3_POO_CONTECONOMII_H
