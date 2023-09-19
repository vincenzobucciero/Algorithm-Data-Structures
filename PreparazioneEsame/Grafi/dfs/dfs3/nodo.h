#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>

#include "vertice.h"

using namespace std;

template <typename T, typename WeightType>
class Nodo {
    private:
        Vertice<T>* vertice;
        list<pair<Vertice<T>*, WeightType>> listaAdiacenza;
    public:
        Nodo(Vertice<T>* vertice) {this->vertice = vertice;}

        Vertice<T>* getVertice() {return this->vertice;}
        list<pair<Vertice<T>*, WeightType>> getList() {return this->listaAdiacenza;}

        void append(Vertice<T>* vertice, WeightType peso) {listaAdiacenza.push_back(make_pair(vertice, peso));}

        friend ostream& operator<<(ostream& out, const Nodo<T, WeightType>& obj) {
            out << *obj.vertice << " --> ";
            for(auto i : obj.listaAdiacenza)
                out << "(" << i.first->getValue() << ", Peso: " << i.second << ") --> ";
            out << "NULL";
            return out;
        }
};


#endif