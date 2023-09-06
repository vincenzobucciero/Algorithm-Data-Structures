#ifndef MAXPRIORITYQUEUE2_H
#define MAXPRIORITYQUEUE2_H

#include <iostream>
#include <vector>

#include "maxHeap2.h"

using namespace std;

template <typename T>
class MaxPriorityQueue2 : private MaxHeap2<T> {
    public:
        MaxPriorityQueue2(vector<T>* tree);
        MaxPriorityQueue2();
        ~MaxPriorityQueue2();

        T queueExtractMax();
        T queueMaximum();

        void queueInsert(T x);
        void queueIncreasePriority(int i, T key);

        void printTree();
        void printAsciiTree();
};

template <typename T>
MaxPriorityQueue2<T>::MaxPriorityQueue2(vector<T>* tree) : MaxHeap2<T> (tree) {  }

template <typename T>
MaxPriorityQueue2<T>::MaxPriorityQueue2() {  }

template <typename T>
MaxPriorityQueue2<T>::~MaxPriorityQueue2() {  }

template <typename T>
T MaxPriorityQueue2<T>::queueMaximum() {
    return this->getRoot();
}

template <typename T>
T MaxPriorityQueue2<T>::queueExtractMax() {
    if(this->getHeapSize() == 0)
        return false;
    T max = this->getRoot();
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->maxHeapify(0);

    return max;
}

template <typename T>
void MaxPriorityQueue2<T>::queueInsert(T x) {
    this->insert(x);
}

template <typename T>
void MaxPriorityQueue2<T>::queueIncreasePriority(int i, T key) {
    if(key < this->getTree()->at(i))
        return;
    this->setTree(i, key);
    while(i > 0 && this->getTree()->at(this->parent(i)) < this->getTree()->at(i)) {
        this->swap(this->getTree()->at(i), this->getTree()->at(this->parent(i)));
        i = this->parent(i);
    }
}

template <typename T>
void MaxPriorityQueue2<T>::printTree() {
    cout << "Printing MaxHeap Tree:" << endl;
    for(int i = 0; i < this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << "  ";
}

template <typename T>
void MaxPriorityQueue2<T>::printAsciiTree() {
    cout << "Printing MaxHeap Ascii Tree:" << endl;
    this->inOrderAscii(0, 0);
}


#endif //MAXPRIORITYQUEUE2_H