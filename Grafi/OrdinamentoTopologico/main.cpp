/**
 * Implemenatre un algoritmo per effettuare l'ordinamento topologico
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>

#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Grafi/OrdinamentoTopologico/vertice.h"
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Grafi/OrdinamentoTopologico/nodo.h"
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/Grafi/OrdinamentoTopologico/grafo.h"

using namespace std;

int main() {
    Grafo<string> myGrafo;
    
    Vertice<string> shirt("shirt");
    Vertice<string> tie("tie");
    Vertice<string> jacket("jacket");
    Vertice<string> belt("belt");
    Vertice<string> pants("pants");
    Vertice<string> undershorts("undershorts");

    myGrafo.addNodo(Nodo<string>(&shirt));            
    myGrafo.addNodo(Nodo<string>(&tie));
    myGrafo.addNodo(Nodo<string>(&jacket));
    myGrafo.addNodo(Nodo<string>(&belt));            
    myGrafo.addNodo(Nodo<string>(&pants));
    myGrafo.addNodo(Nodo<string>(&undershorts));

    myGrafo.addArco(0, &tie);         
    myGrafo.addArco(0, &belt);
    myGrafo.addArco(1, &jacket);         
    myGrafo.addArco(3, &jacket);
    myGrafo.addArco(4, &belt);         
    myGrafo.addArco(5, &pants);
    
    myGrafo.ordTopologico();
}