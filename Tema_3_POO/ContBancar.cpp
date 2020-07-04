//
// Created by zamfirescu on 08.05.2020.
//

#include "ContBancar.h"
#include <utility>

ContBancar::ContBancar(std::string detinator, std::string deschidereCont, double sold)
        : detinator(std::move(detinator))
        , deschidere_cont(std::move(deschidereCont))
        , sold(sold)
{}

ContBancar::ContBancar()
        : detinator("")
        , deschidere_cont("")
        , sold(-1)
{}

std::ostream &operator<<(std::ostream &os, const ContBancar &bancar) {
    os << "detinator: " << bancar.detinator <<"\n"<< "deschidere_cont: " << bancar.deschidere_cont << "\n" << "sold: "
       << bancar.sold << '\n';
    return os;
}

std::istream & operator >> (std::istream &in, ContBancar &bancar){
    std::string sir;
    getline(in, sir);

    if (sir == "")
        getline(in, bancar.detinator);
    else
        bancar.detinator = sir;

    if(bancar.detinator == "" || bancar.detinator == " ")
        throw Exception("nume invalid");
    in >> bancar.deschidere_cont;

    in >> bancar.sold;
}

int ContBancar::checkSold() {
    return sold;
}

