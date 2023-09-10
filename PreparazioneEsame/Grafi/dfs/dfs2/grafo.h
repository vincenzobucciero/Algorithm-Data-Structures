#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>

#include "nodo.h"
#include "vertice.h"

using namespace std;

template <typename T>
class Grafo {
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T>* vertice);

        int time;

        queue<T> myQueue;
        void dfsVisit(Vertice<T>* vertice);
    public:
        Grafo() {  }

        queue<T> getQueue() {return this->myQueue;}
        int searchIndirizzo(Vertice<T>* vertice);
        Vertice<T>* getIndirizzoVertice(T value);

        void addNodo(Nodo<T> nodo) {grafo.push_back(nodo);}
        void addArco(Vertice<T>* v1, Vertice<T>* v2);

        void dfs();

        friend ostream& operator<<(ostream& out, Grafo<T>& obj) {
            for(auto i : obj.grafo)
                out << i << endl;
            return out;
        }
};

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
void Grafo<T>::addArco(Vertice<T>* v1, Vertice<T>* v2) {
    int vertice = searchIndirizzo(v1);
    grafo.at(vertice).append(v2);
}

template <typename T>
list<Vertice<T>*> Grafo<T>::getListAdj(Vertice<T>* vertice) {
    for(auto i : grafo) {
        if(i.getVertice() == vertice)
            return i.getList();
    }
    return grafo.at(0).getList();
}

template <typename T>
void Grafo<T>::dfs() {
    for(auto u : grafo) {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        time = 0;
    }
    for(auto u : grafo) {
        if(u.getVertice()->getColor() == Color::WHITE)
            dfsVisit(u.getVertice());
    }
}

template <typename T>
void Grafo<T>::dfsVisit(Vertice<T>* vertice) {
    vertice->setColor(Color::GRAY);
    vertice->setTInizio(time++);
    
    list<Vertice<T>*> adj = getListAdj(vertice);

    for(auto v : adj) {
        if(v->getColor() == Color::WHITE) {
            v->setPredecessore(vertice);
            dfsVisit(v);
        }
    }
    vertice->setColor(Color::BLACK);
    vertice->setTFine(time++);
}


#endif