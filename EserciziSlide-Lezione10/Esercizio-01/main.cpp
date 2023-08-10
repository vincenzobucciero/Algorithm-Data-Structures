/**
 *  Scrivere una procedura per convertire un min-heap in max-heap.
*/

#include <iostream>
#include <vector>

//includo la classe MaxHeap per utilizzare la buildMaxHeap e la MaxHeapify
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/EserciziSlide-Lezione10/PriorityQueue/Max-Priority-Queue/maxHeap.h"

using namespace std;

int main() {
    MaxHeap<int> heap;

    heap.insert(4);
    heap.insert(7);
    heap.insert(10);
    heap.insert(12);
    heap.insert(18);
    heap.insert(21);
    heap.insert(25);

    heap.printingTree();

    return 0;
}