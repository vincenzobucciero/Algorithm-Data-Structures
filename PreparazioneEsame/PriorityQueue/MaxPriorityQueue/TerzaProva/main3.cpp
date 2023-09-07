#include "maxHeap3.h"
#include "maxPriorityQueue3.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    MaxPriorityQueue3<int> myQueue;

    myQueue.queueInsert(3);
    myQueue.queueInsert(7);
    myQueue.queueInsert(11);
    myQueue.queueInsert(8);
    myQueue.queueInsert(87);
    myQueue.queueInsert(50);

    myQueue.printTree();
    myQueue.printAsciiTree();

    cout << "Elem max:  " << myQueue.queueMaximum() << endl;

    myQueue.queueIncreaseKey(2, 33);
    cout << "\nAfter increasing key at index 2 to 51:";
    myQueue.printTree();
    myQueue.printAsciiTree();

    cout << "\nExtracted max element: " << myQueue.queueExtractMax() << endl;
    cout << "\nHeap after extraction:";
    myQueue.printTree();
    myQueue.printAsciiTree();
}