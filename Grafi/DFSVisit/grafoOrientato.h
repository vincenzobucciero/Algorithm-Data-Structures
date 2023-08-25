/**
 * Implementazione della visità in profondità DFS in un grafo orientato
*/

#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include <iostream>
#include <vector>
#include <list>

#include "nodo.h"
#include "vertice.h"

using namespace std;

template <typename T>
class GrafoOrientato {
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaAdj(Vertice<T>* vertice);

        int time;
        void DFSVisit(Vertice<T>* vertice);
    
    public:
        GrafoOrientato() {  }

        void addNodo(Nodo<T> nodo);
        void addArco(int i, Vertice<T>* vertice);

        void DFS();
        void DFSIterative(Vertice<T>* sorgente);

        friend ostream& operator<<(ostream& out, GrafoOrientato<T>& obj) {
            for(auto i : obj.grafo) 
                out << i << endl;
            
            return out;
        }
};

template <typename T>
list<Vertice<T>*> GrafoOrientato<T>::getListaAdj(Vertice<T>* vertice) {
    for(auto i : grafo) {
        if(i.getVertice() == vertice)
            return i.getList();
    }

    return grafo.at(0).getList();
}

template <typename T>
void GrafoOrientato<T>::addNodo(Nodo<T> nodo) {
    grafo.push_back(nodo);
}

template <typename T>
void GrafoOrientato<T>::addArco(int i, Vertice<T>* vertice) {
    grafo.at(i).append(vertice);
}

template <typename T>
void GrafoOrientato<T>::DFS() {
    for(auto u : grafo) {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        time = 0;
    }
    for(auto u : grafo) {
        if(u.getVertice()->getColor() == Color::WHITE)
            DFSVisit(u.getVertice());
    }

    for (auto u : grafo) {
        cout << *u.getVertice() << " - Inizio: " << u.getVertice()->getT_inizio() << ", Fine: " << u.getVertice()->getT_fine() << endl;
    }
}

template <typename T>
void GrafoOrientato<T>::DFSVisit(Vertice<T>* u) {
    u->setColor(Color::GRAY);
    u->setT_inizio(time++);

    list<Vertice<T>*> adj = getListaAdj(u);
    
    for(auto v : adj) {
        if(v->getColor() == Color::WHITE) {
            v->setPredecessore(u);
            DFSVisit(v);
        }
    }
    u->setColor(Color::BLACK);
    u->setT_fine(time++);
}


#endif //GRAFOORIENTATO_H