#include "test.h"
#include "grafy_lista.h"
#include "grafy_macierz.h"
#include "grafy_krawedzie.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

void TestMacierz(int V, int gestosc, int proby) {
    ofstream fout("wyniki.csv", ios::app);

    vector<long long> sumy(2, 0); // Dijkstra, Bellman-Ford

    for (int i = 0; i < proby; ++i) {
        graf_macierz g(V);
        g.LosowyGraf(gestosc,1,1000);

        auto start = high_resolution_clock::now();
        g.Dijkstra(0);
        auto end = high_resolution_clock::now();
        sumy[0] += duration_cast<nanoseconds>(end - start).count();

        start = high_resolution_clock::now();
        g.BellmanFord(0);
        end = high_resolution_clock::now();
        sumy[1] += duration_cast<nanoseconds>(end - start).count();
    }

    fout << fixed;
    fout << "Macierz;Dijkstra;" << V << ";" << gestosc << ";" << sumy[0] / proby << endl;
    fout << "Macierz;BellmanFord;" << V << ";" << gestosc << ";" << sumy[1] / proby << endl;

    fout.close();
}


void TestLista(int V, int gestosc, int proby) {
    ofstream fout("wyniki.csv", ios::app);

    vector<long long> sumy(2, 0); // Dijkstra, Bellman-Ford

    for (int i = 0; i < proby; ++i) {
        graf_lista g(V);
        g.LosowyGraf(gestosc,1,1000);

        auto start = high_resolution_clock::now();
        g.Dijkstra(0);
        auto end = high_resolution_clock::now();
        sumy[0] += duration_cast<nanoseconds>(end - start).count();

        start = high_resolution_clock::now();
        g.BellmanFord(0);
        end = high_resolution_clock::now();
        sumy[1] += duration_cast<nanoseconds>(end - start).count();
    }

    fout << fixed;
    fout << "Lista;Dijkstra;" << V << ";" << gestosc << ";" << sumy[0] / proby << endl;
    fout << "Lista;BellmanFord;" << V << ";" << gestosc << ";" << sumy[1] / proby << endl;

    fout.close();
}

void TestKrawedzie(int V, int gestosc, int proby) {
    ofstream fout("wyniki.csv", ios::app);

    vector<long long> sumy(2, 0); // Dijkstra, Bellman-Ford

    for (int i = 0; i < proby; ++i) {
        graf_krawedzie g(V);
        g.LosowyGraf(gestosc,1,1000);

        auto start = high_resolution_clock::now();
        g.Dijkstra(0);
        auto end = high_resolution_clock::now();
        sumy[0] += duration_cast<nanoseconds>(end - start).count();

        start = high_resolution_clock::now();
        g.BellmanFord(0);
        end = high_resolution_clock::now();
        sumy[1] += duration_cast<nanoseconds>(end - start).count();
    }

    fout << fixed;
    fout << "Krawedzie;Dijkstra;" << V << ";" << gestosc << ";" << sumy[0] / proby << endl;
    fout << "Krawedzie;BellmanFord;" << V << ";" << gestosc << ";" << sumy[1] / proby << endl;

    fout.close();
}
