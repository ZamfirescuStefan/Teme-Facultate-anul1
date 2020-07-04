//
// Created by zamfirescu on 15.05.2020.
//

#ifndef TEMA_3_POO_DATA_H
#define TEMA_3_POO_DATA_H

#include <string>
#include "Exception.h"
#include <vector>
#include <ostream>
#include <iostream>

class Data : public std :: string{
    std :: string data;
public:
    Data()
            : data("")
    {};

    Data(const std::string &data) : data(data)
    {
        if( data != "")
            this->validare_data();
    }
    friend std::istream &operator >> (std :: istream & in, Data & data);
    friend std::ostream &operator<<(std::ostream &os, const Data &data);
//    Data operator = ( char a);
    Data operator = ( const char *a);
    void validare_data();
};


#endif //TEMA_3_POO_DATA_H
