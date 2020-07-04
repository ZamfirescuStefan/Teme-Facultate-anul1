//
// Created by zamfirescu on 03.04.2020.
//

#include "Automat.h"
#include <bits/stdc++.h>
using namespace std;
ifstream &operator>>(istream &i, Automat &ob1) {
    i >> ob1.nr_de_stari;
    i >> ob1.nr_chr_alfabet;
    for ( int j = 0; j < ob1.nr_chr_alfabet; j ++ )
        i >> ob1.alfabet[j];
    ob1.alfabet[ob1.nr_de_stari] = '$';
    i >> ob1.stare_initiala;
    i >> ob1.nr_stari_finale;
    for ( int j = 0; j < ob1.nr_stari_finale; j++ )
        i >> ob1.stari_finale[j];
    i >> ob1.nr_tranzitii;
    int x,y;
    char chr;
    for ( int j = 0; j < ob1.nr_tranzitii; j ++ )
    {
        i >> x;
        i >> chr;
        i >> y;
        ob1.tranzitii[x][int(chr)].push_back(y);
    }
    return dynamic_cast<ifstream &>(i);
}


void Automat::afis_matrice(vector < int > delta[100][260]) {
    ofstream g("date.out");
    for ( int i = 0; i < nr_de_stari; i++,g << "\n")
    {
        g << i << " : ";
        for (int i1 = 0; i1 < nr_chr_alfabet; i1++) {
            int j = alfabet[i1];

            for (size_t k = 0; k < delta[i][j].size(); k++) {
                g << delta[i][j][k] << " ";
            }
            g << "\t\t";
        }
    }
}

void Automat:: lambda_inchidere() {
    vector < int > noduri_finale;
    queue < int > noduri_de_verificat;
    for ( int nod = 0; nod < nr_de_stari; nod++ ) {
        noduri_finale.clear();
        noduri_de_verificat.push(nod);
        noduri_finale.push_back(nod);
        while (!noduri_de_verificat.empty()) {
            int element = noduri_de_verificat.front();
            for(size_t i = 0; i < tranzitii[element]['$'].size(); i++) {
                int ok = 0;
                for(size_t k = 0; k < noduri_finale.size(); k++)
                    if (noduri_finale[k] == tranzitii[element]['$'][i])
                        ok = 1;
                if (ok == 0)
                    noduri_finale.push_back(tranzitii[element]['$'][i]);
                noduri_de_verificat.push(tranzitii[element]['$'][i]);
            }
            noduri_de_verificat.pop();
        }
        lambda_inch[nod] = noduri_finale;
    }
}


void Automat::afis_tranzitii() {
    ofstream g("date.out");
    for ( int i = 0; i < nr_de_stari; i++)
        for (int j = 0; j < 256; j++){
            for(size_t k = 0; k < tranzitii[i][j].size();k ++) {
                g << i << " " << char(j) << " " << tranzitii[i][j][k] << "\n";
            }
        }
}

void Automat::delta_inchidere(vector < int > delta[100][260]) {
    lambda_inchidere();
    vector < int > vct_aux;
    set < int > set1;
    set < int > solutie;
    for( int i = 0; i < nr_de_stari; i++ ) {
        for (int i1 = 0; i1 < nr_chr_alfabet; i1++) {
            int j = alfabet[i1];
            vct_aux = lambda_inch[i];
            for (size_t k = 0; k < vct_aux.size(); k++)
                set1.insert(tranzitii[vct_aux[k]][j].begin(), tranzitii[vct_aux[k]][j].end());
            for (auto k = set1.begin(); k != set1.end(); k++) {
                vct_aux = lambda_inch[*k];
                for (size_t cnt = 0; cnt < vct_aux.size(); cnt++)
                    solutie.insert(vct_aux.begin(), vct_aux.end());
            }
            for (auto it = solutie.begin(); it != solutie.end(); it++)
                delta[i][j].push_back(*it);
            solutie.clear();
            set1.clear();
            vct_aux.clear();
        }
    }
}

void Automat::eliminare_noduri_identice(vector <int > delta[100][260]) {
    set<int> noduri_de_sters;
    for (int i = 0; i < nr_de_stari - 1; i++) {
        for (int j = i + 1; j < nr_de_stari; j++) {
            int ok = 0;
            for (int k = 0; k < nr_chr_alfabet; k++) {
                int chr = alfabet[k];
                if (delta[i][chr] != delta[j][chr]){
                    ok = 1;
                    break;
                }
            }
            int s = aparitie(j,stari_finale,nr_stari_finale) + aparitie(i,stari_finale,nr_stari_finale);
            if (ok == 0 && (s == 0 || s == 2 ))
                noduri_de_sters.insert(j);

        }
        for ( auto it = noduri_de_sters.begin(); it != noduri_de_sters.end(); it++){
            int elem = *it;
            for( int i1 = 0; i1 < nr_de_stari; i1++ )
                if ( i1 == elem )
                    for ( int j1 = 0; j1 < 256; j1++ )
                        delta[i1][j1].clear();
                else{
                    for( int m = 0; m < nr_chr_alfabet; m ++ ){
                        int j1 = alfabet[m];
                        int ok = 0;
                        int ok1 = 0;
                        for (size_t k = 0; k < delta[i1][j1].size(); k++ ){
                            if ( delta[i1][j1][k] == elem ){
                                delta[i1][j1].erase(delta[i1][j1].begin()+k);
                                ok1 = 1;
                            }

                            if( delta[i1][j1][k] == i)
                                ok = 1;
                        }
                        if(ok == 0  && ok1 == 1)
                            delta[i1][j1].push_back(i);
                    }
                }
        }
        noduri_de_sters.clear();
    }
}

void Automat::backup() {
    ofstream out("backup");
    out << nr_de_stari << "\n";
    out << nr_chr_alfabet << "\n";
    for ( int i = 0; i < nr_chr_alfabet; i++ )
        out << alfabet[i] << " ";
    out << "\n";
    out << stare_initiala << "\n";
    out << nr_stari_finale << "\n";
    for ( int i = 0; i < nr_stari_finale; i++ )
        out << stari_finale[i] << " ";
    out << "\n";
    out << nr_tranzitii << "\n";
    for ( int i = 0; i < nr_de_stari; i++)
        for (int j = 0; j < 256; j++){
            for(size_t k = 0; k < tranzitii[i][j].size();k ++) {
                out << i << " " << char(j) << " " << tranzitii[i][j][k] << "\n";
            }
        }
    out.close();
}

void Automat::upload_backup() {
    ifstream in("backup");
    in >> nr_de_stari;
    in >> nr_chr_alfabet;
    for ( int j = 0; j < nr_chr_alfabet; j ++ )
        in >> alfabet[j];
    in >> stare_initiala;
    in >> nr_stari_finale;
    for ( int j = 0; j < nr_stari_finale; j++ )
        in >> stari_finale[j];
    in >> nr_tranzitii;
    int x,y;
    char chr;
    for ( int i = 0; i < nr_de_stari; i++ )
        for( int j = 0; j < 256; j++ )
            tranzitii[i][j].clear();
    for ( int j = 0; j < nr_tranzitii; j ++ )
    {
        in >> x;
        in >> chr;
        in >> y;
        tranzitii[x][int(chr)].push_back(y);
    }

}

void Automat::LNFA_to_NFA() {
    vector<int> delta[100][260];
    for (int i = 0; i < nr_de_stari; i++)
        for (int j = 0; j < nr_chr_alfabet; j++)
            delta[i][j].clear();
    set<int> stari_finale_NFA;
    lambda_inchidere();
    delta_inchidere(delta);
    stari_finale_NFA = act_stari_finale();
    int index = 0;
    for ( auto it = stari_finale_NFA.begin(); it != stari_finale_NFA.end(); it ++ )
        stari_finale[index++]=*it;
    nr_stari_finale = index;
    eliminare_noduri_identice(delta);
    ofstream g("date.out");
    ///Afisare matrice delta
    /* for ( int i = 0; i < nr_de_stari; i++)
         for (int j = 0; j < 256; j++){
             for(size_t k = 0; k < delta[i][j].size();k ++) {
                 g << i << " " << char(j) << " " << delta[i][j][k] << "\n";
             }
         }*/
    /// Actualizare automat
    /// reinitializare matitrice tranzitii
    for ( int i = 0; i < nr_de_stari; i ++)
        for ( int j = 0; j < 256; j++ )
            tranzitii[i][j].clear();
    for (int i = 0; i < nr_de_stari; i ++ )
        for ( int  j = 0; j < nr_chr_alfabet; j ++ ){
            int chr = alfabet[j];
            tranzitii[i][chr] = delta[i][chr];
        }
}
set < int > Automat::act_stari_finale() {
    set < int > stari_finale_NFA;
    for ( int i = 0; i < nr_de_stari; i++)
    {
        int ok = 0;
        for ( int j = 0; j < nr_stari_finale; j++) {
            for ( size_t k = 0; k < lambda_inch[i].size(); k++ )
                if ( stari_finale[j] == lambda_inch[i][k])
                    ok = 1;
        }
        if ( ok == 1)
            stari_finale_NFA.insert(i);
    }
    return stari_finale_NFA;
}

int Automat::aparitie(int elem, int *vector, int lungime) {
    for ( int i = 0; i < lungime; i++ )
        if (elem == vector[i])
            return 1;
    return 0;
}

void Automat::NFA_to_DFA() {
    queue < int > coada;
    set < int > lista_vizitari[100];
    lista_vizitari[0].insert(stare_initiala);
    int index_lv = 1; ///indexul de la lista de vizualizari
    coada.push(stare_initiala);
    while(!coada.empty()){
        int element = coada.front();
        for ( int j = 0; j < nr_chr_alfabet; j++ ) {
            int chr = alfabet[j];
            if (tranzitii[element][chr].size() > 1) {
                set<int> set_auxiliar;
                int poz = 0;
                set_auxiliar.insert(tranzitii[element][chr].begin(), tranzitii[element][chr].end());
                /// verificam daca exista acest nod in noduri de verificat
                int ok = 0;
                for (int i = 0; i < index_lv; i++) {
                    if (lista_vizitari[i] == set_auxiliar) {
                        ok = 1;
                        poz = i;
                        break;
                    }
                }
                if (ok == 0) { /// daca nu exista in lista de vizitari
                    nr_de_stari++;
                    int stare_noua = nr_de_stari - 1;
                    ///adau noua mea staare in lista de vizualizari
                    lista_vizitari[stare_noua].insert(tranzitii[element][chr].begin(), tranzitii[element][chr].end());
                    index_lv= stare_noua + 1;
                    coada.push(stare_noua);
                    for (int j1 = 0; j1 < nr_chr_alfabet; j1++) {
                        int chr1 = alfabet[j1];
                        set<int> set1;
                        for (auto it = set_auxiliar.begin(); it != set_auxiliar.end(); it++) {
                            set1.insert(tranzitii[*it][chr1].begin(), tranzitii[*it][chr1].end());
                        }
                        tranzitii[stare_noua][chr1].insert(tranzitii[stare_noua][chr1].end(), set1.begin(), set1.end());
                        int ok1 = 0;///actualizare stari finale (il adaugam pe stare noua in stari_finale)
                        for( auto k = set_auxiliar.begin(); k != set_auxiliar.end(); k++ )
                            for( int u = 0; u < nr_stari_finale; u++ ){
                                if( *k == stari_finale[u])
                                    ok1 = 1;
                            }
                        if( ok1 == 1 ){
                            ++nr_stari_finale;
                            stari_finale[nr_stari_finale - 1] = stare_noua;
                        }
                        set1.clear();
                    }
                    tranzitii[element][chr].clear();
                    tranzitii[element][chr].push_back(stare_noua);
                }
                else {
                    tranzitii[element][chr].clear();
                    tranzitii[element][chr].push_back(poz);
                }
                set_auxiliar.clear();
            }
            else{
                set < int > set2; // in aceast set o sa memoram tranzitia din starea "element" cu caracterul "chr"
                set2.insert(tranzitii[element][chr].begin(),tranzitii[element][chr].end());
                int ok = 0;
                for ( int i = 0; i < index_lv; i++ )
                    if( lista_vizitari[i] == set2 ){
                        ok  = 1;
                        break;
                    }
                if(ok == 0 ){
                    coada.push(tranzitii[element][chr][0]);
                    lista_vizitari[tranzitii[element][chr][0]].insert(tranzitii[element][chr][0]);
                }
            }
        }
        coada.pop();
    }
    for( int i = 0; i < index_lv; i++ ){
        if( lista_vizitari[i].empty())
            for(int j = 0; j < nr_chr_alfabet; j++ )
                tranzitii[i][int(alfabet[j])].clear();
    }
}
