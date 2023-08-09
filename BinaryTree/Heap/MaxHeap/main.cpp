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
    MaxHeap<int> myTree;

    myTree.insert(1998);
    myTree.insert(1);
    myTree.insert(10);
    myTree.insert(190);
    myTree.insert(2);
    myTree.insert(20);
    myTree.insert(100);

    myTree.print();
    myTree.printAsciiTree();

    myTree.heapSort();
    myTree.printVector();
    
    return 0;
}

