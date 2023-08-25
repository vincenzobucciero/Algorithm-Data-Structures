/**
 * Implementazione della visita in Ampiezza (BFS) di un Grafo Orientato
*/

#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <list>
#include "vertice.h"

using namespace std;

template <typename T>
class Nodo {
    private:
        Vertice<T>* vertice;    //puntatore a un oggetto di tipo Vertice<T> che rappresenta il vertice associato al nodo
        list<Vertice<T>* > listaAdiacenza;      //lista di puntatori a oggetti Vertice<T>, che rappresentano i vertici adiacenti a questo nodo
    
    public:

        /**
         * Inizializza un oggetto Nodo associato al vertice.
         * Crea un nodo con un vertice specifico
         * @param vertice il vertice a cui associare il nodo
        */
        Nodo(Vertice<T>* vertice);

        /**
         * Restituisce il puntatore al vertice associato al nodo
         * @return puntatore al vertice associato al nodo
        */
        Vertice<T>* getVertice() { return this->vertice; }

        /**
         * Restituisce la lista di adiacenza associata al nodo
         * @return lista di adiacenza associata al nodo
        */
        list<Vertice<T>* > getList() { return this->listaAdiacenza; }

        /**
         * Consente di aggiungere un vertice alla lista di adiacenza di un nodo
         * @param vertice il vertice da inserire nella lista di adiacenza di un nodo
        */
        void append(Vertice<T>* vertice);

        friend ostream &operator<<(ostream& out, const Nodo<T>& obj) {
            out << *obj.vertice << " --> ";
            for(auto i : obj.listaAdiacenza)
                out << *i << " --> ";
            out << "NULL";
            
            return out;
        }
};

template <typename T>
Nodo<T>::Nodo(Vertice<T>* vertice) {
    this->vertice = vertice;
}

template <typename T>
void Nodo<T>::append(Vertice<T>* vertice) {
    listaAdiacenza.push_back(vertice);
}


#endif