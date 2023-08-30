/**
 * Implemenatre un algoritmo per effettuare l'ordinamento topologico
*/

#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <list>

#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Grafi/OrdinamentoTopologico/vertice.h"

using namespace std;

template <typename T>
class Nodo {
    private:
        Vertice<T>* vertice;
        list<Vertice<T>*> listaAdiacenza;
    public:
        Nodo(Vertice<T>* vertice) { this->vertice = vertice; }

        Vertice<T>* getVertice() { return this->vertice; }
        list<Vertice<T>*> getLista() { return this->listaAdiacenza; }

        void append(Vertice<T>* vertice) { listaAdiacenza.push_back(vertice); }

        friend ostream& operator<<(ostream& out, const Nodo<T>* obj) {
            out << *obj.vertice << " --> ";
            for(auto i : obj.listaAdiacenza)
                out << *i << " --> ";
            out << "NULL";

            return out;
        }
};


#endif //NODO_H