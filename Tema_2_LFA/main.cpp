#include <iostream>
#include <bits/stdc++.h>
#include "Automat.h"
using namespace std;
ifstream  f("date.in");
ofstream  g("date.out");
int main() {
    Automat a1;
    f >> a1;
    a1.backup();
//    a1.LNFA_to_NFA();
    a1.NFA_to_DFA();
    a1.afis_tranzitii();
    return 0;
}
