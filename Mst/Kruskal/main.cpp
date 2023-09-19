/**
 * Implementazione dell'algoritmo di Kruskal (Minimum Spanning Tree)
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Mst/Kruskal/vertice.h"
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Mst/Kruskal/nodo.h"
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Mst/Kruskal/grafoPesato.h"

using namespace std;

int main() {
    // Creazione del grafo pesato
    GrafoPesato<int> grafo;

    // Creazione dei vertici
    Vertice<int> A(1);
    Vertice<int> B(2);
    Vertice<int> C(3);
    Vertice<int> D(4);
    Vertice<int> E(5);

    // Creazione dei nodi
    Nodo<int> nodoA(&A);
    Nodo<int> nodoB(&B);
    Nodo<int> nodoC(&C);
    Nodo<int> nodoD(&D);
    Nodo<int> nodoE(&E);

    grafo.addNodo(nodoA);
    grafo.addNodo(nodoB);
    grafo.addNodo(nodoC);
    grafo.addNodo(nodoD);
    grafo.addNodo(nodoE);

    // Aggiunta degli archi con i pesi
    grafo.addArco(0, &B, 2);
    grafo.addArco(0, &D, 3);
    grafo.addArco(1, &C, 1);
    grafo.addArco(1, &D, 4);
    grafo.addArco(2, &E, 5);
    grafo.addArco(3, &E, 6);

    // Trova e stampa l'albero di copertura minimo
    grafo.mstKruskal();

    return 0;
}
