//
// Created by zamfirescu on 08.05.2020.
//

#ifndef TEMA_3_POO_CONTBANCAR_H
#define TEMA_3_POO_CONTBANCAR_H

#include <string>
#include <ostream>
#include <istream>
#include <exception>
#include <vector>
#include "Exception.h"
#include "Data.h"

class ContBancar {
protected:
    std::string detinator;
    Data deschidere_cont;
    double sold;
public:
    ContBancar();
    ContBancar(std::string detinator, std::string deschidereCont, double sold);

    friend std::ostream &operator<<(std::ostream &os, const ContBancar &bancar);
    friend std::istream &operator>> (std::istream &in, ContBancar &bancar);

    virtual int checkSold();

};


#endif //TEMA_3_POO_CONTBANCAR_H
