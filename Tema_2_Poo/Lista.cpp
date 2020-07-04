//
// Created by zamfirescu on 09.04.2020.
//

#include "Lista.h"


std::istream &operator>>(std::istream &i, Lista &ob) {
    i >> ob.len;
    ob.l = new Vector [ob.len];
    for ( size_t j = 0; j < ob.len; j++ )
        i >> ob.l[j];
    return i;
}

std::ostream &operator<<(std::ostream &o, const Lista &ob) {
    if ( ob.len > 1)
        o << "Cei " <<  ob.len << " vectori sunt : \n";
    else
        o << "Lista contine un singur vector\n";
    for ( size_t i = 0; i < ob.len; i++ )
        o << ob.l[i];
    return o;
}

Lista Lista::operator=( Lista ob) {
    swap(*this, ob);
    return *this;
}

Lista::~Lista()  {
    delete [] l;
    len = 0;
}

void swap(Lista &first, Lista &second) {
    using std::swap;
    swap(first.len,second.len);
    swap(first.l,second.l);
}

Lista::Lista(const Lista &ob) {
    l = new Vector [ob.len];
    len = ob.len;
    for( size_t i = 0; i < ob.len; ++i )
        l[i] = ob.l[i];
}

int Lista::getLen() const {
    return int(len);
}
