#include <iostream>
#include <vector>
#include "maxHeap2.h"
#include "maxPriorityQueue2.h"

using namespace std;

int main() {
    MaxPriorityQueue2<int> myQueue;

    myQueue.queueInsert(15);
    myQueue.queueInsert(10);
    myQueue.queueInsert(25);
    myQueue.queueInsert(5);
    myQueue.queueInsert(30);

    myQueue.printTree();
    myQueue.printAsciiTree();

    cout << "\nMaximum element: " << myQueue.queueMaximum();

    myQueue.queueIncreasePriority(2, 40);
    cout << "\nAfter increasing key at index 2 to 40:";
    myQueue.printTree();
    myQueue.printAsciiTree();

    //int extractedMax = myQueue.queueExtractMax();
    cout << "\nExtracted max element: " << myQueue.queueExtractMax() << endl;
    cout << "\nHeap after extraction:";
    myQueue.printTree();
    myQueue.printAsciiTree();


    return 0;
}