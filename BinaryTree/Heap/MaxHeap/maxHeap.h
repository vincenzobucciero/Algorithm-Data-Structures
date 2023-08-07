/**
 * Progettare ed implementare una classe template Max-Heap dotata delle seguenti operazioni
    • Max-Heapify
    • Build-Max-Heap
    • Insert
    • PrintArray
    • (PrintAsciiTree)
*/

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>

#define vuoto 5

using namespace std;

template <typename T>
class MaxHeap {
    private:
        vector<T>* tree;
        int heapSize;

        int parent(int i);
        int left(int i);
        int right(int i);

        void maxHeapify(int i);
        void buildMaxHeap();
        void swap(T& a, T& b);
        void inOrderAscii(int i, int spazio);   //per stampare albero
    public:
        MaxHeap(vector<T>* tree);
        MaxHeap();
        ~MaxHeap();

        void insert(T x);
        void print();
        void printAsciiTree();
};

template <typename T>
MaxHeap<T>::MaxHeap(vector<T>* tree) {
    this->tree = tree;
    this->heapSize = tree->size();;  
    //per garantire che anche inizialmente l'albero rispetti
    //le proprietà del maxHeap, chiamiamo buildMaxHeap() per riorganizzare 
    //l'array in modo che diventi un Max-Heap.
    buildMaxHeap();
}

template <typename T>
MaxHeap<T>::MaxHeap(){
    this->tree = new vector<T>;
    this->heapSize = 0;
}

template <typename T>
MaxHeap<T>::~MaxHeap() {
    delete tree;
}

template <typename T>
int MaxHeap<T>::parent(int i) {
    return (i-1)/2;
}
template <typename T>
int MaxHeap<T>::left(int i) {
    return (2*i)+1;
}
template <typename T>
int MaxHeap<T>::right(int i) {
    return (2*i)+2;
}

template <typename T>
void MaxHeap<T>::swap(T& a, T& b) {
    int tmp;
    tmp = a;
    a = b; 
    b = tmp;
}

template <typename T>
void MaxHeap<T>::maxHeapify(int i) {
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
void MaxHeap<T>::buildMaxHeap() {
    for(int i = heapSize/2; i >= 0; i--)
        maxHeapify(i);
}

template <typename T>
void MaxHeap<T>::insert(T x) {
    this->tree->push_back(x);
    heapSize++;
    buildMaxHeap();
}

template <typename T>
void MaxHeap<T>::print() {
    cout << "Tree: " << endl;
    for(int i = 0; i < heapSize; i++) {
        cout << tree->at(i) << " ";
    }
}

template <typename T>
void MaxHeap<T>::inOrderAscii(int i, int spazio){

    if (i >= heapSize)
        return;

    spazio += vuoto;

    inOrderAscii(right(i),spazio);

    cout << endl;
    for (int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << this->tree->at(i) << endl;

    inOrderAscii(left(i),spazio);
}

template <typename T>
void MaxHeap<T>::printAsciiTree(){
    cout << endl << "***Max Ascii Heap***" << endl;
    inOrderAscii(0,0);
}





#endif //MAXHEAP_H