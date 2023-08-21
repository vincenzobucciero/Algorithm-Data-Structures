/**
 * Progettare un algoritmo ricorsivo che dato un ABR sommi le k chiavi più piccole
*/

#include <iostream>

#include "abr.h"

using namespace std;

int main() {
    Abr<int> myAbr;

    myAbr.insert(10);
    myAbr.insert(24);
    myAbr.insert(12);
    myAbr.insert(102);
    myAbr.insert(66);
    myAbr.insert(2);
    myAbr.insert(2);
    myAbr.insert(20);

    myAbr.printAsciiAbr();

    int k = 90;

    Node<int>* minimo = myAbr.minimum();

    cout << "La somma delle K chiavi piu piccole è:  " << myAbr.sommaKChiaviPiccole(&myAbr, minimo, k-1);

    return 0;
}