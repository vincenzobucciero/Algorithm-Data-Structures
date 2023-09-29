//
// Created by vincenzo on 29/09/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_GRAFO_H
#define ALGORITHM_DATA_STRUCTURES_GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include "vertice.h"
#include "nodo.h"

using namespace std;

template <typename T>
class Grafo {
private:
    vector<Nodo<T>> grafo;
    list<Vertice<T>*> getListAdj(Vertice<T>* vertice);
    queue<T> myQueue;
public:
    Grafo() { }
    queue<T> getMyQueue() {return this->myQueue;}
    int searchIndirizzo(Vertice<T>* vertice);
    Vertice<T>* getIndirizzoVertice(T value);
    void addNodo(Nodo<T> nodo);
    void addArco(Vertice<T>* v1, Vertice<T>* v2);
    void bfs(Vertice<T>* sorgente);

    friend ostream& operator<<(ostream& out, Grafo<T>& obj) {
        for(auto i : obj.grafo)
            out << i << endl;
        return out;
    }
};

template <typename T>
list<Vertice<T>*> Grafo<T>::getListAdj(Vertice<T>* vertice) {
    for(auto i : grafo) {
        if(i.getVertice() == vertice)
            return i.getList();
    }
    return grafo.at(0).getList();
}

template <typename T>
int Grafo<T>::searchIndirizzo(Vertice<T>* vertice) {
    for(int i = 0; i < grafo.size(); i++) {
        if(this->grafo.at(i).getVertice()->getValue() == vertice->getValue())
            return i;
    }
    return -1;
}

template <typename T>
Vertice<T>* Grafo<T>::getIndirizzoVertice(T value) {
    for(auto i : grafo) {
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
}

template <typename T>
void Grafo<T>::addNodo(Nodo<T> nodo) {
    grafo.push_back(nodo);
}

template <typename T>
void Grafo<T>::addArco(Vertice<T> *v1, Vertice<T> *v2) {
    int index = searchIndirizzo(v1);
    grafo.at(index).append(v2);
}

template <typename T>
void Grafo<T>::bfs(Vertice<T> *sorgente) {
    ofstream output;
    output.open("fileOutput.txt");
    for(auto u : grafo) {
        u.getVertice()->setColor(Color::white);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }
    sorgente->setColor(Color::gray);
    sorgente->setPredecessore(nullptr);
    sorgente->setDistanza(0);
    queue<Vertice<T>*> q;
    q.push(sorgente);
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        list<Vertice<T>*> adj = getListAdj(u);
        for(auto v : adj) {
            if(v->getColor() == Color::white) {
                v->setColor(Color::gray);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza()+1);
                q.push(v);
            }
        }
        u->setColor(Color::black);
        output << u->getValue() << endl;
    }
}

#endif //ALGORITHM_DATA_STRUCTURES_GRAFO_H
