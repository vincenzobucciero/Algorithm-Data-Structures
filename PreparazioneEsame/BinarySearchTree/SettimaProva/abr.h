//
// Created by vincenzo on 04/10/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_ABR_H
#define ALGORITHM_DATA_STRUCTURES_ABR_H

#include <iostream>
#include <vector>
#include <list>

#include "nodo.h"

#define vuoto 5

template <typename T>
class Abr {
private:
    Nodo<T>* root;

    void insNodo(T value, Nodo<T>* prev, Nodo<T>* curr) {
        curr = new Nodo<T>(value);
        curr->setParent(prev);
        if(curr->getInfo() < prev->getInfo())
            prev->setLeft(curr);
        else
            prev->setRight(curr);
    }

    void insRic(T value, Nodo<T>* prev, Nodo<T>* curr) {
        if(root == nullptr)
            root = new Nodo<T>(value);
        else if(curr == nullptr)
            insNodo(value, prev, curr);
        else if(curr->getInfo() > value)
            insRic(value, curr, curr->getLeft());
        else
            insRic(value, curr, curr->getRight());
    }

    Nodo<T>* findPredecessor(Nodo<T>* x) {
        if(x == nullptr)
            return false;
        Nodo<T>* y = x->getParent();
        if(y == nullptr)
            return nullptr;
        else if(x == y->getRight())
            return y;
        else
            return findPredecessor(y);
    }

    Nodo<T>* findSuccessor(Nodo<T>* x) {
        if(x == nullptr)
            return false;
        Nodo<T>* y = x->getParent();
        if(y == nullptr)
            return nullptr;
        else if(x == y->getLeft())
            return y;
        else
            return findSuccessor(y);
    }

    void inOrderAscii(Nodo<T>* x, int spazio) {
        if(x == nullptr)
            return;
        spazio += vuoto;
        inOrderAscii(x->getRight(), spazio);
        std::cout << std::endl;
        for(int i = vuoto; i < spazio; i++)
            std::cout << "  ";
        std::cout << x->getInfo() << std::endl;
        inOrderAscii(x->getLeft(), spazio);
    }
public:
    Abr() {this->root = nullptr;}

    Nodo<T>* getRoot() {return this->root;}

    Nodo<T>* getMinimum(Nodo<T>* x) {
        if(root == nullptr)
            return nullptr;
        else if(x->getLeft() == nullptr)
            return x;
        else
            return getMinimum(x->getLeft());
    }

    Nodo<T>* getMaximum(Nodo<T>* x) {
        if(root == nullptr)
            return nullptr;
        else if(x->getRight() == nullptr)
            return x;
        else
            return getMaximum(x->getRight());
    }

    Nodo<T>* predecessor(Nodo<T>* x) {
        if()
    }
};




#endif //ALGORITHM_DATA_STRUCTURES_ABR_H
