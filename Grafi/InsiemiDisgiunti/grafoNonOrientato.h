/**
 * • Implementare una struttura per insiemi disgiunti
 * • Implementare l'algoritmo per trovare le componenti connesse
*/

#ifndef GRAFONONORIENTATO_H
#define GRAFONONORIENTATO_H

#include <iostream>
#include <vector>
#include <list>

#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Grafi/InsiemiDisgiunti/vertice.h"
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Grafi/InsiemiDisgiunti/nodo.h"

using namespace std;

template <typename T>
class GrafoNonOrientato {
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaAdj(Vertice<T>* vertice);

        int tempo;

        //Funzioni per insiemi disgiunti
        void makeSet(Vertice<T>* vertice);
        void unionSet(Vertice<T>* u, Vertice<T>* v);
        Vertice<T>* findSet(Vertice<T>* vertice);
        void link(Vertice<T>* u, Vertice<T>* v);

        void dfsVisit(Vertice<T>* vertice);
    public:
        GrafoNonOrientato() {  }

        void addNodo(Nodo<T> nodo);
        void addArco(int i, Vertice<T>* vertice);

        void dfs();

        void connectedComponent();
        void connectedComponentView();

        friend ostream& operator<<(ostream& out, const GrafoNonOrientato<T>& obj){
            for (auto i: obj.grafo)
                out << i << endl;
            return out;
        }
};

template <typename T>
list<Vertice<T>*> GrafoNonOrientato<T>::getListaAdj(Vertice<T>* vertice) {
    for(auto i : grafo) {
        if(i.getVertice() == vertice)
            return i.getLista();
    }
    return grafo.at(0).getLista();
}

template <typename T>
void GrafoNonOrientato<T>::addNodo(Nodo<T> nodo) {
    this->grafo.push_back(nodo);
}

template <typename T>
void GrafoNonOrientato<T>::addArco(int i, Vertice<T>* vertice) {
    this->grafo.at(i).append(vertice);
}

template <typename T>
void GrafoNonOrientato<T>::makeSet(Vertice<T>* vertice) {
    vertice->setPredecessore(vertice);
    vertice->setRank(0);
}

template <typename T>
Vertice<T>* GrafoNonOrientato<T>::findSet(Vertice<T>* vertice) {
    if(vertice->getPredecessore() != vertice)
        vertice->setPredecessore(findSet(vertice->getPredecessore()));
    return vertice->getPredecessore();
}

template <typename T>
void GrafoNonOrientato<T>::unionSet(Vertice<T>* u, Vertice<T>* v) {
    this->link(findSet(u), findSet(v));
}

template <typename T>
void GrafoNonOrientato<T>::link(Vertice<T>* u, Vertice<T>* v) {
    if(u->getRank() > v->getRank())
        u->setPredecessore(v);
    else {
        v->setPredecessore(u);
        if(u->getRank() == v->getRank())
            v->setRank(v->getRank() + 1);
    }
}

template <typename T>
void GrafoNonOrientato<T>::dfsVisit(Vertice<T>* u) {
    u->setColor(Color::GRAY);
    u->setTempoInizioVisita(tempo++);
    auto adj = getListaAdj(u);
    for(auto v : adj) {
        if(v->getColor() == Color::WHITE) {
            v->setPredecessore(u);
            this->dfsVisit(v);
        }
    }
    u->setColor(Color::BLACK);
    u->setTempoFineVisita(tempo++);
}

template <typename T>
void GrafoNonOrientato<T>::dfs() {
    for(auto u : grafo) {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
    }
    tempo = 0;
    for(auto u : grafo) {
        if (u.getVertice()->getColor() == Color::WHITE)
            dfsVisit(u.getVertice());
    }
    for (auto u : grafo) {
        cout << *u.getVertice() << " - Inizio: " << u.getVertice()->getTempoInizioVisita() << ", Fine: " << u.getVertice()->getTempoFineVisita() << endl;
    }
}

template <typename T>
void GrafoNonOrientato<T>::connectedComponent() {
    for(auto u : grafo)
        makeSet(u.getVertice());
    for(auto u : grafo) {
        auto adj = getListaAdj(u.getVertice());
        for(auto v : adj)
            if(findSet(v)->getValue() != findSet(u.getVertice())->getValue())
                this->unionSet(v, u.getVertice());
    }
}

template <typename T> 
void GrafoNonOrientato<T>::connectedComponentView(){
    cout << "***Componenti Connesse**" << endl;
    for (auto v: grafo)
        cout << *(v.getVertice()) <<  " " << *(v.getVertice()->getPredecessore()) << endl;
}

#endif //GRAFONONORIENTATO_H