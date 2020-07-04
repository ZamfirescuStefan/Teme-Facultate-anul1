//
// Created by zamfirescu on 10.04.2020.
//

#ifndef TEMA_2_POO_GRAF_NEORIENTAT_H
#define TEMA_2_POO_GRAF_NEORIENTAT_H

#include "Graf.h"
#include "Lista.h"
const int LENGTH = 100;
class Graf_neorientat : public Graf{
    Lista L;
    void parcurgere_latime_aux ( int *vizitari, int nod_start,int *comp, int & nr_comp); //fc care o sa ne ajute la functia componente conexe, primeste ca parametru si vectorul de vizitari
    int nod_nevizitat ( int *vizitari );
    friend void swap ( Graf_neorientat & first, Graf_neorientat & second);
public:
    Graf_neorientat()
                : Graf(0)
    {}
    ///folosim constructorul de copierece cel default
//    Graf_neorientat (const Graf_neorientat  & ob)
//            : Graf(ob.nr_noduri)
//            , L(ob.L)
//    {}

    explicit Graf_neorientat(Lista l, int n = 0)
            : Graf(n)
            , L(l)
    {}

    Graf_neorientat operator = ( Graf_neorientat ob);
    friend std::istream &operator >> (std:: istream & in, Graf_neorientat & ob);
    friend std::ostream &operator << (std:: ostream & out,const Graf_neorientat & ob);

    void afis_muchii() override ;

    int getNrNoduri() {
        return this->L.len;
    }
    int* componente_conexe(int nod_start);

};

#endif //TEMA_2_POO_GRAF_NEORIENTAT_H
