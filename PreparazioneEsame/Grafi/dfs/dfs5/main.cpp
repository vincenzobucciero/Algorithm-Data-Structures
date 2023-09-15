#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <string>

#include "vertice.h"
#include "nodo.h"
#include "grafo.h"

using namespace std;

int main() {
    Grafo<int> myGrafo;

    ifstream file;
    string myFileInput = "fileInput.txt";
    ofstream output;
    string myFileOutput = "fileOutput.txt";

    string line;

    int i = 0, numVertici = 0, numArchi = 0, vertice, arco;

    file.open(myFileInput);
    output.open(myFileOutput);

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

            if(myGrafo.searchIndirizzo(v1) == -1)
                myGrafo.addNodo(v1);
            if(myGrafo.searchIndirizzo(v2) == -1)
                myGrafo.addNodo(v2);
            myGrafo.addArco(myGrafo.getIndirizzoVertice(vertice), myGrafo.getIndirizzoVertice(arco));
        }
    }

    file.close();

    cout << "grafo SENZA DFS:" << endl;
    cout << myGrafo << endl;
    myGrafo.dfs();
    cout << "grafo CON DFS:" << endl;
    cout << myGrafo << endl;

    auto u = myGrafo.getQueue();

    while(!u.empty()) {
        output << u.front() << endl;
        u.pop();
    }

    output.close();

    return 0;
}