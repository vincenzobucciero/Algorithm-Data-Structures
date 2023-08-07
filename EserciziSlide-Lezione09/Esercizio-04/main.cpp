/**
 * Progettare ed implementare una algoritmo ricorsivo che, dato un Min-Heap ed un valore X, calcoli la somma dei
 * valori dei nodi minori di X.
*/

#include <iostream>
#include <vector>

#include "minHeap.h"

using namespace std;

int main() {
    MinHeap<int> myTree;

    int x = 5;

    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(3);
    myTree.insert(4);
    myTree.insert(5);
    myTree.insert(6);
    myTree.insert(7);

    int sum = myTree.sumNode(0,x);

    myTree.printTree();
    myTree.printAsciiTree();

    cout << "La somma dei nodi minori di " << x << " è: [" << sum << "]." << endl;

    return 0;
}

