//
// Created by zamfirescu on 09.04.2020.
//

#include "Matrice.h"

Matrice::Matrice(int dim1, int **mat) {
    dim = dim1;
    a = new int *[dim];
    for (int i = 0; i < dim; ++i )
        a[i] = new int [dim];
}

Matrice::~Matrice() {
    for ( int i = 0; i < dim; ++i )
        delete[] a[i];
    delete [] a;
}

Matrice::Matrice(const Matrice &ob) {
    dim = ob.dim;
    a = new int *[dim];
    for (int i = 0; i < dim; ++i )
        a[i] = new int [dim];
    for ( int i = 0; i < dim; ++i ){
        for (int j = 0; j < dim; ++j) {
            a[i][j] = ob.a[i][j];
        }
    }
}

std::istream & operator>>(std::istream &in, Matrice &ob) {
    in >> ob.dim;
    if ( ob.a != nullptr){
        for ( int i = 0; i < ob.dim; ++i )
            delete[] ob.a[i];
        delete [] ob.a;
    }
    ob.a = new int *[ob.dim];
    for (int i = 0; i < ob.dim; ++i )
        ob.a[i] = new int [ob.dim];
    for ( int i = 0; i < ob.dim; ++i )
        for ( int j = 0; j < ob.dim; ++j )
            in >> ob.a[i][j];
    return  in;
}

std::ostream &operator << (std::ostream &out, const Matrice &ob) {
    for ( int i = 0; i < ob.dim; ++i )
    {
        for (int j = 0; j < ob.dim ; ++j) {
            out << ob.a[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

Matrice Matrice::operator=(Matrice ob) {
    swap(*this, ob);
    return *this;
}

void swap(Matrice &first, Matrice &second) {
    using  std::swap;
    swap(first.dim, second.dim);
    swap(first.a, second.a);
}

int Matrice::getDim() const {
    return dim;
}

int **Matrice::getA() const {
    return a;
}
