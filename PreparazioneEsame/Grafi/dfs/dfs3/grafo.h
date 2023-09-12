#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>

#include "vertice.h"
#include "nodo.h"

using namespace std;

template <typename T>
class Grafo {
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T>* vertice);

        int tempo;

        queue<T> q;

        void dfsVisit(Vertice<T>* vertice);
    public:
        Grafo() {  }

        queue<T> getQueue() {return this->q;}

        int searchIndirizzo(Vertice<T>* vertice);
        Vertice<T>* getIndirizzoVertice(T value);

        void addNodo(Nodo<T> nodo);
        void addArco(Vertice<T>* v1, Vertice<T>* v2);

        void dfs();

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
void Grafo<T>::addArco(Vertice<T>* v1, Vertice<T>* v2) {
    int vertice = searchIndirizzo(v1);
    grafo.at(vertice).append(v2);
}

template <typename T>
void Grafo<T>::dfsVisit(Vertice<T>* vertice) {
    vertice->setColor(Color::gray);
    vertice->setTempoInizioVisita(tempo++);
    
    list<Vertice<T>*> adj = getListAdj(vertice);

    for(auto u : adj) {
        if(u->getColor() == Color::white) {
            u->setPredecessore(vertice);
            dfsVisit(u);
        }
    }
    vertice->setColor(Color::black);
    vertice->setTempoFineVisita(tempo++);
    q.push(vertice->getValue());
}

template <typename T>
void Grafo<T>::dfs() {
    for(auto u : grafo) {
        u.getVertice()->setColor(Color::white);
        u.getVertice()->setPredecessore(nullptr);
        tempo = 0;
    }
    for(auto u : grafo) {
        if(u.getVertice()->getColor() == Color::white)  
            dfsVisit(u.getVertice());
    }
}

#endif