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

    ifstream file; //creo file in lettura
    string myFile = "fileprova.txt";
    string line; //per la funzione getline()

    int vertice, arco, valoreSorgente;
    int i = 0;
    int num_vertice = 0;
    int num_arco = 0;

    //apri file
    file.open(myFile);

    while(getline(file, line)) {
        stringstream lineIn(line);

        if(i == 0) {
            lineIn >> num_vertice;
            lineIn >> num_arco;
            i++;
        } else {
            lineIn >> vertice;
            lineIn >> arco;

            Vertice<int>* v1 = new Vertice<int>(vertice);
            Vertice<int>* v2 = new Vertice<int>(arco);

            valoreSorgente = vertice;

            if(myGrafo.searchVertice(v1) == -1)
                myGrafo.addNodo(v1);
            if(myGrafo.searchVertice(v2) == -1)
                myGrafo.addNodo(v2);

            myGrafo.addArco(myGrafo.getIndirizzoVertice(vertice), myGrafo.getIndirizzoVertice(arco));
        }
    }

    Vertice<int>* sorgente = myGrafo.getIndirizzoVertice(valoreSorgente);

    file.close();

    cout<<"Grafo prima di BFS"<<endl;
    cout << myGrafo << endl;    
    //Applico la BFS
    cout<<"Grafo con BFS:"<<endl;
    myGrafo.bfs(sorgente);
    cout << myGrafo << endl;


    return 0;

}