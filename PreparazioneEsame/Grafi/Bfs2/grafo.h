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

        queue<T> myQueue;
    public:
        Grafo() {  }

        queue<T> getMyQueue() { return this->myQueue; }
        int searchVertice(Vertice<T>* vertice);
        Vertice<T>* getIndirizzoVertice(T value);

        void addNodo(Nodo<T> nodo);
        void addArco(Vertice<T>* v1, Vertice<T>* v2);

        void bfs(Vertice<T>* vertice);

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
void Grafo<T>::addNodo(Nodo<T> nodo) {
    grafo.push_back(nodo);
}

template <typename T>
int Grafo<T>::searchVertice(Vertice<T>* vertice) {
    for(int i = 0; i < grafo.size(); i++) {
        if(this->grafo.at(i).getVertice()->getValue() == vertice->getValue())
            return i;
    }

    return -1;
}

template <typename T>
Vertice<T>* Grafo<T>::getIndirizzoVertice(T value) {
    for(auto nodo : grafo) {
        if(nodo.getVertice()->getValue() == value)
            return nodo.getVertice();
    }
    return nullptr;
}

template <typename T>
void Grafo<T>::addArco(Vertice<T>* v1, Vertice<T>* v2) {
    int indice = searchVertice(v1);
    grafo.at(indice).append(v2);
}

template <typename T>
void Grafo<T>::bfs(Vertice<T>* sorgente) {
    ofstream output;
    output.open("output.txt");

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
        output << u->getValue() << endl;
    }
    /*Dato che la BFS non riesce per forza a visitare tutti i nodi 
    ci stampiamo anche quali sono i vertici non raggiungibili nella visita. */

    cout <<endl<< "-Questi sono i Vertici NON raggiungibili: " <<endl;
    for(auto i:grafo)
    {
        if(i.getVertice()->getDistanza() == UINT16_MAX)
        cout<< *(i.getVertice())<<endl;
    }
    output.close();
}

#endif //GRAFO_H