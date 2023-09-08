/**
 * Progettare ed implementare una classe Priority-queue che implementi le seguenti operazioni
        • Insert(S,x)
        • Minimum(S) 
        • Extract-Min(S)
        • Decrease-priority(S,x,k).
*/

#include <iostream>
#include <vector>

#include "minHeap2.h"
#include "minPriorityQueue2.h"

using namespace std;

int main() {

    MinPriorityQueue2<int> priorityQueue;

    priorityQueue.queueInsert(15);
    priorityQueue.queueInsert(10);
    priorityQueue.queueInsert(25);
    priorityQueue.queueInsert(5);
    priorityQueue.queueInsert(30);
    priorityQueue.queueInsert(17);
    priorityQueue.queueInsert(22);

    priorityQueue.printTree();
    priorityQueue.printAsciiTree();

    cout << "\nMinimum element: " << priorityQueue.queueMinimum();

    priorityQueue.queueDecreaseKey(2, 6);
    cout << "\nAfter decreasing key at index 2 to 6:";
    priorityQueue.printTree();
    priorityQueue.printAsciiTree();

    //int extractedMax = priorityQueue.queueExtractMax();
    cout << "\nExtracted min element: " << priorityQueue.queueExtractMin() << endl;
    cout << "\nHeap after extraction:";
    priorityQueue.printTree();
    priorityQueue.printAsciiTree();

    return 0;
}