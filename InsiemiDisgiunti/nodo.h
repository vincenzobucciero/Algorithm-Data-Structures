/**
 * • Implementare una struttura per insiemi disgiunti
 * • Implementare l'algoritmo per trovare le componenti connesse
*/

#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <list>

#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/InsiemiDisgiunti/vertice.h"

using namespace std;

template <typename T>
class Nodo {
    private:
        Vertice<T>* vertice;
        list<Vertice<T>*> listaAdiacenza;
};

#endif //NODO_H