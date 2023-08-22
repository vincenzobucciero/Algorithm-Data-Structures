/**
 * Bisogna pianificare un viaggio in autostrada entrando al km 0 ed uscendo al km N.
    • L'auto con serbatoio pieno ha un'autonomia di m km.
    • Esistono n stazioni di servizio ai km d[1...n] in cui è possibile fare il pieno.
    
    • Progettare un algoritmo greedy che consenta di minimizzare il numero di soste.
*/

#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/programmazioneGreedy/Esercizio02/minheap.h"

template <typename T>
class MinPriorityQueue : private MinHeap<T> {
    public:
        MinPriorityQueue(vector<T>* tree) : MinHeap<T>(tree) {  }
        MinPriorityQueue() {  }
        ~MinPriorityQueue() {  }

        T queueMinimum();
        T queueExtractMin();

        void queueInsert(T x);
        void queueDecreaseKey(int i, T key);

        void printingTree();
        void printingAsciiTree();
};

template <typename T>
T MinPriorityQueue<T>::queueMinimum() {
    return this->getRoot();
}

template <typename T>
T MinPriorityQueue<T>::queueExtractMin() {
    if(this->getHeapSize() == 0)
        return false;
    T min = this->getRoot();
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->minHeapify(0);

    return min;
} 

template <typename T>
void MinPriorityQueue<T>::queueInsert(T x) {
    this->insert(x);
}

template <typename T>
void MinPriorityQueue<T>::queueDecreaseKey(int i, T key) {
    if(key > this->getTree()->at(i))
        return;
    
    this->setTree(i, key);

    while(i > 0 && this->getTree()->at(this->parent(i)) > this->getTree()->at(i)) {
        this->swap(this->getTree()->at(i), this->getTree()->at(this->parent(i)));
        i = this->parent(i);
    }
}

template <typename T>
void MinPriorityQueue<T>::printingTree(){
    cout << endl << "***Min Heap***" << endl;
    for (int i = 0; i < this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << " ";
}

template <typename T>
void MinPriorityQueue<T>::printingAsciiTree(){
    cout << endl << "***Min Ascii Heap***" << endl;
    this->inOrderAscii(0,0);
}

#endif //MINPRIORITYQUEUE_H