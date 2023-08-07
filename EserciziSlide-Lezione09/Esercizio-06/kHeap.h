/**
 * Progettare ed implementare una classe che implementi un heap k-nario (ogni nodo ha k figli)
*/

#ifndef KHEAP_H
#define KHEAP_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class KHeap {
    private:
        vector<T>* tree;
        int heapSize;
        int k;

        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i)+1; }
        int right(int i) { return (2*i)+2; }

        void swap(T& a, T& b);
        void buildKHeap();
        void kHeapify(int i);

    public:
        KHeap(vector<T>* tree, int k);
        KHeap();
        ~KHeap();

        void insert(T x);
        void print();
};

template <typename T>
KHeap<T>::KHeap(vector<T>* tree, int k) {
    this->tree = tree;
    this->heapSize = this->tree->size();
    this->k = k;
    buildKHeap();
}

template <typename T>
KHeap<T>::KHeap() {
    this->tree = new vector<T>;
    this->heapSize = 0;
    this->k = k;
}

template <typename T>
KHeap<T>::~KHeap() {
    delete tree;
}

template <typename T>
void KHeap<T>::swap(T& a, T& b) {
    int tmp; tmp = a; a = b; b = tmp;
}

template <typename T>
void KHeap<T>::buildKHeap() {
    for(int i = heapSize/k; i >= 0; i--) {
        kHeapify(i);
    }
}

template <typename T>
void KHeap<T>::kHeapify(int i) {
    int index = i+1;
    int last = k*index;
    int first = last-k;

    int max = i;

    for(int j = last; j > first; j--) {
        if(j < heapSize && this->tree->at(max) < this->tree->at(j))
            max = j;
    }
    if(max != i) {
        swap(this->tree->at(i), this->tree->at(max));
        kHeapify(max);
    }
}

template <typename T>
void KHeap<T>::insert(T x) {
    this->tree->push_back(x);
    heapSize++;
    buildKHeap();
}

template <typename T>
void KHeap<T>::print() {
    cout << "Printing the Heap: " << endl;
    for(int i = 0; i < heapSize; i++) {
        cout << this->tree->at(i) << "  ";
    }
}

#endif //KHEAP_H