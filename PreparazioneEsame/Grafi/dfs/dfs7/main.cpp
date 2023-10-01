//
// Created by vincenzo on 01/10/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>

#include "grafo.h"

using namespace std;

int main() {
    Grafo<int> myGrafo;

    ifstream input;
    string myFileInput = "fileInput.txt";
    ofstream output;
    string myFileOutput = "fileOutput.txt";
    input.open(myFileInput);
    output.open(myFileOutput);

    string line;
    int i = 0, numVertici = 0, numArchi = 0, vertice, arco;

    while(getline(input, line)) {
        stringstream lineIn(line);
        if(i == 0) {
            lineIn >> numVertici;
            lineIn >> numArchi;
            i++;
        } else {
            lineIn >> vertice;
            lineIn >> arco;

            auto* v1 = new Vertice<int>(vertice);
            auto* v2 = new Vertice<int>(arco);

            if(myGrafo.searchIndirizzo(v1) == -1)
                myGrafo.addNodo(v1);
            if(myGrafo.searchIndirizzo(v2) == -1)
                myGrafo.addNodo(v2);
            myGrafo.addArco(myGrafo.getIndirizzoVertice(vertice), myGrafo.getIndirizzoVertice(arco));
        }
    }

    input.close();

    cout << "Grafo BEFORE DFS:" << endl;
    cout << myGrafo << endl;
    myGrafo.dfs();
    cout << "Grafo AFTER DFS:" << endl;
    cout << myGrafo << endl;

    auto u = myGrafo.getMyQueue();

    while(!u.empty()) {
        output << u.front() << endl;
        u.pop();
    }

    output.close();

    return 0;
}
