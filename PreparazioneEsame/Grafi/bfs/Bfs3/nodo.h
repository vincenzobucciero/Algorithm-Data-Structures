#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>

#include "vertice.h"

using namespace std;

template <typename T>
class Nodo {
    private:
        Vertice<T>* vertice;
        list<Vertice<T>*> listaAdiacenza;
    public:
        Nodo(Vertice<T>* vertice) {this->vertice = vertice;}

        Vertice<T>* getVertice() {return this->vertice;}
        list<Vertice<T>*> getList() {return this->listaAdiacenza;}

        void append(Vertice<T>* vertice) {listaAdiacenza.push_back(vertice);}

        friend ostream& operator<<(ostream& out, const Nodo<T>& obj) {
            out << *obj.vertice << " --> ";
            for(auto i : obj.listaAdiacenza)
                out << *i << " --> ";
            out << "NULL";
            return out;
        }
};

#endif