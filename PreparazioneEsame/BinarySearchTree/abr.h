#ifndef ABR_H
#define ABR_H

#include <iostream>
#include <vector>

#define vuoto 5

#include "nodo.h"

using namespace std;

template <typename T>
class Abr {
    private:
        Nodo<T>* root;

        void insertNodo(T value, Nodo<T>* prev, Nodo<T>* curr);
        void insertRic(T value, Nodo<T>* prev, Nodo<T>* curr);

        Nodo<T>* findSuccessor(Nodo<T>*);
        Nodo<T>* findPredecessor(Nodo<T>*);

        void inOrderAscii(Nodo<T>* x, int spazio);
    public:
        //costruttore
        Abr();

        Nodo<T>* getRoot() { return this->root; }

        Nodo<T> *treeSearch(Nodo<T> *x, T key);
        Nodo<T> *getMinimum(Nodo<T> *x);
        Nodo<T> *getMaximum(Nodo<T> *x);
        Nodo<T> *successor(Nodo<T> *x);
        Nodo<T> *predecessor(Nodo<T> *x);

        void insert(T value);

        void treeDelete(Nodo<T> *x);
        void transplant(Nodo<T> *x, Nodo<T> *y);

        void visitInOrder(Nodo<T> *x);
        void visitPreOrder(Nodo<T> *x);
        void visitPostOrder(Nodo<T> *x);

        void printAsciiTree();
};

template <typename T>
Abr<T>::Abr() {
    this->root = nullptr;
}

template <typename T>
void Abr<T>::insertNodo(T value, Nodo<T>* prev, Nodo<T>* curr) {
    curr = new Nodo<T>(value);
    curr->setParent(prev);
    if(curr->getInfo() < prev->getInfo())
        prev->setLeft(curr);
    else    
        prev->setRight(curr);
}

template <typename T>
void Abr<T>::insertRic(T value, Nodo<T>* prev, Nodo<T>* curr) {
    if(this->root == nullptr)
        this->root = new Nodo<T>(value);
    else if(curr == nullptr)
        insertNodo(value, prev, curr);
    else if(curr->getInfo() > value)
        insertRic(value, curr, curr->getLeft());
    else 
        insertRic(value, curr, curr->getRight());
}

template <typename T>
void Abr<T>::insert(T value) {
    this->insertRic(value, nullptr, root);
}

template <typename T>
Nodo<T>* Abr<T>::findSuccessor(Nodo<T>* x) {
    if(x == nullptr)
        return nullptr;
    Nodo<T>* y = x->getParent();
    if(y == nullptr)
        return nullptr;
    else if(x == y->getLeft())
        return y;
    else   
        return findSuccessor(y);
}

template <typename T>
Nodo<T>* Abr<T>::successor(Nodo<T>* x) {
    if(x == nullptr)
        return nullptr;
    else if(x->getRight() != nullptr)
        return getMinimum(x->getRight());
    else 
        return findSuccessor(x);
}

template <typename T>
Nodo<T>* Abr<T>::findPredecessor(Nodo<T>* x) {
    if(x == nullptr)
        return nullptr;
    Nodo<T>* y = x->getParent();
    if(y == nullptr)
        return nullptr;
    else if(x == y->getRight())
        return y;
    else 
        return findPredecessor(y);
}

template <typename T>
Nodo<T>* Abr<T>::predecessor(Nodo<T>* x) {
    if(x == nullptr)
        return nullptr;
    else if(x->getLeft() != nullptr)
        return getMaximum(x->getLeft());
    else
        return findPredecessor(x);
}

template <typename T>
Nodo<T>* Abr<T>::treeSearch(Nodo<T>* x, T key) {
    if(x == nullptr || key == x->getInfo()) 
        return x;
    else if(key < x->getInfo())
        return treeSearch(x->getLeft(), key);
    else 
        return treeSearch(x->getRight(), key);
}

template <typename T>
Nodo<T>* Abr<T>::getMinimum(Nodo<T>* x) {
    if(root == nullptr)
        return nullptr;
    else if(x->getLeft() == nullptr)
        return x;
    else 
        return getMinimum(x->getLeft());
}

template <typename T>
Nodo<T>* Abr<T>::getMaximum(Nodo<T>* x) {
    if(root == nullptr)
        return nullptr;
    else if(x->getRight() == nullptr)
        return x;
    else 
        return getMaximum(x->getRight());
}

template <typename T>
void Abr<T>::transplant(Nodo<T>* x, Nodo<T>* y) {
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
void Abr<T>::treeDelete(Nodo<T>* x) {
    if(x == nullptr)
        x = nullptr;
    if(x->getLeft() == nullptr)
        transplant(x, x->getRight());
    else if(x->getRight() == nullptr)
        transplant(x, x->getLeft());
    else {
        Nodo<T>* y = successor(x);
        if(y->getParent() != x) {
            transplant(y, y->getRight());
            y->setRight(x->getRight());
            y->getRight()->setParent(y);
        }
        transplant(x, y);
        y->setLeft(x->getLeft());
        y->getLeft()->setParent(y);
    }
}

template <typename T>
void Abr<T>::visitPreOrder(Nodo<T>* x) {
    if(x != nullptr) {
        cout << x->getInfo() << "  ";
        visitPreOrder(x->getLeft());
        visitPreOrder(x->getRight());
    }
}

template <typename T>
void Abr<T>::visitInOrder(Nodo<T>* x) {
    if(x != nullptr) {
        visitPreOrder(x->getLeft());
        cout << x->getInfo() << "  ";
        visitPreOrder(x->getRight());
    }
}

template <typename T>
void Abr<T>::visitPostOrder(Nodo<T>* x) {
    if(x != nullptr) {
        visitPreOrder(x->getLeft());
        visitPreOrder(x->getRight());
        cout << x->getInfo() << "  ";
    }
}

template <typename T>
void Abr<T>::inOrderAscii(Nodo<T>* x, int spazio) {
    if(x == nullptr)
        return;
    spazio += vuoto;
    inOrderAscii(x->getRight(), spazio);
    cout << endl;
    for(int i = vuoto; i < spazio; i++) 
        cout << "  ";
    cout << x->getInfo() << endl;
    inOrderAscii(x->getLeft(), spazio);
}

template <typename T>
void Abr<T>::printAsciiTree() {
    cout << "Printing ABR: " << endl;
    inOrderAscii(root, 0);
}

#endif //ABR_H