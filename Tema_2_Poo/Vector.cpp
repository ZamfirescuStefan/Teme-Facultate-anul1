//
// Created by zamfirescu on 08.04.2020.
//
#include <iostream>
#include "Vector.h"
Vector::Vector(unsigned long n, int *v) {
    dim = n;
    vct = new int[dim];
    for ( size_t i = 0; i < n; i++ )
        vct[i] = v[i];
}

void Vector::afis() {
    for ( size_t i = 0; i < dim; i++ )
        std::cout << vct[i] << " ";
    std::cout << "\n";
}

Vector::~Vector() {
    delete [] vct;
    dim = 0;
}

std::ostream &operator<<(std::ostream &o, const Vector &ob) {
    for (size_t i = 0; i < ob.dim; i++ )
        o << ob.vct[i] << " ";
    o << "\n";
    return o;
}

std::istream &operator>>(std::istream &i, Vector &ob) {
    i >> ob.dim;
    if ( ob.vct != nullptr)
        delete []ob.vct;
    ob.vct = new int [ob.dim];
    for (size_t j = 0; j < ob.dim; j++ )
        i >> ob.vct[j];
    return i;
}

Vector Vector::operator = ( Vector ob) {

    swap(*this, ob);
    return *this;
}

Vector::Vector(const Vector &ob) {
    dim = ob.dim;
    vct = new int [ob.dim];
    for ( size_t i = 0; i < dim; i++ )
        vct[i] = ob.vct[i];
}

void swap(Vector &first, Vector &second) {
    using std::swap;
    swap(first.dim,second.dim);
    swap(first.vct,second.vct);
}

int &Vector::operator[](size_t index) {
    if(index >= dim )
        throw "Index out of range";
    return vct[index];
}
