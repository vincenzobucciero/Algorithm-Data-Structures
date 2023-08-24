/**
 * Implementazione della visita in Ampiezza (BFS) di un Grafo Orientato
*/

#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include <iostream>
#include <limits>
#include <queue>
#include <list>
#include <stack>

#include "vertice.h"
#include "nodo.h"

using namespace std;

template <typename T>
class GrafoOrientato {
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>* > getListaAdj(Vertice<T>* vertice);

    public:
        GrafoOrientato() {  }

        void addNodo(Nodo<T> nodo);
        void addArco(int i, Vertice<T>* vertice);
        void BFS(Vertice<T>* vertice);
        void BFSRecursive(queue<Vertice<T>* >);

        friend ostream &operator<<(ostream& out, GrafoOrientato<T>& obj) {
            for(auto i : obj.grafo) 
                out << i << endl;

            return out;
        }
};

template <typename T>
void GrafoOrientato<T>::addNodo(Nodo<T> nodo) {
    this->grafo.push_back(nodo);   // aggiunge il nuovo Nodo al vettore del Grafo
}

template <typename T>
void GrafoOrientato<T>::addArco(int i, Vertice<T>* vertice) {
    grafo.at(i).append(vertice);
}

template <typename T>
list<Vertice<T>* > GrafoOrientato<T>::getListaAdj(Vertice<T>* vertice) {
    for(auto i : grafo) {
        if(i.getVertice() == vertice)
            return i.getList();
    }

    return grafo.at(0).getList();
}

template <typename T>
void GrafoOrientato<T>::BFS(Vertice<T>* sorgente) {
    //Inizializzazione
    for(auto u : grafo)
    {
        u.getVertice()->setColore(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }

    sorgente->setColore(Color::GRAY);
    sorgente->setDistanza(0);
    sorgente->setPredecessore(nullptr);
    queue<Vertice<T>* > q;

    //Inseriamo nella coda FIFO
    q.push(sorgente);       //ENQUEUE
    
    while(!q.empty())   //Finche la coda non è vuota
    {
        auto u = q.front();  //Viene utilizzato front per recuperare il primo elemento di una coda
        q.pop();

        //Creo la lista di adiacenza
        list<Vertice<T>* > adj = getListaAdj(u);

        for(auto v : adj)
        {
            if(v->getColore() == Color::WHITE)
            {
                v->setColore(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza() + 1);
                q.push(v);
            }
        }
        u->setColore(Color::BLACK);
    }
}

template <typename T> 
void GrafoOrientato<T>::BFSRecursive(queue<Vertice<T>* > queue) {
    static bool isFirst = true;

    if (isFirst)
    {
        //Inizializzazione
        for (auto u : grafo)
        {
            u.getVertice()->setColore(Color::WHITE);
            u.getVertice()->setPredecessore(nullptr);
            u.getVertice()->setDistanza(UINT16_MAX);
        }

        isFirst = false;
    }

    if(!queue.empty())
    {
        auto u = queue.front();
        queue.pop();

        list<Vertice<T>*> adj = getListaAdj(u);

        for (auto v : adj)
        {
            if(v->getColore() == Color::WHITE)
            {
                v->setColore(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza() + 1);
                queue.push(v);
            }
        }
        u->setColore(Color::BLACK);  //Finita la visita lo settiamo di colore Nero
        BFSRecursive(queue);
    }
}

#endif