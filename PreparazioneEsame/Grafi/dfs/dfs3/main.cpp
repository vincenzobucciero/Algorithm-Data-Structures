#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>

#include "vertice.h"
#include "nodo.h"
#include "grafo.h"

using namespace std;

int main() {
    Grafo<int> grafo;

    ifstream file;
    string myInputFile = "fileInput.txt";
    ofstream output;
    string myOutputFile = "fileOutput.txt";

    string line;

    int i = 0;
    int num_vertici = 0, num_archi = 0, vertice, arco;

    file.open(myInputFile);
    output.open(myOutputFile);

    while(getline(file, line)) {
        stringstream lineIn(line);
        if(i == 0) {
            lineIn >> num_vertici;
            lineIn >> num_archi;
            i++;
        } else {
            lineIn >> vertice;
            lineIn >> arco;

            Vertice<int>* v1 = new Vertice<int>(vertice);
            Vertice<int>* v2 = new Vertice<int>(arco);

            if(grafo.searchIndirizzo(v1) == -1)
                grafo.addNodo(v1);
            if(grafo.searchIndirizzo(v2) == -1)
                grafo.addNodo(v2);

            grafo.addArco(grafo.getIndirizzoVertice(vertice), grafo.getIndirizzoVertice(arco));
        }
    }

    file.close();

    cout << "Grafo PRE-DFS:" << endl;
    cout << grafo << endl;
    cout << "Grafo POST-DFS:" << endl;
    grafo.dfs();
    cout << grafo << endl;

    //scrittura su file di output

    auto u = grafo.getQueue();

    while(!u.empty()) {
        output << u.front() << endl;
        u.pop();
    }

    output.close();

    return 0;
}
