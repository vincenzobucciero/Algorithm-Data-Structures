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
    public:
        Grafo() {  }

        void addNodo(Nodo<T> nodo);
        void addArco(int i, Vertice<T>* vertice);

        void bfs(Vertice<T>* vertice);

        friend ostream& operator<<(ostream& out, Grafo<T>& obj) {
            for(auto i : obj.grafo)
                out << i << endl;
            return out;
        }
};

template <typename T>
void Grafo<T>::addNodo(Nodo<T> nodo) {
    this->grafo.push_back(nodo);
}

template <typename T>
void Grafo<T>::addArco(int i, Vertice<T>* vertice) {
    grafo.at(i).append(vertice);
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
void Grafo<T>::bfs(Vertice<T>* sorgente) {
    for(auto u : grafo) {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }
    sorgente->setColor(Color::GRAY);
    sorgente->setPredecessore(nullptr);
    sorgente->setDistanza(0);

    queue<Vertice<T>*> q;

    q.push(sorgente);

    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        list<Vertice<T>*> adj = getListAdj(u);
        for(auto v : adj) {
            if(v->getColor() == Color::WHITE) {
                v->setColor(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza()+1);
                q.push(v);
            }
        }
        u->setColor(Color::BLACK);
    }
}



#endif //GRAFO_H