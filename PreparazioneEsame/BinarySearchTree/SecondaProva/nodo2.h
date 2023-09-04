#ifndef NODO2_H
#define NODO2_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Nodo2 {
    private:
        T info;
        Nodo2<T>* parent;
        Nodo2<T>* left;
        Nodo2<T>* right;
    public:
        Nodo2(T info) { this->info = info; this->parent = nullptr; this->left = nullptr; this->right = nullptr; }
        ~Nodo2() { delete info; delete parent; delete left; delete right; }

        void setInfo(T info) { this->info = info; }
        void setParent(Nodo2<T>* parent) { this->parent = parent; }
        void setLeft(Nodo2<T>* left) { this->left = left; }
        void setRight(Nodo2<T>* right) { this->right = right; }

        T getInfo() { return this->info; }
        Nodo2<T>* getParent() { return this->parent; }
        Nodo2<T>* getLeft() { return this->left; }
        Nodo2<T>* getRight() { return this->right; }
};

#endif //NODO2_H
