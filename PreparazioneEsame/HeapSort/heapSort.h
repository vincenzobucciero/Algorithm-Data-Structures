#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <vector>

#define vuoto 5

using namespace std;

template <typename T>
class HeapSort {
    private:
        vector<T> tree;
        int heapSize;
        int parent(int i) {return (i-1)/2;}
        int left(int i) {return (2*i)+1;}
        int right(int i) {return (2*i)+2;}

        void setHeapSize(int heapSize) {this->heapSize = heapSize;}
        int getHeapSize() {return this->heapSize;}

        vector<T> getTree(){return this->tree;}

        void swap(T& a, T& b);
        void buildMaxHeap();
        void maxHeapify(int i);
        void insert(T x);
    public:
        HeapSort(vector<T> tree);
        HeapSort();

        void heapSortMethod();
        void printTree();
        //void inOrderAscii(int i, int spazio);
        //void printAsciiTree();
};

template <typename T>
HeapSort<T>::HeapSort(vector<T> tree) {
    this->tree = tree;
    this->heapSize = tree.size();
    buildMaxHeap();
}

template <typename T>
HeapSort<T>::HeapSort() {
    //this->tree = new vector<T>;
    this->heapSize = 0;
}

template <typename T>
void HeapSort<T>::swap(T& a, T& b) {
    int tmp; tmp = a; a = b; b = tmp;
}

template <typename T>
void HeapSort<T>::buildMaxHeap() {
    for(int i = getHeapSize()/2; i >= 0; i--)
        maxHeapify(i);
}

template <typename T>
void HeapSort<T>::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int max = i;

    if(l < getHeapSize() && getTree().at(max) < getTree().at(l))
        max = l;
    if(r < getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;
    if(max != i) {
        swap(tree.at(max), tree.at(i));
        maxHeapify(max);
    }
}

template <typename T>
void HeapSort<T>::insert(T x) {
    setHeapSize(getHeapSize()+1);
    tree.push_back(x);
    int i = getHeapSize()-1;

    while(i > 0 && getTree().at(parent(i)) < x) {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);
    }
}

template <typename T>
void HeapSort<T>::heapSortMethod() {
    buildMaxHeap();
    for(int i = getHeapSize()-1; i >= 0; i--) {
        swap(tree.at(0), tree.at(i));
        setHeapSize(getHeapSize()-1);
        maxHeapify(0);
    }
}

template <typename T>
void HeapSort<T>::printTree() {
    cout << "\nPrint Tree: " << endl;
    for(auto i : tree)
        cout << i << endl;
}

/*
template <typename T>
void HeapSort<T>::inOrderAscii(int i, int spazio) {
    if(i >= heapSize)
        return;
    spazio += vuoto;
    inOrderAscii(right(i), spazio);
    cout << endl;
    for(int i = vuoto; i < spazio; i++)
        cout << "  ";
    cout << tree.at(i) << endl;
    inOrderAscii(left(i), spazio);
}

template <typename T>
void HeapSort<T>::printAsciiTree() {
    cout << "\nPrint Ascii Tree:" << endl;
    inOrderAscii(0, 0);
}
*/

#endif