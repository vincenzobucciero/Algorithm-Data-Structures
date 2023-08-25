/**
 * Implementazione della visità in profondità DFS in un grafo orientato
*/

#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <list>

#include "vertice.h"

using namespace std;

template <typename T>
class Nodo {
    private:
        Vertice<T>* vertice;
        list<Vertice<T>*> listaAdiacenza;
    
    public:
        Nodo(Vertice<T>* vertice);

        //metodi getter
        Vertice<T>* getVertice() { return this->vertice; }
        list<Vertice<T>*> getList() { return this->listaAdiacenza; }

        void append(Vertice<T>* vertice);

        friend ostream& operator<<(ostream& out, const Nodo<T>* obj) {
            out << *obj->vertice << " --> ";
            for(auto i : obj->listaAdiacenza)
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