//
// Created by zamfirescu on 03.04.2020.
//

#ifndef TEMA_2_LFA_AUTOMAT_H
#define TEMA_2_LFA_AUTOMAT_H

#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Automat {
    char alfabet[50];
    int nr_de_stari;
    int nr_chr_alfabet;
    int stare_initiala;
    int nr_stari_finale;
    int nr_tranzitii;
    std::vector < int > tranzitii[100][260];
    std::vector < int > lambda_inch[100];
    int stari_finale[100];
public:
    Automat():nr_de_stari{0}, nr_chr_alfabet{0},stare_initiala{0}, nr_stari_finale{0},nr_tranzitii{0} {};
    void lambda_inchidere ();
    void backup();
    void delta_inchidere (vector <int> delta[100][260]);
    void LNFA_to_NFA ();
    void NFA_to_DFA();
    void afis_matrice(vector < int > delta[100][260]);
    void eliminare_noduri_identice(vector < int> delta[100][260]);
    void upload_backup();
    void afis_tranzitii();
    set < int > act_stari_finale();
    friend std::ifstream & operator>> (std::istream & i, Automat & ob1 );
    int aparitie( int elem, int vector[], int lungime);
};


#endif //TEMA_2_LFA_AUTOMAT_H
