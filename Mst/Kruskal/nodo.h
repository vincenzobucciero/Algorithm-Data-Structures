/**
 * Implementazione dell'algoritmo di Kruskal (Minimum Spanning Tree)
*/

#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <list>

#include "vertice.h"

using namespace std;

template <typename T>
class Nodo {
    private:
        Vertice<T>* vertice;
        list<pair<Vertice<T>*, int>> listaAdiacenza;
    public:
        Nodo(Vertice<T>* vertice) { this->vertice = vertice; }

        Vertice<T>* getVertice() { return this->vertice; }
        list<pair<Vertice<T>*, int>> getLista() { return this->listaAdiacenza; }

        void append(Vertice<T>* vertice, int peso) { this->listaAdiacenza.push_back(make_pair(vertice, peso)); }

        friend ostream& operator<<(ostream& out, const Nodo<T>& obj) {
            out << *obj.vertice << " -> ";
            for(const auto& pair : obj.listaAdiacenza)
                out << pair.first->getValue() << " (" << pair.second << " peso) -> ";
            out << "NULL";

            return out;
        }
};

#endif //NODO_H