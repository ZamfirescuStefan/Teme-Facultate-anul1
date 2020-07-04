//
// Created by zamfirescu on 10.04.2020.
//

#include "Graf_neorientat.h"



std::istream &operator>>(std::istream &in, Graf_neorientat &ob) {
    in >> ob.L;
    ob.nr_noduri = ob.L.getLen();
    return  in;
}

std::ostream &operator<<(std::ostream &out, const Graf_neorientat &ob) {
    out << ob.L ;
    return out;
}

Graf_neorientat Graf_neorientat::operator=(Graf_neorientat ob) {
    swap(*this,ob);
    return *this;
}

void swap(Graf_neorientat &first, Graf_neorientat &second) {
    using std::swap;
    swap(first.nr_noduri, second.nr_noduri);
    swap(first.L, second.L);
}

void Graf_neorientat::afis_muchii() {
    std:: cout << "Muchtiile sunt :" << "\n";
    for ( size_t j = 0; j < L.len; ++j)
        for ( size_t i = 0; i < L.l[j].dim; ++i )
            std :: cout << j + 1<< " - " << L.l[j].vct[i] << "\n";
}

void Graf_neorientat::parcurgere_latime_aux(int *vizitari, int nod_start, int *comp, int &nr_comp) {
    vizitari[nod_start] = 1;
    comp[nod_start] = nr_comp;
    int c[LENGTH];
    int primul = 0;
    int ultimul = 0;
    c[ultimul] = nod_start;
    while ( primul <= ultimul){
        for (size_t i = 0; i < L.l[c[primul]].dim; ++i )
            if ( vizitari[L.l[c[primul]].vct[i]] == 0 ){
                ultimul++;
                c[ultimul] =  L.l[c[primul]].vct[i];
                vizitari[L.l[c[primul]].vct[i] ] = 1;
            }
        primul++;
    }
    ++nr_comp;
}

int Graf_neorientat::nod_nevizitat(int *vizitari) { /// returneaza primul nod nevizitat sau -1 in caz contrar
    for ( int i = 0; i < nr_noduri; ++i )
        if ( vizitari[i] == 0 )
            return i;
    return -1;
}

int *Graf_neorientat::componente_conexe(int nod_start) {

    static int comp[LENGTH];
    int comp_index = 0;
    int viz[LENGTH];
    for ( int i = 0; i < LENGTH; ++i)
        viz[i] = 0,
        comp[i] = 0;
    parcurgere_latime_aux(viz, nod_start, comp, comp_index);
    while (nod_nevizitat(viz) != -1){
        int nod = nod_nevizitat(viz);
        parcurgere_latime_aux(viz,nod,comp, comp_index);
    }
    return comp;
}



