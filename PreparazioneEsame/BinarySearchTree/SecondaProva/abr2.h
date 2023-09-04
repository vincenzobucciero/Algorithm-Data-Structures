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

        void inOrderAscii(Nodo2<T>* x, int spazio);
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

        void preOrderVisit(Nodo2<T>* x);
        void inOrderVisit(Nodo2<T>* x);
        void postOrderVisit(Nodo2<T>* x);

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


template <typename T>
void Abr2<T>::transplant(Nodo2<T>* x, Nodo2<T>* y) {
    if(x->getParent() == nullptr)
        root = y;
    else if(x == x->getParent()->getLeft())
        x->getParent()->setLeft(y);
    else 
        x->getParent()->setRight(y);
    if(y != nullptr)
        y->setParent(x->getParent());
}

template <typename T>
void Abr2<T>::treeDelete(Nodo2<T>* x) {
    if(x == nullptr)
        x = nullptr;
    if(x->getLeft() == nullptr)
        transplant(x, x->getRight());
    else if(x->getRight() == nullptr)
        transplant(x, x->getLeft());
    else {
        Nodo2<T>* y = successor(x);
        if(y->getParent() != x) {
            transplant(y, y->getParent());
            y->setRight(x->getRight());
            y->getRight()->setParent(y);
        }
        transplant(x, y);
        y->setLeft(x->getLeft());
        y->getLeft()->setParent(y);
    }
}

template <typename T>
void Abr2<T>::inOrderAscii(Nodo2<T>* x, int spazio) {
    if(x == nullptr)
        return;
    spazio += vuoto;
    inOrderAscii(x->getRight(), spazio);
    cout << endl;
    for(int i = vuoto; i < spazio; i++) 
        cout << " ";
    cout << x->getInfo() << endl;
    inOrderAscii(x->getLeft(), spazio);
}

template <typename T>
void Abr2<T>::printAsciiTree() {
    cout << "Printing tree: " << endl;
    inOrderAscii(root, 0);
}

template <typename T>
void Abr2<T>::preOrderVisit(Nodo2<T>* x) {
    if(x != nullptr) {
        cout << x->getInfo() << "  ";
        preOrderVisit(x->getLeft());
        preOrderVisit(x->getRight());
    }
}

template <typename T>
void Abr2<T>::inOrderVisit(Nodo2<T>* x) {
    if(x != nullptr) {
        preOrderVisit(x->getLeft());
        cout << x->getInfo() << "  ";
        preOrderVisit(x->getRight());
    }
}

template <typename T>
void Abr2<T>::postOrderVisit(Nodo2<T>* x) {
    if(x != nullptr) {
        preOrderVisit(x->getLeft());
        preOrderVisit(x->getRight());
        cout << x->getInfo() << "  ";
    }
}


#endif //ABR2_H