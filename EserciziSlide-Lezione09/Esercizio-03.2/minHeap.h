/**
 * Progettare ed implementare una classe template Min-Heap dotata delle seguenti operazioni
    • Min-Heapify
    • Build-Min-Heap
    • Insert
    • PrintArray
    • (PrintAsciiTree)
*/

#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <vector>

#define vuoto 5

using namespace std;

template <typename T>
class MinHeap {
    private:
        vector<T>* tree;
        int heapSize;

        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i)+1; }
        int right(int i) { return (2*i)+2; }

        void swap(T& a, T& b);
        void buildMinHeap();
        void minHeapify(int i);
        void inOrderAscii(int i , int spazio);

    public:
        MinHeap(vector<T>* tree);
        MinHeap();
        ~MinHeap();

        void insert(T x);
        void printTree();
        void printAsciiTree();
};

template <typename T>
MinHeap<T>::MinHeap(vector<T>* tree) {
    this->tree = tree;
    this->heapSize = this->tree->size();
}

template <typename T>
MinHeap<T>::MinHeap() {
    this->tree = new vector<T>;
    this->heapSize = 0;
}

template <typename T>
MinHeap<T>::~MinHeap() {
    delete tree;
}

template <typename T>
void MinHeap<T>::swap(T& a, T& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void MinHeap<T>::buildMinHeap() {
    for(int i = heapSize/2; i >= 0; i--)
        minHeapify(i);
}

template <typename T>
void MinHeap<T>::minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int min = i;

    if(l < heapSize && this->tree->at(min) > this->tree->at(l))
        min = l;
    if(r < heapSize && this->tree->at(min) > this->tree->at(r))
        min = r;   
    if(min != i) {
        swap(this->tree->at(i), this->tree->at(min));
        minHeapify(min);
    } 
}

template <typename T>
void MinHeap<T>::insert(T x) {
    this->tree->push_back(x);
    heapSize++;
    buildMinHeap();
}

template <typename T>
void MinHeap<T>::printTree() {
    cout << "Printing the Tree: " << endl;
    for(int i = 0; i < heapSize; i++) {
        cout << this->tree->at(i) << "  ";
    }
}

template <typename T>
void MinHeap<T>::inOrderAscii(int i, int spazio) {
    if(i >= heapSize)
        return;
    spazio += vuoto;
    inOrderAscii(right(i), spazio);
    cout << endl;
    for(int i = vuoto; i < spazio; i++) 
        cout << "  ";
    cout << this->tree->at(i) << endl;
    inOrderAscii(left(i), spazio);
}

template <typename T>
void MinHeap<T>::printAsciiTree() {
    cout << "\nPrinting the Ascii Tree:" << endl;
    inOrderAscii(0, 0);
}

#endif //MINHEAP_H