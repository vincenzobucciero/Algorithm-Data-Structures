/**
 * Progettare una classe BinarySearchTree che implementi un albero binario di ricerca con le seguenti funzioni
        • SEARCH
        • MINIMUM
        • MAXIMUM
        • PREDECESSOR
        • SUCCESSOR
        • INSERT
        • DELETE
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <vector>

#include "node.h"

#define vuoto 5

using namespace std;

template <typename T>
class BinarySearchTree {
    private:
        Node<T>* root;

        void insNode(T key, Node<T>* prev, Node<T>* curr);
        void inOrderAscii(Node<T>* root, int spazio);
        void transplant(Node<T>* u, Node<T>* v);

        //visit
        void preOrderView(Node<T>* node);
        void inOrderView(Node<T>* node);
        void postOrderView(Node<T>* node);

    public:
        BinarySearchTree();
        BinarySearchTree(Node<T>* root);
        ~BinarySearchTree();

        Node<T>* search(T key, Node<T>* node);
        void search(T key);

        Node<T>* maximum(Node<T>* node);
        Node<T>* maximum();

        Node<T>* minimum(Node<T>* node);
        Node<T>* minimum();

        //Node<T>* predecessor(Node<T>* node);
        Node<T>* predecessor(T key);

        //Node<T>* successor(Node<T>* node);
        Node<T>* successor(T key);

        void insert(T key, Node<T>* prev, Node<T>* curr);
        void insert(T key);

        void deleteNode(T key);

        void printAsciiTree();      //stampa dell albero

        //visit
        void preOrder();
        void inOrder();
        void postOrder();

        Node<T>* getRoot() { return this->root; }
};

/**
 * Costruttore di default
 * Crea albero binario vuoto
 * Esempio nel main -> BinarySearchTree<int> myTree;
*/
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    this->root = nullptr;
}

/**
 * Crea albero binario con radice specifica
 * Esempio nel main -> NodoAbr<int>* rootNode = new NodoAbr<int>(10);
*/
template <typename T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* root) {
    this->root = root;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    
}

/**
 * effettua una ricerca ricorsiva nell'albero binario di ricerca a partire dal nodo fornito. 
 * Se trova un nodo con la chiave corrispondente, restituisce quel nodo. Altrimenti, naviga nel sottoalbero 
 * sinistro o destro a seconda della relazione tra la chiave cercata e la chiave del nodo corrente.
 * @param key chiave k da cercare
 * @param node puntatore x alla radice dell'albero
 * @return puntatore al nodo con chiave k se esiste
*/
template <typename T>
Node<T> *BinarySearchTree<T>::search(T key, Node<T>* node) {
    if(node == nullptr || key == node->getKey())
        return node;
    if(key < node->getKey())
        return search(key, node->getLeft());
    else 
        return search(key, node->getRight());
    
    return nullptr;
}

/**
 * Metodo pubblico che utilizza il metodo provato search.
 * Si usa per ricercare un nodo con una data chiave all’ interno di un ABR
 * @param key chiave k da cercare
*/
template <typename T>
void BinarySearchTree<T>::search(T key) {
    //si esegue la ricerca utilizzando il metodo privato search. 
    //si passa la chiave da cercare (key) e il nodo radice (this->getRoot()) come punto di partenza 
    //per la ricerca. Il risultato della ricerca sarà assegnato a nodeTmp.
    Node<T>* nodeTmp = this->search(key, this->getRoot());

    if(nodeTmp == nullptr)
        cout << "Node not find!!" <<  endl;
    else 
        cout << "Node [" << key << "] find: " << nodeTmp->getKey() << endl; 
}

/**
 * trova il nodo con la chiave massima nell'albero binario di ricerca.
 * @param node nodo in ingresso
 * @return un puntatore al nodo con la chiave massima nel sottoalbero radicato nel nodo dato.
*/
template <typename T>
Node<T> *BinarySearchTree<T>::maximum(Node<T>* node) {
    while(node->getRight() != nullptr) {    //fin quando non trova il nodo con chiave massima
        node = node->getRight();
    }
    return node;
}

template <typename T>
Node<T> *BinarySearchTree<T>::maximum() {
    return this->maximum(root);
}

template <typename T>
Node<T> *BinarySearchTree<T>::minimum(Node<T>* node) {
    while(node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

template <typename T>
Node<T> *BinarySearchTree<T>::minimum() {
    return this->minimum(root);
}

template <typename T>
Node<T> *BinarySearchTree<T>::predecessor(T key) {
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
Node<T> *BinarySearchTree<T>::successor(T key) {
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
void BinarySearchTree<T>::insNode(T key, Node<T>* prev, Node<T>* curr) {
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
void BinarySearchTree<T>::transplant(Node<T>* u, Node<T>* v) {
    if(u->getParent() == nullptr)
        this->root = v;
    else if (u == u->getParent()->getLeft())
        u->getParent()->setLeft(v);
    else
        u->getParent()->setRight(v);

    if(v != nullptr)
        v->setParent(u->getParent());
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
void BinarySearchTree<T>::deleteNode(T key) {
    Node<T>* nodeTmp = this->search(key, root);

    if(nodeTmp != nullptr) {
        if(nodeTmp->getLeft() == nullptr)
            this->transplant(nodeTmp, nodeTmp->getRight());
        else if(nodeTmp->getRight() == nullptr)
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
void BinarySearchTree<T>::preOrder() {
    cout << endl << "***preOrder***" << endl;
    this->preOrderView(root);
}

template <typename T>
void BinarySearchTree<T>::preOrderView(Node<T>* node) {
    if(node == nullptr)
        return;
    cout << node->getKey() << " ";
    preOrderView(node->getLeft());
    preOrderView(node->getRight());
}

template <typename T>
void BinarySearchTree<T>::inOrder() {
    cout << endl << "***inOrder***" << endl;
    this->inOrderView(root);
}

template <typename T>
void BinarySearchTree<T>::inOrderView(Node<T>* node) {
    if(node == nullptr)
        return;
    preOrderView(node->getLeft());
    cout << node->getKey() << " ";
    preOrderView(node->getRight());
}

template <typename T>
void BinarySearchTree<T>::postOrder() {
    cout << endl << "***postOrder***" << endl;
    this->postOrderView(root);
}

template <typename T>
void BinarySearchTree<T>::postOrderView(Node<T>* node) {
    if(node == nullptr)
        return;
    preOrderView(node->getLeft());
    preOrderView(node->getRight());
    cout << node->getKey() << " ";
}

template <typename T>
void BinarySearchTree<T>::printAsciiTree() {
    cout << endl << "***Binary Search Tree***" << endl;
    inOrderAscii(root,0);
}




#endif //BINARYSEARCHTREE_H