/**
 * Implementazione della visità in profondità DFS in un grafo orientato
*/

#include "nodo.h"
#include "vertice.h"
#include "grafoOrientato.h"

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    GrafoOrientato<string> grafo;

    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");
    Vertice<string> f("F");

    grafo.addNodo(Nodo<string>(&a));
    grafo.addNodo(Nodo<string>(&b));
    grafo.addNodo(Nodo<string>(&c));
    grafo.addNodo(Nodo<string>(&d));
    grafo.addNodo(Nodo<string>(&e));
    grafo.addNodo(Nodo<string>(&f));

    grafo.addArco(0, &b);
    grafo.addArco(0, &e);
    grafo.addArco(1, &c);
    grafo.addArco(2, &d),
    grafo.addArco(2, &e);
    grafo.addArco(4, &f);

    cout << "VISITA DFS:" << endl;
    grafo.DFS();

}