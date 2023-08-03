/**
 * La blockchain è una struttura dati composta da una lista di
 * blocchi all'interno dei quali è memorizzato un insieme di
 * transazioni.
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include "transaction.h"

template <typename T>
class Node {
    private:
        T *info;
        Node<T> *nextNode;
    public:
        Node(T *info);
        ~Node();

        void setInfo(T *info);
        T *getInfo();

        void setNext(Node<T> *nextNode);
        Node<T> *getNext();
};

template <typename T>
Node<T>::Node(T *info){
    this->info = info;
    this->nextNode = nullptr;
}

template <typename T>
Node<T>::~Node(){
    delete info;
    delete nextNode;
}

template <typename T>
void Node<T>::setInfo(T *info){
    this->info = info;
}

template <typename T>
T *Node<T>::getInfo(){
    return info;
}

template <typename T>
void Node<T>::setNext(Node<T> *nextNode){
    this->nextNode = nextNode;
}

template <typename T>
Node<T> *Node<T>::getNext(){
    return nextNode;
}



#endif

