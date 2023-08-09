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

    MinPriorityQueue<int> myMinQueue;

    myMinQueue.queueInsert(100);
    myMinQueue.queueInsert(200);
    myMinQueue.queueInsert(20);
    myMinQueue.queueInsert(420);
    myMinQueue.queueInsert(80);
    myMinQueue.queueInsert(820);
    myMinQueue.queueInsert(1020);
    myMinQueue.queueInsert(600);

    myMinQueue.printTree();
    myMinQueue.printAsciiTree();

    cout << "Maximum : " << myMinQueue.queueMinimum() << endl;

    cout << "Extract Min : " << myMinQueue.queueExtractMin() << endl;

    myMinQueue.queueDecreaseKey(2, 20);

    myMinQueue.printTree();
    myMinQueue.printAsciiTree();

    return 0;
}