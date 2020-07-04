#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "ContBancar.h"
#include "GestionareConturi.h"
#include "ContEconomii.h"
#include "ContCurent.h"
#include "Data.h"

int main() {
    std::ifstream f("date.in");
    std::ofstream g("date.out");
    try{
        /*Data data;
        std :: cin >> data;
        std ::cout << data;*/


//        ContBancar ob1;
//        std::cin >> ob1;
//        std::cout << ob1;
        ContEconomii ob1;
        f >> ob1;
//        g << ob1;
        ContCurent ob2;
        f >> ob2;
//        g << ob2;

        GestionareConturi<ContCurent> gestiuneC;
        gestiuneC += ob2;
        std :: cout << gestiuneC.checksold(0) << "\n";
        gestiuneC += ob2;
        std :: cout << gestiuneC.checksold(1) << "\n";

        GestionareConturi<ContEconomii> gestiuneE;
        gestiuneE += ob1;
        std :: cout << gestiuneE.checksold(0) << "\n";
        gestiuneE.afisare_conturi();
    }
    catch (Exception &e) {
        std::cout << e.getMessage();
    }

    return 0;
}
