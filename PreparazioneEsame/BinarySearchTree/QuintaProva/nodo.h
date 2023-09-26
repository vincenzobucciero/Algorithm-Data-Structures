//
// Created by vincenzo on 25/09/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_NODO_H
#define ALGORITHM_DATA_STRUCTURES_NODO_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T>
class Nodo {
private:
    T info;
    Nodo<T>* parent;
    Nodo<T>* left;
    Nodo<T>* right;
public:
    Nodo(T info);
    void setInfo() {this->info = info;}
    void setParent(Nodo<T>* parent) {this->parent = parent;}
    void setLeft(Nodo<T>* left) {this->left = left;}
    void setRight(Nodo<T>* right) {this->right = right;}
    T getInfo() {return this->info;}
    Nodo<T>* getParent() {return this->parent;}
    Nodo<T>* getLeft() {return this->left;}
    Nodo<T>* getRight() {return this->right;}
};

template <typename T>
Nodo<T>::Nodo(T info) {
    this->info = info;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

#endif //ALGORITHM_DATA_STRUCTURES_NODO_H
