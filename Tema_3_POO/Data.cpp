//
// Created by zamfirescu on 15.05.2020.
//

#include "Data.h"


void Data::validare_data() {
/// verificare data valida
    std::vector<char> separator = {'/', '.', '-'};
    int ok = 0;
    for (auto it : separator )
    {
        if(data[2] == it && data[5] == it) //  data este felul asta : 02/23/2000//
        {
            ok = 1;
            break;
        }
    }
    if (data.size() != 10) // daca contine prea multe cifre
        ok = 0;
    for(int i = 0; i < data.size(); ++i)
        if( i != 2 || i != 5){
            if (!( (int)data[i] >= 0 || (int)data[i] <= 9))
                ok = 0;
        }
    if( ((int)data[0] == '0' && (int)data[1]  == '0' )
        ||   ((int)data[3] == '0' && (int)data[4]  == '0' )
        || ((int)data[6] == '0' ) )
        ok = 0;

    if ( ok == 0)
        throw Exception("data introdusa este invalida");
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
    os << "data: " << data.data;
    return os;
}

std::istream &operator>>(std::istream &in, Data &data) {
    in >> data.data;
    data.validare_data();
    return in;
}

Data Data::operator=(const char *a) {
    return basic_string::operator=(a);
}

