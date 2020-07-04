//
// Created by zamfirescu on 10.04.2020.
//

#include "Graf_orientat.h"
#include "Matrice.h"

std::istream & operator>>(std::istream &in, Graf_orientat &ob) {
    ///numarul de noduri este acelasi cu nr de linii si de coloane ale matricei
    in >> ob.M;
    ob.nr_noduri = ob.M.getDim();
    return in;
}

std::ostream &operator<<(std::ostream &out, const Graf_orientat &ob) {
    out << "Matricea de adiacenta a grafului este: \n";
    out << ob.M;
    return out;
}

void swap(Graf_orientat &first, Graf_orientat &second) {
    using std :: swap;
    swap(first.nr_noduri, second.nr_noduri);
    swap(first.M, second.M);
}

Graf_orientat Graf_orientat::operator=(Graf_orientat ob) {
    swap(*this, ob);
    return *this;
}

void Graf_orientat::afis_muchii() {
    std :: cout << "Muchiile grafului sunt : \n";
    for ( int  i = 0; i < nr_noduri; ++i )
        for ( int j = 0; j < nr_noduri; ++j )
            if ( M.a[i][j] != 0)
                std :: cout << i << " -> " << j << "\n";
}

int Graf_orientat::grad_intern(int nod) {
    int contor = 0;
    for( int i = 0; i < nr_noduri; ++i )
        if ( M.a[i][nod] != 0 )
            ++contor;
    return contor;
}

int Graf_orientat::grad_extern(int nod) {
    int contor = 0;
    for( int i = 0; i < nr_noduri; ++i )
        if( M.a[nod][i] != 0 )
            ++contor;
    return  contor;
}
