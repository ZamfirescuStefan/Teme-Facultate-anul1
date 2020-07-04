#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Lista.h"
#include "Matrice.h"
#include "Graf_neorientat.h"
#include "Graf_orientat.h"
using namespace std;
enum tip_graf{
    graf_neorientat, graf_orientat
};
int main() {
    ifstream f("date.in");
    int tip;
    f >> tip;
    tip_graf tip_gf;
    tip_gf = static_cast<tip_graf>(tip);
    switch (tip_gf) {
        case graf_neorientat :
        {
            try {
                Graf_neorientat ob;
                f >> ob;
                Graf_neorientat ob1;
                ob1 = ob;
                int nod_start;
                cout << "Dati un nod de inceput pentru elem compexe: ";
                cin >> nod_start;
                int *v = ob1.componente_conexe(nod_start);
                cout << "vectorul de componente conexe:0 \n" ;
                for ( int i = 0; i < ob.getNrNoduri(); ++i )
                    cout << v[i] <<" ";
                cout << "\n";
                cout << ob1;
            }
            catch (const char *e) {
                cout << e << "\n";
            }
            break;
        }
        case graf_orientat:{
            Graf_orientat ob;
            f >> ob;    /// citire 3 matrici pentru verificare memory leak la citire
            f >> ob;
            f >> ob;
            Graf_orientat ob1;
            ob1 = ob;
            cout << ob1;
            break;
        }
    }
    f.close();
    return 0;

}