//
// Created by vincenzo on 22/09/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_MINHEAP_H
#define ALGORITHM_DATA_STRUCTURES_MINHEAP_H

#include <iostream>
#include <vector>
#include <list>

#define vuoto 5

using namespace std;

template <typename T>
class minHeap {
private:
    vector<T>* tree;
    int heapSize;
    int left(int i) {return (2*i)+1;}
    int right(int i) {return (2*i)+2;}
    void buildMinHeap();
protected:
    int parent(int i) {return (i-1)/2;}
    T getRoot() {return this->tree->at(0);}
    void setTree(int i, T key) {this->tree->at(i) = key;}
    vector<T>* getTree() {return this->tree;}
    void setHeapSize(int heapSize) {this->heapSize = heapSize;}
    int getHeapSize() {return this->heapSize;}
    void swap(T& a, T& b);
    void minHeapify(int i);
public:
    minHeap(vector<T>* tree) {this->tree = tree; this->heapSize = this->tree->size();}
    minHeap() {this->tree = new vector<T>; this->heapSize = 0;}
    ~minHeap() {delete this->tree;}
    void insert(T x);
    void printTree();
    void inOrderAscii(int i, int spazio);
    void printAsciiTree();
};

template<typename T>
void minHeap<T>::swap(T &a, T &b) {
    int tmp; tmp = a; a = b; b = tmp;
}

template<typename T>
void minHeap<T>::buildMinHeap() {
    for(int i = heapSize/2; i >= 0; i++)
        minHeapify(i);
}

template<typename T>
void minHeap<T>::minHeapify(int i) {
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

template<typename T>
void minHeap<T>::insert(T x) {
    this->tree->push_back(x);
}

template<typename T>
void minHeap<T>::printTree() {
    cout << "Print Tree:" << endl;
    for(int i = 0; i < heapSize; i++) {
        cout << this->tree->at(i) << "  ";
    }
}

template<typename T>
void minHeap<T>::inOrderAscii(int i, int spazio) {
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

template<typename T>
void minHeap<T>::printAsciiTree() {
    cout << "Print Ascii Tree:" << endl;
    inOrderAscii(0, 0);
}







#endif //ALGORITHM_DATA_STRUCTURES_MINHEAP_H
