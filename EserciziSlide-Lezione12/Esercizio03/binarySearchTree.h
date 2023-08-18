/**
 * Progettare un algoritmo ricorsivo che dato un ABR sommi le chiavi di tutte le foglie
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "node.h"

#define vuoto 5

using namespace std;

template <typename T>
class BinarySearchTree {
    private:
        Node<T>* root;

        void insNode(T key, Node<T>* prev, Node<T>* curr);
    public:
        BinarySearchTree(Node<T>* root);
        BinarySearchTree();
        ~BinarySearchTree();

        Node<T>* getRoot() { return this->root; }

        void insert(T key, Node<T>* prev, Node<T>* curr);
        void insert(T key);

        int sommaKFoglie(Node<T>* node);

        void inOrderAscii(Node<T>* root, int spazio);
        void printAsciiTree();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* root) {
    this->root = root;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    this->root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete root;
}

template <typename T>
void BinarySearchTree<T>::insert(T key, Node<T>* prev, Node<T>* curr) {
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
void BinarySearchTree<T>::insert(T key) {
    this->insert(key, nullptr, this->root);
}

template <typename T>
int BinarySearchTree<T>::sommaKFoglie(Node<T>* node) {
    if(node == nullptr)
        return 0;
    if(node->getLeft() == nullptr && node->getRight() == nullptr)
        return node->getKey();
    
    return sommaKFoglie(node->getLeft()) + sommaKFoglie(node->getRight());
}

template <typename T>
void BinarySearchTree<T>::inOrderAscii(Node<T>* root, int spazio) {
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
void BinarySearchTree<T>::printAsciiTree() {
    cout << endl << "***Binary Search Tree***" << endl;
    inOrderAscii(root,0);
}

template <typename T>
void BinarySearchTree<T>::insNode(T key, Node<T>* prev, Node<T>* curr) {
    if(prev != nullptr) {   //controllo se esiste un genitore
        curr = new Node<T>(key);    //creo nuovo nodo curr con valore key
        curr->setParent(prev);  //imposto prev come genitore di curr

        if(key > prev->getKey())    //se il valore di key è > di prev
            prev->setRight(curr);       //inserisci key nel sottoalbero sinistro
        else    
            prev->setLeft(curr);        //inserisco key nel sottoalbero sinistro
    } else {
        curr = new Node<T>(key);    //inserisco il nuovo nodo come radice dell'albero
    }
}

#endif //BINARYSEARCHTREE_H