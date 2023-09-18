/**
 * Progettare ed implementare una classe Priority-queue che implementi le seguenti operazioni
        • Insert(S,x)
        • Maximum(S) 
        • Extract-Max(S)
        • Increase-priority(S,x,k).
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "maxHeap.h"
#include "maxPriorityQueue.h"

using namespace std;

int main() {
    MaxPriorityQueue<int> priorityQueue;

    /*
    priorityQueue.queueInsert(15);
    priorityQueue.queueInsert(10);
    priorityQueue.queueInsert(25);
    priorityQueue.queueInsert(5);
    priorityQueue.queueInsert(30);

    priorityQueue.printingTree();
    priorityQueue.printingAsciiTree();

    cout << "\nMaximum element: " << priorityQueue.queueMaximum();

    priorityQueue.queueIncreasePriority(2, 40);
    cout << "\nAfter increasing key at index 2 to 40:";
    priorityQueue.printingTree();
    priorityQueue.printingAsciiTree();

    //int extractedMax = priorityQueue.queueExtractMax();
    cout << "\nExtracted max element: " << priorityQueue.queueExtractMax() << endl;
    cout << "\nHeap after extraction:";
    priorityQueue.printingTree();
    priorityQueue.printingAsciiTree();
    */

    ifstream file("fileInput.txt");

    //controllo apertura file
    if(!file) {
        cerr << "Impossibile aprire file!!" << endl;
        return -1;
    }

    int num;
    while(file >> num) {
        priorityQueue.queueInsert(num);
    }
    file.close();

    priorityQueue.printingTree();
    priorityQueue.printingAsciiTree();

    cout << "\nMaximum element: " << priorityQueue.queueMaximum();

    priorityQueue.queueIncreasePriority(2, 60);
    cout << "\nAfter increasing key at index 2 to 40:";
    priorityQueue.printingTree();
    priorityQueue.printingAsciiTree();

    //int extractedMax = priorityQueue.queueExtractMax();
    cout << "\nExtracted max element: " << priorityQueue.queueExtractMax() << endl;
    cout << "\nHeap after extraction:";
    priorityQueue.printingTree();
    priorityQueue.printingAsciiTree();

    return 0;
}

