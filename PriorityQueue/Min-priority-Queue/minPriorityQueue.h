/**
 * Progettare ed implementare una classe Priority-queue che implementi le seguenti operazioni
        • Insert(S,x)
        • Minimum(S) 
        • Extract-Min(S)
        • Decrease-priority(S,x,k).
*/

#include <iostream>
#include <vector>
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/PriorityQueue/Min-priority-Queue/minHeap.h"

using namespace std;

template <typename T>
class MinPriorityQueue : private MinHeap<T> {
    public:
        MinPriorityQueue(vector<T>* tree) : MinHeap<T>(tree) {  }
        MinPriorityQueue() {  }
        ~MinPriorityQueue() {  }

        T queueMinimum();
        T queueExtractMin();

        void queueInsert(T x);
        void queueDecreaseKey(int i, T key);
        void printingTree();
        void printingAsciiTree();
};

template <typename T>
void MinPriorityQueue<T>::queueInsert(T x) {
    this->insert(x);
}

template <typename T>
T MinPriorityQueue<T>::queueMinimum() {
    return this->getRoot();
}

template <typename T>
T MinPriorityQueue<T>::queueExtractMin() {
    if(this->getHeapSize() == 0)
        return false;
    T min = this->getRoot();
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->minHeapify(0);

    return min;
}

template <typename T>
void MinPriorityQueue<T>::queueDecreaseKey(int i, T key) {
    if(key > this->getTree()->at(i))
        return;

    this->setTree(i, key);

    while(i > 0 && this->getTree()->at(this->parent(i)) > this->getTree()->at(i)) {
        this->swap(this->getTree()->at(i), this->getTree()->at(this->parent(i)));
        i = this->parent(i);
    }
}

template <typename T>
void MinPriorityQueue<T>::printingTree(){
    cout << endl << "***Min Heap***" << endl;
    for (int i=0; i<this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << " ";
}

template <typename T>
void MinPriorityQueue<T>::printingAsciiTree(){
    cout << endl << "***Min Ascii Heap***" << endl;
    this->inOrderAscii(0,0);
}