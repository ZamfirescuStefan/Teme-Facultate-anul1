//
// Created by zamfirescu on 09.04.2020.
//

#ifndef TEMA_2_POO_MATRICE_H
#define TEMA_2_POO_MATRICE_H


#include <iosfwd>
#include <iostream>
class Matrice {
    int **a;
    int dim;

    friend void swap ( Matrice & first, Matrice & second);
public:
    Matrice()
            : dim{0}
    {
        a = nullptr;
    };
    Matrice(int dim, int **mat);

    Matrice(const Matrice & ob );

    virtual ~Matrice();

    Matrice operator = (Matrice ob);
    friend class Graf_orientat;

    friend class Graf;
    friend std::ostream &operator << ( std::ostream & out, const Matrice & ob);
    friend std::istream & operator >> (std::istream & in, Matrice & ob);

    int **getA() const;

    int getDim() const;
};


#endif //TEMA_2_POO_MATRICE_H
