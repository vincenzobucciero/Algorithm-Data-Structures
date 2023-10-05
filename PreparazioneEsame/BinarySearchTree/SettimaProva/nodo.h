//
// Created by vincenzo on 04/10/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_NODO_H
#define ALGORITHM_DATA_STRUCTURES_NODO_H

#include <iostream>
#include <vector>
#include <list>

template <typename T>
class Nodo {
private:
    T info;
    Nodo<T>* parent;
    Nodo<T>* left;
    Nodo<T>* right;
public:
    Nodo(T info) {
        this->info = info;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
    void setInfo(T info) {this->info = info;}
    T getInfo() {return this->info;}
    void setParent(Nodo<T>* parent) {this->parent = parent;}
    Nodo<T>* getParent() {return this->parent;}
    void setLeft(Nodo<T>* left) {this->left = left;}
    Nodo<T>* getLeft() {return this->left;}
    void setRight(Nodo<T>* right) {this->right = right;}
    Nodo<T>* getRight() {return this->right;}
};


#endif //ALGORITHM_DATA_STRUCTURES_NODO_H
