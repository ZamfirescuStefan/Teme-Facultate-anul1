//
// Created by zamfirescu on 14.05.2020.
//

#include "ContCurent.h"

double ContCurent:: cost_tranzactie = 0.3;
int ContCurent :: nr_tranz_gratis_initial = 10;

void ContCurent::retragere(double suma) {
    if ( nr_tranzactii_gratis > 0){
        if ( suma > sold )
            throw Exception("Tranzanctie esuata.....Suma insuficienta :(");
        else
            sold -= suma;
        --nr_tranzactii_gratis;
    }
    else{
        suma = suma + suma* cost_tranzactie;
        if( suma > suma )
            throw Exception("Tranzactie esuata ... Suma insuficienta :(");
        else
            sold -= suma;
    }
}

void ContCurent::depunere(double suma) {
    sold += suma;
}

std::ostream &operator<<(std::ostream &os, const ContCurent &curent) {
    os << static_cast<const ContBancar &>(curent) << "\nnr tranzactii gratis ramase : " << curent.nr_tranzactii_gratis;
    return os;
}

std::istream &operator>>(std::istream &in,ContCurent &curent) {
    in >> static_cast<ContBancar &>(curent);
    curent.nr_tranzactii_gratis = ContCurent::nr_tranz_gratis_initial;
}
