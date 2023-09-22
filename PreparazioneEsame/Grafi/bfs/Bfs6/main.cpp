//
// Created by vincenzo on 22/09/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>

#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/Grafi/bfs/Bfs6/vertice.h"
#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/Grafi/bfs/Bfs6/nodo.h"
#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/Grafi/bfs/Bfs6/grafo.h"

using namespace std;

int main () {
    Grafo<int> myGrafo;
    ifstream file;
    file.open("fileInput.txt");
    string line;
    int i = 0, numVertici = 0, numArchi = 0, vertice, arco, verticeSorgente;

    while(getline(file, line)) {
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
    file.close();

    cout << "Grafo PRE-BFS" << endl;
    cout << myGrafo << endl;
    cout << "Grafo POST-BFS" << endl;
    myGrafo.bfs(myGrafo.getIndirizzoVertice(verticeSorgente));
    cout << myGrafo << endl;

    return 0;
}