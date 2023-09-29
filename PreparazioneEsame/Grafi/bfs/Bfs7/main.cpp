//
// Created by vincenzo on 29/09/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include "vertice.h"
#include "nodo.h"
#include "grafo.h"

using namespace std;

int main() {
    Grafo<int> myGrafo;
    ifstream input;
    input.open("fileInput.txt");
    string line;
    int i = 0, numVertici = 0, numArchi = 0, vertice, arco, verticeSorgente;

    while(getline(input, line)) {
        stringstream lineIn(line);
        if(i == 0) {
            lineIn >> numVertici;
            lineIn >> numArchi;
            i++;
        } else {
            lineIn >> vertice;
            lineIn >> arco;

            Vertice<int>* v1 = new Vertice<int>(vertice);
            Vertice<int>* v2 = new Vertice<int>(arco);

            verticeSorgente = vertice;

            if(myGrafo.searchIndirizzo(v1) == -1)
                myGrafo.addNodo(v1);
            if(myGrafo.searchIndirizzo(v2) == -1)
                myGrafo.addNodo(v2);
            myGrafo.addArco(myGrafo.getIndirizzoVertice(vertice), myGrafo.getIndirizzoVertice(arco));
        }
    }
    input.close();

    cout << "myGrafo BEFORE bfs:" << endl;
    cout << myGrafo << endl;

    myGrafo.bfs(myGrafo.getIndirizzoVertice(verticeSorgente));
    cout << "myGrafo AFTER bfs:" << endl;
    cout << myGrafo << endl;

    return 0;
}
