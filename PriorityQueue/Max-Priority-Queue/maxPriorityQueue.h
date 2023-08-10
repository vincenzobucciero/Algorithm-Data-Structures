/**
 * Progettare ed implementare una classe Priority-queue che implementi le seguenti operazioni
        • Insert(S,x)
        • Maximum(S) 
        • Extract-Max(S)
        • Increase-priority(S,x,k).
*/

#include <iostream>
#include <vector>
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/PriorityQueue/Max-Priority-Queue/maxHeap.h"

using namespace std;

template <typename T>
class MaxPriorityQueue : private MaxHeap<T> {
    public:
        MaxPriorityQueue(vector<T>* tree);
        MaxPriorityQueue();
        ~MaxPriorityQueue();

        T queueMaximum();
        T queueExtractMax();

        void queueInsert(T x);
        void queueIncreasePriority(int i, T key);
        void printingTree();
        void printingAsciiTree();
};

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(vector<T>* tree) : MaxHeap<T>(tree) { }

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue() { }

template <typename T>
MaxPriorityQueue<T>::~MaxPriorityQueue() { }

template <typename T>
T MaxPriorityQueue<T>::queueMaximum() {
    return this->getRoot();
}

template <typename T>
T MaxPriorityQueue<T>::queueExtractMax() {
    if(this->getHeapSize() == 0)
        return false;

    T max = this->getRoot();
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->maxHeapify(0);

    return max;
}

template <typename T>
void MaxPriorityQueue<T>::queueInsert(T x) {
    this->insert(x);
}

template <typename T>
void MaxPriorityQueue<T>::queueIncreasePriority(int i, T key) {
    if(key < this->getTree()->at(i))
        return;
    
    this->setTree(i, key);

    while(i > 0 && this->getTree()->at(this->parent(i)) < this->getTree()->at(i)) {
        this->swap(this->getTree()->at(i), this->getTree()->at(this->parent(i)));
        i = this->parent(i);
    }
}


template <typename T>
void MaxPriorityQueue<T>::printingTree() {
    cout << "\nPrinting Max Heap Tree:" << endl;
    for(int i = 0; i < this->getHeapSize(); i++) {
        cout << this->getTree()->at(i) << " ";
    }
}


template <typename T>
void MaxPriorityQueue<T>::printingAsciiTree() {
    cout << "\nPrinting Ascii Max Heap Tree: " << endl;
    this->inOrderAscii(0, 0);
}


