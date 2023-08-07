/**
 * Progettare ed implementare una classe template Max-Heap dotata delle seguenti operazioni
    • Max-Heapify
    • Build-Max-Heap
    • Insert
    • PrintArray
    • (PrintAsciiTree)
*/

#include <iostream>
#include "maxHeap.h"

using namespace std;

int main() {
    MaxHeap<int> maxTree;

    maxTree.insert(1998);
    maxTree.insert(1);
    maxTree.insert(10);
    maxTree.insert(190);
    maxTree.insert(2);
    maxTree.insert(20);
    maxTree.insert(100);

    maxTree.print();
    maxTree.printAsciiTree();
    
    return 0;
}

