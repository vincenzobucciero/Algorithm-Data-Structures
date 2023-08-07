/**
 * Progettare ed implementare un algoritmo ricorsivo che dato
 * un array verifichi se rappresenta un [min, max]-heap binario
*/

#ifndef ISHEAP_H
#define ISHEAP_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class IsHeap {
    private:
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i)+1; }
        int right(int i) { return (2*i)+2; }

        bool isMaxHeap(vector<T> tree, int heapSize, int i);
        bool isMinHeap(vector<T> tree, int heapSize, int i);

    public:
        void print(vector<T> tree, int heapSize, int i);
};

template <typename T>
bool IsHeap<T>::isMaxHeap(vector<T> tree, int heapSize, int i) {
    int l = left(i);
    int r = right(i);

    if(i >= heapSize/2)
        return true;
    if(l < heapSize && tree.at(i) < tree.at(l))
        return false;
    if(r < heapSize && tree.at(i) < tree.at(r))
        return false;

    return isMaxHeap(tree, heapSize, l) && isMaxHeap(tree, heapSize, r);
}

template <typename T>
bool IsHeap<T>::isMinHeap(vector<T> tree, int heapSize, int i) {
    int l = left(i);
    int r = right(i);

    if(i >= heapSize/2)
        return true;
    if(l < heapSize && tree.at(i) > tree.at(l))
        return false;
    if(r < heapSize && tree.at(i) > tree.at(r))
        return false;

    return isMinHeap(tree, heapSize, l) && isMinHeap(tree, heapSize, r);
}

template <typename T>
void IsHeap<T>::print(vector<T> tree, int heapSize, int i) {
    if(isMaxHeap(tree, heapSize, i) && !isMinHeap(tree, heapSize, i)) {
        cout << "L'albero è un MaxHeap" << endl;
    } else if(!isMaxHeap(tree, heapSize, i) && isMinHeap(tree, heapSize, i)) {
        cout << "L'albero è un MinHeap" << endl;
    } else {
        cout << "L'albero NON è un heap" << endl;
    }
}


#endif //ISHEAP_H