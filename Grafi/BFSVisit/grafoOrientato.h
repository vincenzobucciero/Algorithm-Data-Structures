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

//RAPPRESENTAZIONE DI UN GRAFO ORIENTATO MEDIANTE LISTA DI ADIACENZE


template <typename T>
class GrafoOrientato {
    private:
        vector<Nodo<T>> grafo;      //grafo rappresentato tramite una serie di nodi

        /**
         * Utilizzata per ottenere la lista di adiacenza di un vertice specifico in un grafo orientato
         * @param vertice puntatore ad un oggetto di tipo Vertice<T>, cioè il vertice di cui si vuole ottenere la lista di adiacenza
         * @return lista di adiacenza del vertice specificato in input
        */
        list<Vertice<T>* > getListaAdj(Vertice<T>* vertice);

    public:

        /**
         * Costruttore vuoto perchè si poi utilizzano metodi come addNodo e addArco per costruire il grafo passo dopo passo.
         * @see addNodo
         * @see addArco
        */
        GrafoOrientato() {  }

        /**
         * Aggiunge un nuovo nodo al grafo
         * @param nodo il nodo da aggiungere al grafo
        */
        void addNodo(Nodo<T> nodo);

        /**
         * Utilizzata per aggiungere un nuovo arco al grafo tra un nodo esistente e un vertice specificato
         * @param i indice del nodo a cui si vuole aggiungere l'arco
         * @param vertice il puntatore al vertice a cui si vuole aggiungere l'arco
        */
        void addArco(int i, Vertice<T>* vertice);

        /**
         * Implementazione della visita in ampiezza BFS con approccio iterativo in un grafo
         * @param vertice vertice(sorgente) specificato di partenza per la BFS
        */
        void BFS(Vertice<T>* vertice);

        /**
         * Implementazione della visita in ampiezza BFS con approccio ricorsico in un grafo
         * @param queue coda di verticida cui inizia la visita BFS
        */
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
    grafo.at(i).append(vertice);    //si recupera il nodo con indice i nel vettore grafo

    //In pratico l'arco viene aggiunto aggiungendo il vertice alla lista di adiacenza del nodo corrispondente
}

template <typename T>
list<Vertice<T>* > GrafoOrientato<T>::getListaAdj(Vertice<T>* vertice) {
    for(auto i : grafo) {       //si scorre il vettore grafo che contiene tutti i nodi
        if(i.getVertice() == vertice)   //se il vertice associato al nodo corrente è == al vertice in input
            return i.getList();     //return lista di adiacenza di quel nodo
    }

    //se il vertice in input non corrisponde a nessun vertice del grafo
    return grafo.at(0).getList();   //return la lista di adiacenza del primo vertice del grafo
}

template <typename T>
void GrafoOrientato<T>::BFS(Vertice<T>* sorgente) {
    //Inizializzazione
    for(auto u : grafo)     //per tutti i nodi del grafo
    {
        u.getVertice()->setColore(Color::WHITE);    //colore bianco
        u.getVertice()->setPredecessore(nullptr);   //predecessore nullo
        u.getVertice()->setDistanza(UINT16_MAX);    //distanza infinita(max) dalla sorgente
    }

    sorgente->setColore(Color::GRAY);   //colore sorgente grigio
    sorgente->setDistanza(0);   //distanza sorgente da se stessa 0
    sorgente->setPredecessore(nullptr);     //predecessore sorgente punta a nullptr
    
    queue<Vertice<T>* > q;        //Utilizza una coda q per mantenere i vertici da visitare durante la BFS

    //Inseriamo nella coda FIFO
    q.push(sorgente);       //ENQUEUE della sorgente nella coda
    
    while(!q.empty())   //Finche la coda non è vuota
    {
        auto u = q.front();  //Viene utilizzato front per recuperare il primo elemento di una coda
        q.pop();    //viene estratto

        //Creo la lista di adiacenza
        list<Vertice<T>* > adj = getListaAdj(u);

        for(auto v : adj)   //per ogni vertice nella lista di adiacenza di u
        {
            if(v->getColore() == Color::WHITE)      //se il vertice non è ancora stato visitato
            {
                v->setColore(Color::GRAY);      //il suo colore diventa grigio
                v->setPredecessore(u);      //il predecessore viene impostato al vertice corrente
                v->setDistanza(u->getDistanza() + 1);   //distanza incrementata di 1 rispetto al vertice corrente
                q.push(v);      //il vertice adiacente viene inserito in coda per essere successivamente visitato
            }
        }
        u->setColore(Color::BLACK);         //dopo che tutti i vertici adiacenti sono stati visitati, u diventa nero
                                            //per contrassegnare che è stato completamente visitato
    }
}

template <typename T> 
void GrafoOrientato<T>::BFSRecursive(queue<Vertice<T>* > queue) {
    static bool isFirst = true;     //static per assicurarsi che l'inizializzazione dei vertici nel grafo venga eseguita solo una volta durante l'intero processo di esecuzione.

    if (isFirst)    //se verificata
    {
        //Inizializzazione
        for (auto u : grafo)    //per tutti i vertici del grafo
        {       
            u.getVertice()->setColore(Color::WHITE);        //colore bianco
            u.getVertice()->setPredecessore(nullptr);       //predecessore nullo
            u.getVertice()->setDistanza(UINT16_MAX);        //distanza max(infinita)
        }

        isFirst = false;    
    }

    if(!queue.empty())      //finchè la coda non è vuota
    {
        auto u = queue.front();         //Viene utilizzato front per recuperare il primo elemento di una coda
        queue.pop();        //viene stratto

        list<Vertice<T>*> adj = getListaAdj(u);     //creo la lista di adiacenze di u

        for (auto v : adj)      //per ogni nodo nella lista di adiacenze
        {
            if(v->getColore() == Color::WHITE)      //se il vertice ancora non è stato esplorato
            {
                v->setColore(Color::GRAY);      //diventa grigio
                v->setPredecessore(u);          //il predecessore viene impostato al vertice corrente   
                v->setDistanza(u->getDistanza() + 1);    //distanza incrementata di 1 rispetto al vertice corrente   
                queue.push(v);      //il vertice adiacente viene inserito in coda per essere successivamente visitato
            }
        }
        u->setColore(Color::BLACK);  //Finita la visita lo settiamo di colore Nero
        BFSRecursive(queue);    //ricorsione, si passa la coda aggiornata
    }
}

#endif