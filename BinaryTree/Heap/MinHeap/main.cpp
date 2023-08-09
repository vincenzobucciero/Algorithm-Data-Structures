/**
 * Progettare ed implementare una classe template Min-Heap dotata delle seguenti operazioni
    • Min-Heapify
    • Build-Min-Heap
    • Insert
    • PrintArray
    • (PrintAsciiTree)
*/

#include <iostream>
#include <vector>

#include "minHeap.h"

using namespace std;

int main() {
    MinHeap<int> myTree;

    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(3);
    myTree.insert(4);
    myTree.insert(5);
    myTree.insert(6);
    myTree.insert(7);

    myTree.printTree();
    myTree.printAsciiTree();

    myTree.heapSort();
    myTree.printVector();
}