#include "grafy_krawedzie.h"
#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <limits>
#include <queue>
#include <functional> 


using namespace std;

graf_krawedzie::graf_krawedzie(int wierzcholki) : V(wierzcholki) {}

void graf_krawedzie::dodajKrawedz(int u, int v, int waga) {
    edges.emplace_back(u, v, waga);
}

void graf_krawedzie::LosowyGraf(int gestosc, int minValue, int maxValue) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, V - 1);
    uniform_int_distribution<> waga_losowa(minValue, maxValue);

    int max_krawedzi = V * (V - 1);
    int liczba_krawedzi = (gestosc * max_krawedzi) / 100;

    set<pair<int, int>> istniejace;

    while ((int)istniejace.size() < liczba_krawedzi) {
        int u = dis(gen);
        int v = dis(gen);
        if (u == v) continue;

        if (istniejace.insert({ u, v }).second) {
            int w = waga_losowa(gen);
            dodajKrawedz(u, v, w);
        }
    }
}

void graf_krawedzie::wypisz() {
    cout << "Lista krawedzi:\n";
    for (const auto& e : edges)
        cout << e.u << " -> " << e.v << " (waga: " << e.value << ")\n";
}

bool graf_krawedzie::BellmanFord(int start) {
    vector<int> dystans(V, numeric_limits<int>::max());
    dystans[start] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const auto& e : edges) {
            if (dystans[e.u] != numeric_limits<int>::max() && dystans[e.v] > dystans[e.u] + e.value) {
                dystans[e.v] = dystans[e.u] + e.value;
            }
        }
    }

    for (const auto& e : edges) {
        if (dystans[e.u] != numeric_limits<int>::max() && dystans[e.v] > dystans[e.u] + e.value) {
            cout << "Wykryto cykl ujemny!\n";
            return false;
        }
    }

    cout << "Najkrótsze odleg³oœci od " << start << ":\n";
    for (int i = 0; i < V; ++i) {
        if (dystans[i] == numeric_limits<int>::max())
            cout << i << ": brak drogi\n";
        else
            cout << i << ": " << dystans[i] << "\n";
    }

    return true;
}




void graf_krawedzie::Dijkstra(int start) {
    vector<int> dystans(V, numeric_limits<int>::max());
    vector<bool> odwiedzony(V, false);
    dystans[start] = 0;

    for (int i = 0; i < V; ++i) {
        int u = -1;

        // ZnajdŸ nieodwiedzony wierzcho³ek o najmniejszym dystansie
        for (int j = 0; j < V; ++j) {
            if (!odwiedzony[j] && (u == -1 || dystans[j] < dystans[u]))
                u = j;
        }

        if (u == -1 || dystans[u] == numeric_limits<int>::max())
            break;

        odwiedzony[u] = true;

        // Przejrzyj wszystkie krawêdzie wychodz¹ce z u
        for (const auto& e : edges) {
            if (e.u == u && dystans[e.v] > dystans[u] + e.value) {
                dystans[e.v] = dystans[u] + e.value;
            }
        }
    }

    // Wypisz wyniki
    cout << "Najkrótsze odleg³oœci od " << start << ":\n";
    for (int i = 0; i < V; ++i) {
        if (dystans[i] == numeric_limits<int>::max())
            cout << i << ": brak drogi\n";
        else
            cout << i << ": " << dystans[i] << "\n";
    }
}
