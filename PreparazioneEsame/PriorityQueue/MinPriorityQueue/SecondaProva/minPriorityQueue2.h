#ifndef MINPRIORITYQUEUE2_H
#define MINPRIORITYQUEUE2_H

#include <iostream>
#include <vector>

#include "minHeap2.h"

using namespace std;

template <typename T>
class MinPriorityQueue2 : private MinHeap2<T> {
    public:
        MinPriorityQueue2(vector<T>* tree) : MinHeap2<T>(tree) {  }
        MinPriorityQueue2() {  }
        ~MinPriorityQueue2() {  }
        T queueMinimum();
        T queueExtractMin();
        void queueInsert(T x);
        void queueDecreaseKey(int i, T key);
        void printTree();
        void printAsciiTree();
};

template <typename T>
T MinPriorityQueue2<T>::queueMinimum() {
    return this->getRoot();
}

template <typename T>
T MinPriorityQueue2<T>::queueExtractMin() {
    if(this->getHeapSize() == 0)
        return false;
    T min = this->getRoot();
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->minHeapify(0);

    return min;
}

template <typename T>
void MinPriorityQueue2<T>::queueInsert(T x) {
    this->insert(x);
}

template <typename T>
void MinPriorityQueue2<T>::queueDecreaseKey(int i, T key) {
    if(key > this->getTree()->at(i))
        return;
    this->setTree(i, key);
    while(i > 0 && this->getTree()->at(this->parent(i)) > this->getTree()->at(i)) {
        this->swap(this->getTree()->at(i), this->getTree()->at(this->parent(i)));
        i = this->parent(i);
    }
}

template <typename T>
void MinPriorityQueue2<T>::printTree() {
    cout << "Print MinHeap Tree:" << endl;
    for(int i = 0; i < this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << "  ";
}

template <typename T>
void MinPriorityQueue2<T>::printAsciiTree() {
    cout << "Print MinHeap Ascii Tree:" << endl;
    this->inOrderAscii(0, 0);
}


#endif //MINPRIORITYQUEUE2_H