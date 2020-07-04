//
// Created by zamfirescu on 09.04.2020.
//

#ifndef TEMA_2_POO_LISTA_H
#define TEMA_2_POO_LISTA_H

#include "Vector.h"

class Lista {
protected:
    Vector *l;
    size_t len;
    friend void swap ( Lista & first, Lista & second);
public:
    Lista()
            : l(nullptr)
            , len{0}
    {};
    Lista(const Lista & ob);

    virtual ~Lista();
    friend std::istream &operator >> ( std::istream &i , Lista &ob );
    friend std::ostream &operator << ( std::ostream & o, const Lista & ob);
    Lista operator = ( Lista ob);

    friend class Graf_neorientat;

    virtual int getElement(int i, int j){
        return l[i].vct[j];
    }

    int getLen() const;
};



#endif //TEMA_2_POO_LISTA_H
