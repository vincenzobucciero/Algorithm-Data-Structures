#ifndef MAXPRIORITYQUEUE3H
#define MAXPRIORITYQUEUE3_H

#include <iostream>
#include <vector>
#include "maxHeap3.h"

using namespace std;

template <typename T>
class MaxPriorityQueue3 : private MaxHeap3<T> {
    public:
        MaxPriorityQueue3(vector<T>* tree);
        MaxPriorityQueue3();
        ~MaxPriorityQueue3();
        T queueMaximum();
        T queueExtractMax();
        void queueInsert(T x);
        void queueIncreaseKey(int i, T key);
        void printTree();
        void printAsciiTree();
};

template <typename T>
MaxPriorityQueue3<T>::MaxPriorityQueue3(vector<T>* tree) : MaxHeap3<T> (tree) {  }

template <typename T>
MaxPriorityQueue3<T>::MaxPriorityQueue3() {  }

template <typename T>
MaxPriorityQueue3<T>::~MaxPriorityQueue3() {  }

template <typename T>
T MaxPriorityQueue3<T>::queueMaximum() {
    return this->getRoot();
}

template <typename T>
T MaxPriorityQueue3<T>::queueExtractMax() {
    if(this->getHeapSize() == 0)
        return false;
    T max = this->getRoot();
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->maxHeapify(0);

    return max;
}

template <typename T>
void MaxPriorityQueue3<T>::queueInsert(T x) {
    this->insert(x);
}

template <typename T>
void MaxPriorityQueue3<T>::queueIncreaseKey(int i, T key) {
    if(key < this->getTree()->at(i))
        return;
    this->setTree(i, key);
    while(i > 0 && this->getTree()->at(this->parent(i)) < this->getTree()->at(i)) {
        this->swap(this->getTree()->at(i), this->getTree()->at(this->parent(i)));
        i = this->parent(i);
    }    
}

template <typename T>
void MaxPriorityQueue3<T>::printTree() {
    cout << "\nPrinting Max Tree: ";
    for(int i = 0; i < this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << "  ";
}

template <typename T>
void MaxPriorityQueue3<T>::printAsciiTree() {
    cout << "\nPrinting Max Ascii Tree:" << endl;
    this->inOrderAscii(0, 0);
}



#endif //MAXPRIORITYQUEUE3_H