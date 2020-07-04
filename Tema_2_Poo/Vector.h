//
// Created by zamfirescu on 08.04.2020.
//

#include <iostream>
#ifndef TEMA_2_POO_VECTOR_H

#define TEMA_2_POO_VECTOR_H
class Vector {
    size_t dim;
    int *vct;

    friend void swap (Vector & first, Vector & second);
public:
    Vector()
            : dim{0}
            , vct(nullptr)
    {};
    Vector(unsigned long n, int *v);
    Vector(const Vector & ob);
    virtual ~Vector();

    Vector operator = (Vector ob);
    friend std::ostream & operator << (std::ostream & o, const Vector  & ob );
    friend std::istream &operator >> (std::istream & i, Vector & ob);

    friend class Lista;
    friend class Graf_neorientat;
    void afis ();

    int & operator[](size_t index);
};


#endif //TEMA_2_POO_VECTOR_H
