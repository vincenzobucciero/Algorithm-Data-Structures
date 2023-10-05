//
// Created by vincenzo on 05/10/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_HEAP_H
#define ALGORITHM_DATA_STRUCTURES_HEAP_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T>
class Heap {
private:
    vector<T>* tree;
    int heapSize;

    int left(int i) {return (2*i)+1;}
    int right(int i) {return (2*i)+2;}
    int parent(int i) {return (i-1)/2;}

    void buildMaxHeap();

    void swap(T& a, T& b);
    void maxHeapify(int i);
public:
    Heap(vector<T>* tree);
    Heap();
    ~Heap();

    void insert(T x);
    void printTree();
    void heapSort();
    //void inOrderAscii(int i, int spazio);
    //void printAsciiTree();
};

template <typename T>
Heap<T>::Heap(vector<T>* tree) {
    this->tree = tree;
    this->heapSize = this->tree->size();
    buildMaxHeap();
}

template <typename T>
Heap<T>::Heap() {
    this->tree = new vector<T>;
    this->heapSize = 0;
}

template <typename T>
Heap<T>::~Heap() {
    delete tree;
}

template <typename T>
void Heap<T>::swap(T &a, T &b) {
    T tmp; tmp = a; a = b; b = tmp;
}

template <typename T>
void Heap<T>::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int max = i;
    if(l < heapSize && this->tree->at(max) < this->tree->at(l))
        max = l;
    if(r < heapSize && this->tree->at(max) < this->tree->at(r))
        max = r;
    if(max != i) {
        swap(this->tree->at(i), this->tree->at(max));
        maxHeapify(max);
    }
}

template <typename T>
void Heap<T>::buildMaxHeap() {
    for(int i = heapSize/2; i >= 0; i--)
        maxHeapify(i);
}

template <typename T>
void Heap<T>::insert(T x) {
    heapSize++;
    this->tree->push_back(x);
    int i = heapSize-1;
    while(i != 0 && this->tree->at(parent(i)) < this->tree->at(i)) {
        swap(this->tree->at(i), this->tree->at(parent(i)));
        i = parent(i);
    }
}

template <typename T>
void Heap<T>::heapSort() {
    buildMaxHeap();
    for(int i = heapSize-1; i >= 0; i--) {
        swap(tree->at(0), tree->at(i));
        heapSize--;
        maxHeapify(0);
    }
}

template <typename T>
void Heap<T>::printTree() {
    cout << "Heap: ";
    for (const auto& num : *tree) {
        cout << num << " ";
    }
    cout << endl;
}


#endif //ALGORITHM_DATA_STRUCTURES_HEAP_H
