//
// Created by vincenzo on 22/09/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_MINPRIORITYQUEUE_H
#define ALGORITHM_DATA_STRUCTURES_MINPRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <list>
#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/PriorityQueue/MinPriorityQueue/TerzaProva/minHeap.h"

#define vuoto 5

using namespace std;

template <typename T>
class minPriorityQueue : private minHeap<T> {
public:
    minPriorityQueue(vector<T>* tree) : minHeap<T>(tree) { }
    minPriorityQueue() { }
    ~minPriorityQueue() { }
    T queueMinimum();
    T queueExtractMin();
    void queueInsert(T x);
    void queueDecreaseKey(int i, T key);
    void printTree();
    void printAsciiTree();
};

template<typename T>
void minPriorityQueue<T>::queueDecreaseKey(int i, T key) {
    if(key < this->getTree()->at(i))
        return;
    this->setTree(i, key);
    while(i > 0 && this->getTree()->at(this->parent(i)) > this->getTree()->at(i)) {
        this->swap(this->getTree()->at(i), this->getTree()->at(this->parent(i)));
        i = this->parent(i);
    }
}

template<typename T>
void minPriorityQueue<T>::queueInsert(T x) {
    this->insert(x);
}

template<typename T>
T minPriorityQueue<T>::queueExtractMin() {
    if(this->getHeapSize() == 0)
        return false;
    T min = this->getRoot();
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->minHeapify(0);

    return min;
}

template<typename T>
T minPriorityQueue<T>::queueMinimum() {
    return this->getRoot();
}

template<typename T>
void minPriorityQueue<T>::printTree() {
    cout << "Print Min Heap:" << endl;
    for(int i = 0; i < this->getHeapSize(); i++) {
        cout << this->getTree()->at(i) << "  ";
    }
}

template<typename T>
void minPriorityQueue<T>::printAsciiTree() {
    cout << "Print Min Heap Ascii Tree:" << endl;
    this->inOrderAscii(0, 0);
}




#endif //ALGORITHM_DATA_STRUCTURES_MINPRIORITYQUEUE_H
