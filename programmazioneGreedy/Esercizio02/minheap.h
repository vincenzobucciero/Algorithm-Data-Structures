/**
 * Bisogna pianificare un viaggio in autostrada entrando al km 0 ed uscendo al km N.
    • L'auto con serbatoio pieno ha un'autonomia di m km.
    • Esistono n stazioni di servizio ai km d[1...n] in cui è possibile fare il pieno.
    
    • Progettare un algoritmo greedy che consenta di minimizzare il numero di soste.
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

        int left(int i) { return (2*i)+1; }
        int right(int i) { return (2*i)+2; }

        void buildMinHeap();
    protected:
        int parent(int i) { return (i-1)/2; }

        T getRoot() { return this->tree->at(0); }
        T getTail() { return this->tree->at(heapSize-1); }

        void setTree(int i, T key) { this->tree->at(i) = key; }
        vector<T>* getTree() { return this->tree; }

        void setHeapSize(int heapSize) { this->heapSize = heapSize; }
        int getHeapSize() { return this->heapSize; }

        void swap(T& a, T& b);
        void minHeapify(int i);
    public:
        MinHeap(vector<T>* tree);
        MinHeap();
        ~MinHeap();

        void insert(T x);
        void printingTree();
        void inOrderAscii(int i, int spazio);
        void printingAsciiTree();
};

template <typename T>
MinHeap<T>::MinHeap(vector<T>* tree) {
    this->tree = tree;
    this->heapSize = this->tree->size();
    buildMinHeap();
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
    int tmp; tmp = a; a = b; b = tmp;
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
void MinHeap<T>::buildMinHeap() {
    for(int i = heapSize/2; i >= 0; i--)
        minHeapify(i);     
}

template <typename T>
void MinHeap<T>::insert(T x) {
    heapSize++;
    this->tree->push_back(x);
    int i = heapSize-1;

    while(i != 0 && this->tree->at(parent(i)) > this->tree->at(i)) {
        swap(this->tree->at(i), this->tree->at(parent(i)));
        i = parent(i);
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
        cout << " ";
    cout << this->tree->at(i) << endl;
    inOrderAscii(left(i), spazio);
}

template <typename T>
void MinHeap<T>::printingTree() {
    cout << "Printing Tree: " << endl;
    for(int i = 0; i < heapSize; i++)
        cout << this->tree->at(i) << " ";
}

template <typename T>
void MinHeap<T>::printingAsciiTree() {
    cout << "Printing Ascii Tree: " << endl;
    inOrderAscii(0, 0);
}


#endif //MINHEAP_H