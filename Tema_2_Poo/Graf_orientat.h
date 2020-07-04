//
// Created by zamfirescu on 10.04.2020.
//

#ifndef TEMA_2_POO_GRAF_ORIENTAT_H
#define TEMA_2_POO_GRAF_ORIENTAT_H

#include "Graf.h"
#include "Matrice.h"

class Graf_orientat : Graf{
    Matrice M;
    friend void swap ( Graf_orientat & first,Graf_orientat & second );
public:
    Graf_orientat ()
            : Graf(0)
            , M()
    {}

    Graf_orientat(const Graf_orientat & ob)
            : Graf(ob.nr_noduri)
            , M(ob.M)
    {}
    friend std::istream & operator >> ( std::istream & in, Graf_orientat & ob);

    friend std :: ostream &  operator << ( std::ostream & out, const Graf_orientat & ob);
    void afis_muchii ();

    int grad_intern ( int nod );
    int grad_extern ( int nod );
    Graf_orientat operator= ( Graf_orientat ob);
};


#endif //TEMA_2_POO_GRAF_ORIENTAT_H
