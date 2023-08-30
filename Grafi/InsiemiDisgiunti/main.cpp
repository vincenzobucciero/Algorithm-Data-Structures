/**
 * • Implementare una struttura per insiemi disgiunti
 * • Implementare l'algoritmo per trovare le componenti connesse
*/

#include <iostream>

#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/InsiemiDisgiunti/vertice.h"
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/InsiemiDisgiunti/nodo.h"
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/InsiemiDisgiunti/grafoNonOrientato.h"

using namespace std;

int main() {
    GrafoNonOrientato<string> myGrafo;

    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");
    Vertice<string> f("F");
    Vertice<string> g("G");

    myGrafo.addNodo(Nodo<string>(&a));
    myGrafo.addNodo(Nodo<string>(&b));
    myGrafo.addNodo(Nodo<string>(&c));
    myGrafo.addNodo(Nodo<string>(&d));
    myGrafo.addNodo(Nodo<string>(&e));
    myGrafo.addNodo(Nodo<string>(&f));
    myGrafo.addNodo(Nodo<string>(&g));

    myGrafo.addArco(0, &b);
    myGrafo.addArco(0, &c);
    myGrafo.addArco(1, &e);
    myGrafo.addArco(2, &d);
    myGrafo.addArco(2, &f);
    myGrafo.addArco(4, &g);

    myGrafo.dfs();

    myGrafo.connectedComponent();
    myGrafo.connectedComponentView();

    return 0;
}