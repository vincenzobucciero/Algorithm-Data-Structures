/**
 * Implementazione dell'algoritmo di Kruskal (Minimum Spanning Tree)
*/

#ifndef GRAFOPESATO_H
#define GRAFOPESATO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

#include "vertice.h"
#include "nodo.h"

using namespace std;

template <typename T>
class GrafoPesato {
    private: 
        vector<Nodo<T>> grafo;

        struct ArcoPeso {
            Vertice<T>* u;
            Vertice<T>* v;
            int peso;

            ArcoPeso(Vertice<T>* u, Vertice<T>* v, int peso) : u(u), v(v), peso(peso) {  }

            bool operator<(const ArcoPeso& other) {
                return this->peso < other.peso;
            }
        };

        list<Vertice<T>*> getListaAdj(Vertice<T>* vertice) {
            for(auto i : grafo) {
                if(i.getVertice() == vertice)
                    return i.getLista();
            }
            return grafo.at(0).getLista();
        }

        void makeSet(Vertice<T>* vertice) {
            vertice->setPredecessore(vertice);
            vertice->setRank(0);
        }

        void unionA(Vertice<T>* u, Vertice<T>* v) {
            this->link(findSet(u), findSet(v));
        }

        void link(Vertice<T>* u, Vertice<T>*v) {
            if(u->getRank() > v->getRank())
                u->setPredecessore(v);
            else {
                v->setPredecessore(u);
                if(u->getRank() == v->getRank())
                    v->setRank(v->getRank() + 1);
            }
        }

        Vertice<T>* findSet(Vertice<T>* vertice) {
            if(vertice->getPredecessore() != vertice)
                vertice->setPredecessore(findSet(vertice->getPredecessore()));
            return vertice->getPredecessore();
        }

    public:
        GrafoPesato() { };

        void addNodo(Nodo<T> nodo) {
            grafo.push_back(nodo);
        }

        void addArco(int i, Vertice<T>* vertice, int peso) {
            if(i >= 0 && i < grafo.size()) {
                grafo.at(i).append(vertice, peso);
            }
        }

        void mstKruskal() {
            // Creare una coda di priorità per gli archi pesati
            priority_queue<ArcoPeso> edgeQueue;

            // Aggiungi tutti gli archi del grafo alla coda di priorità
            for (auto nodo : grafo) {
                Vertice<T>* u = nodo.getVertice();
                list<pair<Vertice<T>*, int>> adiacenti = nodo.getLista(); // Lista di coppie (vertice, peso)
                for (const auto& pair : adiacenti) {
                    Vertice<T>* v = pair.first;
                    int peso = pair.second; // Estrai il peso dall'arco
                    // Assicurati che gli archi siano aggiunti una sola volta
                    if (*u < *v) {
                        edgeQueue.push(ArcoPeso(u, v, peso));
                    }
                }
            }

            // Inizializza gli insiemi disgiunti
            for (const Nodo<T>& nodo : grafo) {
                Vertice<T>* u = nodo.getVertice();
                makeSet(u);
            }

            // Inizializza l'albero di copertura minimo
            vector<ArcoPeso> mstEdges;

            // Esegui l'algoritmo di Kruskal
            while (!edgeQueue.empty() && mstEdges.size() < grafo.size() - 1) {
                ArcoPeso edge = edgeQueue.top();
                edgeQueue.pop();
                Vertice<T>* u = edge.u;
                Vertice<T>* v = edge.v;

                // Verifica se l'aggiunta dell'arco crea un ciclo
                if (findSet(u) != findSet(v)) {
                    mstEdges.push_back(edge);
                    unionA(u, v);
                }
            }

            // Stampa gli archi dell'albero di copertura minimo
            for (const ArcoPeso& edge : mstEdges) {
                cout << "Arco: " << edge.u->getValue() << " - " << edge.v->getValue() << " Peso: " << edge.peso << endl;
            }
        }
};

#endif //GRAFOPESATO_H