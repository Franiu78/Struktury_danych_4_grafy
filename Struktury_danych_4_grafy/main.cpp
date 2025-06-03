#include <iostream>
#include <vector>
#include "grafy_macierz.h"
#include "grafy_lista.h"
#include "grafy_krawedzie.h"
#include "test.h"
#include <fstream>

using namespace std;


int main() {
    ofstream fout("wyniki.csv");
    fout << "Struktura;Algorytm;V;Gestosc;SredniCzas_ns\n";
    fout.close();





    int tab[5] = { 10, 20, 50, 100, 200};

    for (int i = 0; i < 5; i++) {
        for (int j = 25; j <= 100; j += 25) {
            TestLista(tab[i], j);
            TestMacierz(tab[i], j);
            TestKrawedzie(tab[i], j);
        }
    }

    return 0;
}


