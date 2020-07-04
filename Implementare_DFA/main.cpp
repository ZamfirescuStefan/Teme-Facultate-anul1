#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("config_automat");
class DFA{
public:
    int nr_stari;
    int nr_chr_alfabet;
    char alfabet[1001];
    int stare_initiala;
    int nr_stari_finale;
    int stari_finale[10001];
    int nr_tranzitii;
    vector <int > mat[100][100];
    int poz_in_alfabet( char a);

public:

    DFA();

    void display_mat();     ///afisare matrice de adiacenta

    void evaluate ( int n, char cuv[]);

};

int DFA::poz_in_alfabet(char a) {
    for ( int i = 0; i < nr_chr_alfabet; i ++ ){
        if (a == alfabet[i])
            return i;
    }
}

DFA::DFA() {
    {
        int x,y,poz;
        char val;
        char alf[1001];
        f >> nr_stari;
        f >> nr_chr_alfabet;
        for ( int i = 0; i < nr_chr_alfabet ; i++ )
            f >> alfabet[i];
        alfabet[nr_chr_alfabet] = '$';
        f >> stare_initiala;
        f >> nr_stari_finale;
        for ( int i = 0; i < nr_stari_finale; i ++ )
            f >> stari_finale[i];
        f >> nr_tranzitii;
        for ( int i = 0; i < nr_tranzitii; i ++ ){
            f >> x;
            f >> val;
            f >> y;
            poz = poz_in_alfabet(val);
            mat[x][poz].push_back(y);
        }
    }
}

void DFA::display_mat() {
    for ( int i = 0 ; i < nr_stari; i++ )
        for( int j = 0; j < nr_chr_alfabet; j++)
            for ( int k = 0; k < mat[i][j].size(); k++)
                cout << mat[i][j][k] << " ";
}

void DFA::evaluate(int n, char *cuv) {
    int p = 0; // poz din cuv pe care o inspectez
    int ch = 0;
    int poz;    /// pozitia
    int stare_actuala = stare_initiala;
    int ok = 0;
    while ( p < n - 1){             /// cat timp mai exista litere in cuv
        poz = poz_in_alfabet(cuv[p]);
        if(!mat[stare_actuala][poz].empty()) {
            for (int i = 0; i < mat[stare_actuala][poz].size(); i++)
                stare_actuala = mat[stare_actuala][poz][i];
            p++;
        }
        else{
            ok = 1;
            cout << "Cuvantul nu este acceptat de automat";
            break;
        }
    }
    if ( ok != 1)
    {
        int ok1 = 0;
        for ( int i = 0; i < nr_stari_finale; i ++ )
            if (stare_actuala == stari_finale[i])
                ok = 1;
    if ( ok == 0)
        cout << "Cuvantul nu este acceptat de automat";
    else
        cout << "Cuvantul este acceotat de automat";
    }
}

int main(){
    int n = 0 ;
    DFA ob1;
    char cuv[1000];
    /*cout << ob1.nr_stari << " ";
    cout << ob1.nr_chr_alfabet << " ";
    cout << ob1.nr_tranzitii;*/
    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> cuv[i];
    ob1.evaluate(n,cuv);
    return  0;
}