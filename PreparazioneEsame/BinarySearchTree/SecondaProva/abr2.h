#ifndef ABR2_H
#define ABR2_H

#include <iostream>
#include <vector>

#include "nodo2.h"

#define vuoto 5

using namespace std;

template <typename T>
class Abr2 {
    private:
        Nodo2<T>* root;

        void insertNodo(T value, Nodo2<T>* prev, Nodo2<T>* curr);
        void insertRic(T value, Nodo2<T>* prev, Nodo2<T>* curr);

        Nodo2<T>* findSuccessor(Nodo2<T>* x);
        Nodo2<T>* findPredecessor(Nodo2<T>* x);

        void inOrderAscii(Nodo<T>* x, int spazio);
    public:
        Abr2() { this->root = nullptr; }

        Nodo2<T>* getRoot() { return this->root; }

        void insert(T value);

        Nodo2<T>* treeSearch(Nodo2<T>* x, int key);
        Nodo2<T>* getMinimum(Nodo2<T>* x);
        Nodo2<T>* getMaximum(Nodo2<T>* x);
        Nodo2<T>* successor(Nodo2<T>* x);
        Nodo2<T>* predecessor(Nodo2<T>* x);

        void transplant(Nodo2<T>* x, Nodo2<T>* y);
        void treeDelete(Nodo2<T>* x);

        void printAsciiTree();
};

template <typename T>
void Abr2<T>::insertNodo(T value, Nodo2<T>* prev, Nodo2<T>* curr) {
    curr = new Nodo2<T>(value);
    curr->setParent(prev);
    if(curr->getInfo() < prev->getInfo)
        prev->setLeft(curr);
    else 
        prev->setRight(curr);
}

template <typename T>
void Abr2<T>::insertRic(T value, Nodo2<T>* prev, Nodo2<T>* curr) {
    if(root == nullptr)
        root = new Nodo2<T>(value);
    else if(curr == nullptr)
        insertNodo(value, prev, curr);
    else if(curr->getInfo() > value)
        insertRic(value, curr, curr->getLeft());
    else 
        insertRic(value, curr, curr->getRight());
}

template <typename T>
void Abr2<T>::insert(T value) {
    insertRic(value, nullptr, root);
}

template <typename T>
Nodo2<T>* Abr2<T>::findSuccessor(Nodo2<T>* x) {
    if(x == nullptr)
        return nullptr;
    Nodo2<T>* y = x->getParent();
    if(y == nullptr)
        return nullptr;
    else if(x == y->getLeft())
        return y;
    else    
        return findSuccessor(y);
}

template <typename T>
Nodo2<T>* Abr2<T>::successor(Nodo2<T>* x) {
    if(x == nullptr)
        return nullptr;
    else if(x->getRight() != nullptr)
        return getMinimum(x->getRight());
    else
        return findSuccessor(x);
}

template <typename T>
Nodo2<T>* Abr2<T>::findPredecessor(Nodo2<T>* x) {
    if(x == nullptr)
        return nullptr;
    Nodo2<T>* y = x->getParent();
    if(y == nullptr)
        return nullptr;
    else if(x = y->getRight())
        return y;
    else
        return findPredecessor(y);    
}

template <typename T>
Nodo2<T>* Abr2<T>::predecessor(Nodo2<T>* x) {
    if(x == nullptr)
        return nullptr;
    else if(x->getLeft() != nullptr)
        return getMaximum(x->getLeft());
    else    
        return findPredecessor(x);
}

template <typename T>
Nodo2<T>* Abr2<T>::getMaximum(Nodo2<T>* x) {
    if(root == nullptr)
        return nullptr;
    else if(x->getRight() == nullptr)
        return x,
    else    
        return getMaximum(x->getRight());
}

template <typename T>
Nodo2<T>* Abr2<T>::getMinimum(Nodo2<T>* x) {
    if(root == nullptr)
        return nullptr;
    else if(x->getLeft() == nullptr)
        return x;
    else
        return getMinimum(x->getLeft());
}

template <typename T>
Nodo2<T>* Abr2<T>::treeSearch(Nodo2<T>* x, int key) {
    if(x == nullptr || key == x->getInfo())
        return x;
    else if(key < x->getInfo())
        return treeSearch(x->getLeft(), key);
    else
        return treeSearch(x->getRight(), key);
}


#endif //ABR2_H