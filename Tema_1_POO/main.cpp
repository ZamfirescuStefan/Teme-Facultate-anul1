#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;
const int  max_len = 1000;
class multime
{
private:
    int len;
    int set[max_len];
    static void conv_list_to_set( int v[], int &n );        /// transforma un vector intr - 0 multime
public:
    multime(int v[], int n);           /// constructor de initializare

    multime();

    const int *get_set() const;       /// returneaza multimea

    int get_len()const;                 /// returneaza lungimea

    void display();                     /// metoda de afisare

     ~multime();                        /// destructor

    multime(const multime &ob1 );           /// constructor de copiere

    multime operator+ (const multime& M2 );        /// reuniunea a 2 multimi

    multime operator* (const multime& M2 );        /// intersectia a 2 multimi

    multime operator- (const multime& M2);         /// diferenta dintre 2 multimi`

    friend ostream & operator << ( ostream & o, const multime & ob1);
    friend istream & operator >> ( istream &i, multime & ob1);

};
const int *multime::get_set() const {
    return set;
}

multime::multime(int v[],int n = 0)
{
    conv_list_to_set(v,n);
    for (int i = 0; i < n; i ++ )
        set[i] = v[i];
    len = n;
}

multime multime::operator+(const multime& M2)       /// supraincarcarea operatorului cu reunirea a 2 multimi
{                                   /// observatie ambele multimi sunt sortate
    int len1 = M2.get_len();
    const int *a = M2.get_set();
    int vect[max_len];
    int index = -1;
    for (int i = 0; i <= len+len1+21; i ++ )
        vect[i] = -1;
    int i = 0, j = 0;
    while(i < len1 && j < len) {
        if (a[i] < set[j]) {
            index++;
            vect[index] = a[i];
            i++;
        } else {
            index++;
            vect[index] = set[j];
            j++;
        }
    }
    while( i < len1 )
    {
        index++;
        vect[index] = a[i];
        i++;
    }
    while ( j < len )
    {
        index++;
        vect[index] = set[j];
        j++;
    }
    multime ob1(vect,index + 1 );

    return ob1;
}

multime::multime(const multime &ob1)        /// constructor de copiere
{
    len = ob1.get_len();
    const int *a = ob1.get_set();
    for (int i = 0; i < len; i++)
        set[i] = a[i];

}

void multime::display() {
    cout << "{";
    int i;
    if ( len >= 1)
    {
        for ( i = 0; i < len - 1; i++ )
        cout << set[i] << ","<<  " ";
        cout << set[i];
    }
    cout << "}";
    cout << "\n";
}

int multime::get_len() const {
    return this->len;
}

multime multime::operator*(const multime& M2) {
    int len1 = M2.get_len();
    const int *a = M2.get_set();
    int vect[len1 + len];
    for( int i = 0; i < len1 + len + 1; i++ ){
        vect[i] = 0;
    }
    int index = -1;
    int i = 0, j = 0;
    while ( i < len1 && j < len){
        if (a[i] < set[j])
            i++;
        else
        if(set[j] < a[i] )
            j++;
        else {
            vect[++index] = set[j];
            i++;
            j++;
        }
    }
    multime ob1(vect, index + 1);
    return  ob1;
}

multime multime::operator-(const multime& M2) {
    int len1 = M2.get_len();
    const int *a = M2.get_set();
    int vect[len1 + len];
    for( int i = 0; i < len1 + len + 1; i++ ){
        vect[i] = 0;
    }
    int index = -1;
    for ( int i = 0; i < len; i ++ ){
        int ok = 0;
        for ( int j = 0; j < len1; j++ )
            if ( set[i] == a[j] ){
                ok = 1;
                break;
            }
        if ( ok == 0 )
            vect[++index] = set[i];
    }
    multime ob1(vect, index + 1);
    return ob1;
}

multime::~multime() {
    len = 0;
}

void multime::conv_list_to_set(int *v, int &n) {
    int creare_set[max_len];
    int index = 0;
    if (n > 0) {
        sort(v, v + n);
        creare_set[index++] = v[0];
        for (int i = 1; i < n; i++)
            if (v[i] != v[i - 1])
                creare_set[index++] = v[i];
        for (int i = 0; i < index; i++)
            v[i] = creare_set[i];
        n = index;
    }
}

ostream &operator<<(ostream &o, const multime &ob1) {
    o << "{";
    int i;
    if (ob1.len >= 1) {
        for (i = 0; i < ob1.len - 1; i++)
            o << ob1.set[i] << "," << " ";
        o << ob1.set[i];
    }
    o << "}";
    o << "\n";
    return o;
}

multime::multime() {
    len = 0;
}

istream & operator>>(istream & i, multime & ob1) {
    i >> ob1.len;
    for (int j = 0; j < ob1.len; j ++ ){
        i >> ob1.set[j];
    }
    return i;
}


int main()
{
    char nume_fisier[max_len];
    cout << "Dati nume fisier :";
    cin.get(nume_fisier,max_len);
    cin.get();
    ifstream f(nume_fisier);
    multime ob1, ob2;
    f >> ob1;
    f >> ob2;
    f.close();
    multime ob3 = ob1 + ob2;
    multime ob4 = ob1 * ob2;
    multime ob5 = ob1 - ob2;
    cout <<"Nultimea 1 : " << ob1 << "Multimea 2 : " << ob2 << "Reuniunea celor 2 multimi : "<< ob3 <<"Intersectia celor 2 multimi : " <<  ob4 << "Multimea 1 - Multimea 2 : " << ob5;

    return 0;
}