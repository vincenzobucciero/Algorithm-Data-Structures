/**
 * Progettare ed implementare una classe che implementi un heap k-nario (ogni nodo ha k figli)
*/

#include <iostream>
#include <vector>

#include "kHeap.h"

using namespace std;

int main() {
    srand(1);
    srand((unsigned)time(0));

    KHeap<int> myTree(new vector<int>, 4);

    for (int i=0; i<20; i++)
        myTree.insert(rand()%10);
    myTree.print();

    return 0;
}