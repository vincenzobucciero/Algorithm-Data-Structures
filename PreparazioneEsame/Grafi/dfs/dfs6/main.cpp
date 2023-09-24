//
// Created by vincenzo on 24/09/23.
//

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

            Vertice<int>* v1 = new Vertice<int>(vertice);
            Vertice<int>* v2 = new Vertice<int>(arco);

            if(myGrafo.searchIndirizzo(v1) == -1)
                myGrafo.addNodo(v1);
            if(myGrafo.searchIndirizzo(v2) == -1)
                myGrafo.addNodo(v2);
            myGrafo.addArco(myGrafo.getIndirizzoVertice(vertice), myGrafo.getIndirizzoVertice(arco));
        }
    }
    input.close();

    cout <<"Grafo prima della DFSVISIT:" << endl;
    cout << myGrafo << endl;
    cout <<"Grafo dopo la DFSVISIT:" << endl;
    myGrafo.dfs();
    cout << myGrafo << endl;

    auto u = myGrafo.getQueue();
    while(!u.empty()) {
        output << u.front() << endl;
        u.pop();
    }

    output.close();

    return 0;
}