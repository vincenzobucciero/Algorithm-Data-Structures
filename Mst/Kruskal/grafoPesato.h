/**
 * Implementazione dell'algoritmo di Kruskal (Minimum Spanning Tree)
*/

#ifndef GRAFOPESATO_H
#define GRAFOPESATO_H

#include <iostream>
#include <vector>
#include <list>

#include "vertice.h"
#include "nodo.h"

using namespace std;

template <typename T>
class GrafoPesato {
    private: 
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaAdj(Vertice<T>* vertice);

        void makeSet(Vertice<T>* vertice);
        void unionA(Vertice<T>* u, Vertice<T>* v);
        void link(Vertice<T>* u, Vertice<T>*v);
        Vertice<T>* findSet(Vertice<T>* vertice);

    public:
        GrafoPesato();

        void addNodo(Nodo<T> nodo);
        void addArco(int i, Vertice<T>* vertice);

        void mstKruskal();
};

#endif //GRAFOPESATO_H