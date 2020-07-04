//
// Created by zamfirescu on 14.05.2020.
//

#ifndef TEMA_3_POO_GESTIONARECONTURI_H
#define TEMA_3_POO_GESTIONARECONTURI_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include "ContEconomii.h"
template <class T>
class GestionareConturi {
    static int index_cont;
    std :: unordered_map<int,std :: pair <T, std :: vector <std :: pair <std :: string , int > > > > conturi;
public:
    GestionareConturi();
    ~GestionareConturi();

    void operator +=( const T & ob);
    void depunere( int id_cont, int suma);

    double checksold (int id_cont);
};

template<>
class GestionareConturi <ContEconomii>{
    static int index_cont1;
    std :: unordered_map<int,std :: pair <ContEconomii, std :: vector <std :: pair <std :: string , int > > > > conturi;
public:
    void afisare_conturi(){
        for(int i = 0; i < 10; ++i)
            if(conturi[i].first.getTip_rata() == 12)
                std :: cout << conturi[i].first << "\n";
    }
    double checksold (int id_cont){
        return conturi[id_cont].first.checkSold();
    }
    void operator +=( const ContEconomii & ob){
        conturi[index_cont1].first = ob;
        conturi[index_cont1].second.push_back({"initializare cont ", 0});
        ++index_cont1;
    };
};



template<class T>
GestionareConturi<T>::GestionareConturi() {
}

template<class T>
GestionareConturi<T>::~GestionareConturi() {
}

template<class T> int  GestionareConturi<T> ::index_cont = 0;

template<class T>
void GestionareConturi<T>::operator+=(const T &ob) {
    conturi[index_cont].first = ob;
    conturi[index_cont].second.push_back({"initializare cont ", 0});
    ++index_cont;
}

template<class T>
void GestionareConturi<T>::depunere(int id_cont, int suma) {
    conturi[id_cont].first.depunere(suma);
    conturi[id_cont].second.push_back({"depunere", suma});
}

template<class T>
double GestionareConturi<T>::checksold(int id_cont) {
    return conturi[id_cont].first.checkSold();
}



#endif //TEMA_3_POO_GESTIONARECONTURI_H