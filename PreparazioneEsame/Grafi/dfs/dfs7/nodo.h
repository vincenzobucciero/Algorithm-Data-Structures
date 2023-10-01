//
// Created by vincenzo on 01/10/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_NODO_H
#define ALGORITHM_DATA_STRUCTURES_NODO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include "vertice.h"

using namespace std;

template <typename T>
class Nodo {
private:
    Vertice<T>* vertice;
    list<Vertice<T>*> listAdj;
public:
    Nodo(Vertice<T>* vertice) {this->vertice = vertice;}

    Vertice<T>* getVertice() {return this->vertice;}
    list<Vertice<T>*> getList() {return this->listAdj;}

    void append(Vertice<T>* vertice) {this->listAdj.push_back(vertice);}

    friend ostream& operator<<(ostream& out, const Nodo<T>& obj) {
        out << *obj.vertice << " --> ";
        for(auto i : obj.listAdj)
            out << *i << " --> ";
        out << "NULL";
        return out;
    }
};

#endif //ALGORITHM_DATA_STRUCTURES_NODO_H
