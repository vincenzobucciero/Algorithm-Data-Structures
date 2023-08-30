/**
 * • Implementare una struttura per insiemi disgiunti
 * • Implementare l'algoritmo per trovare le componenti connesse
*/

#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <list>

#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Grafi/InsiemiDisgiunti/vertice.h"

using namespace std;

template <typename T>
class Nodo {
    private:
        Vertice<T>* vertice;
        list<Vertice<T>*> listaAdiacenza;
    public:
        Nodo(Vertice<T>* vertice);

        Vertice<T>* getVertice() { return this->vertice; }
        list<Vertice<T>*> getLista() { return this->listaAdiacenza; }

        void append(Vertice<T>* vertice);

        friend ostream& operator<<(ostream& out, const Nodo<T>& obj) {
            out << *obj.vertice << " --> ";
            for(auto i : obj.listaAdiacenza)
                out << *i << " --> ";
            out << "NULL";

            return out;
        }
};

template <typename T>
Nodo<T>::Nodo(Vertice<T>* vertice) {
    this->vertice = vertice;
}

template <typename T>
void Nodo<T>::append(Vertice<T>* vertice) {
    this->listaAdiacenza.push_back(vertice);
}

#endif //NODO_H