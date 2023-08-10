/**
 * Progettare ed implementare una classe Priority-queue che implementi le seguenti operazioni
        • Insert(S,x)
        • Minimum(S) 
        • Extract-Min(S)
        • Decrease-priority(S,x,k).
*/

#include <iostream>
#include <vector>

#include "minHeap.h"
#include "minPriorityQueue.h"

using namespace std;

int main() {

    MinPriorityQueue<int> priorityQueue;

    priorityQueue.queueInsert(15);
    priorityQueue.queueInsert(10);
    priorityQueue.queueInsert(25);
    priorityQueue.queueInsert(5);
    priorityQueue.queueInsert(30);
    priorityQueue.queueInsert(17);
    priorityQueue.queueInsert(22);

    priorityQueue.printingTree();
    priorityQueue.printingAsciiTree();

    cout << "\nMinimum element: " << priorityQueue.queueMinimum();

    priorityQueue.queueDecreaseKey(2, 6);
    cout << "\nAfter decreasing key at index 2 to 6:";
    priorityQueue.printingTree();
    priorityQueue.printingAsciiTree();

    //int extractedMax = priorityQueue.queueExtractMax();
    cout << "\nExtracted min element: " << priorityQueue.queueExtractMin() << endl;
    cout << "\nHeap after extraction:";
    priorityQueue.printingTree();
    priorityQueue.printingAsciiTree();

    return 0;
}