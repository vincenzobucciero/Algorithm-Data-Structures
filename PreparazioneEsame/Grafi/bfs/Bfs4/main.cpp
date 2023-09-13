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
  string myFileInput = "fileInput.txt";
  file.open(myFileInput);

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

      if(grafo.searchIndirizzo(v1) == -1)
        grafo.addNodo(v1);
      if(grafo.searchIndirizzo(v2) == -1)
        grafo.addNodo(v2);
      grafo.addArco(grafo.getIndirizzoVertice(vertice), grafo.getIndirizzoVertice(arco));
    }
  }

  file.close();

  cout << "Grafo PRE-BFS" << endl;
  cout << grafo << endl;
  cout << "Grafo POST-BFS" << endl;
  grafo.bfs(grafo.getIndirizzoVertice(verticeSorgente));
  cout << grafo << endl;

  return 0;
}
