#pragma once
#include <vector>
using namespace std;

struct Edge {
    int u, v, value;
    Edge(int u_, int v_, int value_) : u(u_), v(v_), value(value_) {}
};

class graf_krawedzie {
private:
    int V;
    vector<Edge> edges;

public:
    graf_krawedzie(int wierzcholki);

    void dodajKrawedz(int u, int v, int waga);
    void LosowyGraf(int gestosc, int minValue = 1, int maxValue = 10);
    void wypisz();
    bool BellmanFord(int start);
    void Dijkstra(int start); // opcjonalnie
};
