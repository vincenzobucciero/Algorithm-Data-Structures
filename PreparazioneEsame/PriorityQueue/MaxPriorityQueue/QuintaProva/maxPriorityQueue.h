//
// Created by vincenzo on 03/10/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_MAXPRIORITYQUEUE_H
#define ALGORITHM_DATA_STRUCTURES_MAXPRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <list>

#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/PriorityQueue/MaxPriorityQueue/QuintaProva/maxHeap.h"

#define vuoto 5

using namespace std;

template <typename T>
class MaxPriorityQueue : private MaxHeap<T> {
public:
    explicit MaxPriorityQueue(vector<T>* tree) : MaxHeap<T>(tree) {  }
    MaxPriorityQueue() {  }
    ~MaxPriorityQueue() {  }

    T queueMaximum();
    T queueExtractMax();

    void queueInsert(T x);
    void queueIncreaseKey(int i, T key);

    void printTree();
    void printAsciiTree();
};

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
void MaxPriorityQueue<T>::queueIncreaseKey(int i, T key) {
    if(key < this->getTree()->at(i))
        return;
    this->setTree(i, key);
    while(i > 0 && this->getTree()->at(this->parent(i)) < this->getTree()->at(i)) {
        this->swap(this->getTree()->at(i), this->getTree()->at(this->parent(i)));
        i = this->parent(i);
    }
}

template <typename T>
void MaxPriorityQueue<T>::printTree() {
    cout << "Print Max Heap: " << endl;
    for(int i = 0; i < this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << "  ";
}

template <typename T>
void MaxPriorityQueue<T>::printAsciiTree() {
    cout << "Print Max Heap Ascii Tree:" << endl;
    this->inOrderAscii(0, 0);
}

#endif //ALGORITHM_DATA_STRUCTURES_MAXPRIORITYQUEUE_H
