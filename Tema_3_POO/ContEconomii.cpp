//
// Created by zamfirescu on 08.05.2020.
//

#include "ContEconomii.h"

ContEconomii::ContEconomii()
        : rata_dobanda{-1}
        , tip_rata{-1}
{}

std::ostream &operator<<(std::ostream &os, const ContEconomii &economii) {
    os << static_cast<const ContBancar &>(economii) << "\n" <<  "rata: " << economii.rata_dobanda <<"\n"<<"tip_rata: "<<economii.tip_rata<< "\n"<< "istoric_sold: ";
    for(int i = 0; i < economii.istoric_sold.size(); ++i ){
        os << economii.istoric_sold[i] << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &in, ContEconomii &economii) {
    in >> (ContBancar&)economii;
    in >> economii.rata_dobanda;
    in >> economii.tip_rata;
    int ok = 0;
    if (economii.tip_rata == 3 || economii.tip_rata == 6 || economii.tip_rata == 9 || economii.tip_rata == 12 )
        ok = 1;
    if( ok == 0)
        throw Exception("Tip rata invalid");
    int nr_elem_istoric;
    in >> nr_elem_istoric;
    int elem = 0;
    for( int i = 0; i < nr_elem_istoric; ++i){
        in >> elem;
        economii.istoric_sold.push_back(elem);
    }
    return in;
}

void ContEconomii::setIstoricSold(const std::vector<int> &istoricSold) {
    istoric_sold = istoricSold;
}

void ContEconomii::depunere(int suma) {
    sold += suma;
}

int ContEconomii::getTip_rata() {
    return tip_rata;
}
