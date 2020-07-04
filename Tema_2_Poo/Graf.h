//
// Created by zamfirescu on 10.04.2020.
//

#ifndef TEMA_2_POO_GRAF_H
#define TEMA_2_POO_GRAF_H

#include <iostream>
class Graf {
protected:
    int nr_noduri;
public:
    explicit Graf (int n = 0)
            : nr_noduri{n}
    {}
    ~Graf() {
        nr_noduri = 0;
    }
    virtual void afis_muchii() = 0;
};

#endif //TEMA_2_POO_GRAF_H
