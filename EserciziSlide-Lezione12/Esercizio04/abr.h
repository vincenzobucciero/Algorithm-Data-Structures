/**
 * Progettare un algoritmo ricorsivo che dato un ABR sommi le k chiavi più piccole
*/

#ifndef ABR_H
#define ABR_H

#include <iostream>
#include "node.h"

#define vuoto 5

using namespace std;

template <typename T>
class Abr {
    private:
        Node<T>* root = nullptr;

        void insNode(T key, Node<T>* prev, Node<T>* curr);
        void inOrderAscii(Node<T>* root, int spazio);
        void transplant(Node<T>* u, Node<T>* v);

        void preOrderView(Node<T>* node);
        void inOrderView(Node<T>* node);
        void postOrderView(Node<T>* node);
    public:
        Abr(Node<T>* root);
        Abr();
        ~Abr();

        Node<T>* getRoot() { return this->root; }

        Node<T>* search(T key, Node<T>* node);
        void search(T key);

        Node<T>* maximum(Node<T>* node);
        Node<T>* maximum();

        Node<T>* minimum(Node<T>* node);
        Node<T>* minimum();

        Node<T>* predecessor(T key);
        Node<T>* successor(T key);

        void insert(T key, Node<T>* prev, Node<T>* curr);
        void insert(T key);

        void deleteNode(T key);

        void printAsciiAbr();

        void preOrder();
        void inOrder();
        void postOrder();

        int sommaKChiaviPiccole(Abr<int>* tree, Node<int>* node, int k);
};

template <typename T>
Abr<T>::Abr(Node<T>* root) {
    this->root = root;
}

template <typename T>
Abr<T>::Abr() {
    this->root = nullptr;
}

template <typename T>
Abr<T>::~Abr() {
    delete root;
}

template <typename T>
void Abr<T>::insNode(T key, Node<T>* prev, Node<T>* curr) {
    if(prev != nullptr) {
        curr = new Node<T>(key);
        curr->setParent(prev);

        if(key > prev->getKey())
            prev->setRight(curr);
        else 
            prev->setLeft(curr);
    } else {
        curr = new Node<T>(key);
    }
}

template <typename T>
void Abr<T>::inOrderAscii(Node<T>* root, int spazio) {
    if(root == nullptr)
        return;
    spazio += vuoto;
    inOrderAscii(root->getRight(), spazio);
    cout << endl;
    for(int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << root->getKey() << endl;
    inOrderAscii(root->getLeft(), spazio);
}

template <typename T>
void Abr<T>::transplant(Node<T>* u, Node<T>* v) {
    if(u->getParent() == nullptr)
        this->root = v;
    else if(u == u->getParent()->getLeft())
        u->getParent()->setLeft(v);
    else 
        u->getParent()->setRight(v);
    
    if(v != nullptr)
        v->setParent(u->getParent());
}

template <typename T>
void Abr<T>::preOrderView(Node<T>* node) {
    if(node == nullptr)
        return;
    cout << node->getKey() << "  ";
    preOrderView(node->getLeft());
    preOrderView(node->getRight());
}

template <typename T>
void Abr<T>::inOrderView(Node<T>* node) {
    if(node == nullptr)
        return;
    inOrderView(node->getLeft());
    cout << node->getKey() << " ";
    inOrderView(node->getRight());
}

template <typename T>
void Abr<T>::postOrderView(Node<T>* node) {
    if(node == nullptr)
        return;
    postOrderView(node->getLeft());
    postOrderView(node->getRight());
    cout << node->getKey() << " ";
}

template <typename T>
Node<T> *Abr<T>::search(T key, Node<T>* node) {
    if(node == nullptr || key == node->getKey())
        return node;
    if(key < node->getKey())
        return search(key, node->getLeft());
    else
        return search(key, node->getRight());
    
    return nullptr;
}

template <typename T>
void Abr<T>::search(T key) {
    Node<T>* nodeTmp = this->search(key, this->getRoot());
    if(nodeTmp == nullptr)
        cout << "Node not found" << endl;
    else 
        cout << "Node " << key << " found" << endl;
}

template <typename T>
Node<T> *Abr<T>::maximum(Node<T>* node) {
    while(node->getRight() != nullptr) {
        node = node->getRight();
    }
    return node;
}

template <typename T>
Node<T> *Abr<T>::maximum() {
    return this->maximum(root);
}

template <typename T>
Node<T> *Abr<T>::minimum(Node<T>* node) {
    while(node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

template <typename T>
Node<T> *Abr<T>::minimum() {
    return this->minimum(root);
}

template <typename T>
Node<T> *Abr<T>::predecessor(T key) {
    Node<T>* nodeTmp = this->search(key, this->getRoot());
    if(nodeTmp->getLeft() != nullptr)
        return maximum(nodeTmp->getLeft());
    Node<T>* y = nodeTmp->getParent();

    while(y != nullptr && nodeTmp == nodeTmp->getLeft()) {
        nodeTmp = y;
        y = y->getParent();
    }

    return y;
}

template <typename T>
Node<T> *Abr<T>::successor(T key) {
    Node<T>* nodeTmp = this->search(key, this->getRoot());
    if(nodeTmp->getRight() != nullptr)
        return minimum(nodeTmp->getRight());
    Node<T>* y = nodeTmp->getParent();
    while(y != nullptr && nodeTmp == nodeTmp->getRight()) {
        nodeTmp = y;
        y = y->getParent();
    }

    return y;
}

template <typename T>
void Abr<T>::insert(T key, Node<T>* prev, Node<T>* curr) {
    if(this->root == nullptr)
        this->root = new Node<T>(key);
    if(curr == nullptr)
        insNode(key, prev, curr);
    else if(key > curr->getKey())
        insert(key, curr, curr->getRight());
    else 
        insert(key, curr, curr->getLeft());
}

template <typename T>
void Abr<T>::insert(T key) {
    this->insert(key, nullptr, this->root);
}

template <typename T>
void Abr<T>::deleteNode(T key) {
    Node<T>* nodeTmp = this->search(key, root);
    if(nodeTmp != nullptr) {
        if(nodeTmp->getLeft() == nullptr)
            this->transplant(nodeTmp, nodeTmp->getRight());
        else if(nodeTmp->getRight == nullptr)
            this->transplant(nodeTmp, nodeTmp->getLeft());
        else {
            Node<T>* y = this->minimum(nodeTmp->getRight());
            if(y->getParent() != nodeTmp) {
                this->transplant(y, y->getRight());
                y->setRight(nodeTmp->getRight());
                y->getRight()->setParent(y);
            }
            this->transplant(nodeTmp, y);
            y->setLeft(nodeTmp->getLeft());
            y->getLeft()->setParent(y);
        }
    }
}

template <typename T>
void Abr<T>::preOrder() {
    cout << "VISITA PRE-ORDER" << endl;
    this->preOrderView(root);
}

template <typename T>
void Abr<T>::inOrder() {
    cout << "VISITA IN-ORDER" << endl;
    this->inOrderView(root);
}

template <typename T>
void Abr<T>::postOrder() {
    cout << "VISITA POST-ORDER" << endl;
    this->postOrderView(root);
}

template <typename T>
void Abr<T>::printAsciiAbr() {
    cout << "Binary Search tree" << endl;
    inOrderAscii(root, 0);
}

template <typename T>
int Abr<T>::sommaKChiaviPiccole(Abr<int>* abr, Node<int>* node, int k) {
    if(node == nullptr)
        return 0;
    else if(k == 0)
        return node->getKey();
    else    
        return node->getKey() + sommaKChiaviPiccole(abr, abr->successor(node->getKey()), k-1);
}



#endif //ABR_H