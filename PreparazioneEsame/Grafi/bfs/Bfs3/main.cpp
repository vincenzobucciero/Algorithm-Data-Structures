#include"vertice.h"
#include"nodo.h"
#include"grafo.h"

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main() {
    Grafo<int> myGrafo;

    ifstream file;
    string myFileInput = "fileInput.txt";

    string line;

    int i = 0;
    int num_vertici = 0, num_archi = 0, vertice, arco, verticeSorgente;

    file.open(myFileInput);

    while(getline(file, line)) {
        stringstream lineIn(line);
        if(i == 0) {
            lineIn >> num_vertici;
            lineIn >> num_archi;
            i++;
        } else {
            lineIn >> vertice;
            lineIn >> arco;

            verticeSorgente = vertice;

            Vertice<int>* v1 = new Vertice<int>(vertice);
            Vertice<int>* v2 = new Vertice<int>(arco);

            if(myGrafo.searchVertice(v1) == -1)
                myGrafo.addNodo(v1);
            if(myGrafo.searchVertice(v2) == -1)
                myGrafo.addNodo(v2);

            myGrafo.addArco(myGrafo.getIndirizzoVertice(vertice), myGrafo.getIndirizzoVertice(arco));
        }
    }

    Vertice<int> *sorgente = new Vertice<int>(verticeSorgente);

    file.close();

    cout << "Grafo prima di BFS" << endl;
    cout << myGrafo << endl;    
    //Applico la BFS
    cout << "Grafo con BFS:" << endl;
    myGrafo.bfs(sorgente);
    cout << myGrafo << endl;

    return 0;
    
}
