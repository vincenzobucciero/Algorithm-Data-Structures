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

#include <iostream>
#include <vector>

using namespace std;

/**
 * Ogni nodo di un ABR contiene:
    • la chiave (o key);
    • il puntatore al PADRE
    • il puntatore al FIGLIO DESTRO
    • il puntatore al FIGLIO SINISTRO
    • Eventuali dati satelliti
*/
template <typename T>
class Node {
    private:
        T key;
        Node<T>* parent;
        Node<T>* left;
        Node<T>* right;
    public:
        Node(T* key, Node<T>* parent, Node<T>* left, Node<T>* right);
        Node(T key);
        ~Node();

        void setKey(T* key) { this->key = key; }
        void setParent(Node<T>* parent) { this->parent = parent; }
        void setLeft(Node<T>* left) { this->left = left; }
        void setRight(Node<T>* right) { this->right = right; }

        T getKey() { return this->key; }
        Node<T>* getParent() { return  this->parent; }
        Node<T>* getLeft() { return this->left; }
        Node<T>* getRight() { return this->right; }
};

template <typename T>
Node<T>::Node(T* key, Node<T>* parent, Node<T>* left, Node<T>* right) {
    this->key = key;
    this->parent = parent;
    this->left = left;
    this->right = right;
}

template <typename T>
Node<T>::Node(T key) {
    this->key = key;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
Node<T>::~Node() {
    delete key;
    delete parent;
    delete left;
    delete right;
}