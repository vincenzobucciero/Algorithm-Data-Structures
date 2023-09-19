#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>

#include "vertice.h"
#include "nodo.h"

using namespace std;

template <typename T, typename WeightType>
class Grafo {
    private:
        vector<Nodo<T, WeightType>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T>* vertice);

        int tempo;

        queue<T> q;

        void dfsVisit(Vertice<T>* vertice);
    public:
        Grafo() {  }

        queue<T> getQueue() {return this->q;}

        int searchIndirizzo(Vertice<T>* vertice);
        Vertice<T>* getIndirizzoVertice(T value);

        void addNodo(Nodo<T, WeightType> nodo);
        void addArco(Vertice<T>* v1, Vertice<T>* v2, WeightType peso);

        void dfs();

        friend ostream& operator<<(ostream& out, Grafo<T, WeightType>& obj) {
            for(auto i : obj.grafo)
                out << i << endl;
            return out;
        }
};

template <typename T, typename WeightType>
list<Vertice<T>*> Grafo<T, WeightType>::getListAdj(Vertice<T>* vertice) {
    list<Vertice<T>*> adjVertices;
    
    for (auto& node : grafo) {
        if (node.getVertice() == vertice) {
            for (const auto& edge : node.getList()) {
                adjVertices.push_back(edge.first);
            }
            break;
        }
    }
    
    return adjVertices;
}

template <typename T, typename WeightType>
int Grafo<T, WeightType>::searchIndirizzo(Vertice<T>* vertice) {
    for(int i = 0; i < grafo.size(); i++) {
        if(this->grafo.at(i).getVertice()->getValue() == vertice->getValue())
            return i;
    }
    return -1;
}

template <typename T, typename WeightType>
Vertice<T>* Grafo<T, WeightType>::getIndirizzoVertice(T value) {
    for(auto i : grafo) {
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
}

template <typename T, typename WeightType>
void Grafo<T, WeightType>::addNodo(Nodo<T, WeightType> nodo) {
    grafo.push_back(nodo);
}

template <typename T, typename WeightType>
void Grafo<T, WeightType>::addArco(Vertice<T>* v1, Vertice<T>* v2, WeightType peso) {
    int vertice = searchIndirizzo(v1);
    grafo.at(vertice).append(v2, peso);
}

template <typename T, typename WeightType>
void Grafo<T, WeightType>::dfsVisit(Vertice<T>* vertice) {
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

template <typename T, typename WeightType>
void Grafo<T, WeightType>::dfs() {
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