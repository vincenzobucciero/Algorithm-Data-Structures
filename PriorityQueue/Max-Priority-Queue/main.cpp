/**
 * Progettare ed implementare una classe Priority-queue che implementi le seguenti operazioni
        • Insert(S,x)
        • Maximum(S) 
        • Extract-Max(S)
        • Increase-priority(S,x,k).
*/

#include <iostream>
#include <vector>
#include "maxHeap.h"
#include "maxPriorityQueue.h"

using namespace std;

int main() {
    MaxPriorityQueue<int> myMaxQueue;

    myMaxQueue.queueInsert(100);
    myMaxQueue.queueInsert(200);
    myMaxQueue.queueInsert(20);
    myMaxQueue.queueInsert(420);
    myMaxQueue.queueInsert(80);
    myMaxQueue.queueInsert(820);
    myMaxQueue.queueInsert(1020);
    myMaxQueue.queueInsert(600);

    myMaxQueue.printingTree();
    myMaxQueue.printingAsciiTree();

    cout << "Maximum : " << myMaxQueue.queueMaximum() << endl;

    cout << "Extract Max : " << myMaxQueue.queueExtractMax() << endl;

    myMaxQueue.queueIncreasePriority(2, 20);

    myMaxQueue.printingTree();
    myMaxQueue.printingAsciiTree();

    return 0;
}

