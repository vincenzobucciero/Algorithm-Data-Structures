//
// Created by vincenzo on 03/10/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_MINPRIORITYQUEUE_H
#define ALGORITHM_DATA_STRUCTURES_MINPRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <list>

#include "minHeap.h"

#define vuoto 5

using namespace std;

template <typename T>
class MinPriorityQueue : private MinHeap<T> {
public:
   explicit MinPriorityQueue(vector<T>* tree) : MinHeap<T>(tree) {  }
   MinPriorityQueue() = default;
   ~MinPriorityQueue() = default;

   T queueMinimum();
   T queueExtractMin();

   void queueInsert(T x);
   void queueDecreakeKey(int i, T key);

   void printTree();
   void printAsciiTree();
};

template <typename T>
T MinPriorityQueue<T>::queueMinimum() {
    return reinterpret_cast<int>(this->getRoot());
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
void MinPriorityQueue<T>::queueInsert(T x) {
    this->insert(x);
}

template <typename T>
void MinPriorityQueue<T>::queueDecreakeKey(int i, T key) {
    if(key > this->getTree()->at(i))
        return;
    this->setTree(i, key);
    while(i > 0 && this->getTree()->at(this->parent(i)) > this->getTree()->at(i)) {
        this->swap(this->getTree()->at(i), this->getTree()->at(this->parent(i)));
        i = this->parent(i);
    }
}

template <typename T>
void MinPriorityQueue<T>::printTree() {
    cout << "\nPrint MIN HEAP TREE:" << endl;
    for(int i = 0; i < this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << "  ";
}

template <typename T>
void MinPriorityQueue<T>::printAsciiTree() {
    cout << "\nPrint MIN HEAP ASCII TREE:" << endl;
    this->inOrderAscii(0, 0);
}



#endif //ALGORITHM_DATA_STRUCTURES_MINPRIORITYQUEUE_H
