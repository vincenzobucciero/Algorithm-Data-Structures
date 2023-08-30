/**
 * Implemenatre un algoritmo per effettuare l'ordinamento topologico
*/

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Grafi/OrdinamentoTopologico/vertice.h"
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Grafi/OrdinamentoTopologico/nodo.h"

using namespace std;

template <typename T>
class Grafo {
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaAdj(Vertice<T>* vertice);

        int tempo;
        void dfsVisit(Vertice<T>* vertice);

        //è necessario per l'ordinamento topologico che il grafo sia una DAG ossia un grafo senza cicli
        //N.B i cicli si verificano quando tutti i nodi adiacenti sono grigi
        stack<Vertice<T>*> L;
        int cicli;
    public:
        Grafo() {  }

        void addNodo(Nodo<T> nodo);
        void addArco(int i, Vertice<T>* vertice);

        bool dfs();

        void ordTopologico();
        void printOrdTopologico();

        friend ostream& operator<<(ostream& out, Grafo<T>& obj) {
            for(auto i : obj.grafo)
                out << i << endl;
            return out;
        }
};

template <typename T>
list<Vertice<T>*> Grafo<T>::getListaAdj(Vertice<T>* vertice) {
    for(auto i : grafo) {
        if(i.getVertice() == vertice)
            return i.getLista();
    }
    return grafo.at(0).getLista(); 
}

template <typename T>
void Grafo<T>::dfsVisit(Vertice<T>* u) {
    u->setColor(Color::GRAY);
    u->setTempoInizioVisita(tempo++);
    auto adj = getListaAdj(u);
    for(auto v : adj) {
        if(v->getColore() == Color::WHITE) {
            v->setPredecessore(u);
            dfsVisit(v);
        } else if(v->getColore() == Color::GRAY) {
            cicli++;
        }
    }
    u->setColor(Color::BLACK);
    u->setTempoFineVisita(tempo++);
    L.push(u);
}

template <typename T>
bool Grafo<T>::dfs() {
    cicli = 0;
    for(auto u : grafo) {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        tempo = 0;
    }
    for(auto u : grafo) {
        if(u.getVertice()->getColore() == Color::WHITE)
            dfsVisit(u.getVertice());
    }

    if (cicli > 0)
        return true;
    else
        return false;
}

template <typename T>
void Grafo<T>::addNodo(Nodo<T> nodo) {
    this->grafo.push_back(nodo);
}

template <typename T>
void Grafo<T>::addArco(int i, Vertice<T>* vertice) {
    this->grafo.at(i).append(vertice);
}

template <typename T>
void Grafo<T>::ordTopologico() {
    if(!dfs()) {
        cout << "Ordinamento Topologico:" << endl;
        printOrdTopologico();
    } else 
        cout << "Sono presenti cicli" << endl;
}

template <typename T>
void Grafo<T>::printOrdTopologico() {
    while(!L.empty()) {
        cout << *L.top() << " -->  ";
        L.pop();
    }
    cout << "NULL";
}

#endif //GRAFO_H