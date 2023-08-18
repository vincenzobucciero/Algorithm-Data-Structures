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

/**
 * Esemplificazione del metodo Node<T> *BinarySearchTree<T>::maximum(Node<T>* node)
*/
template <typename T>
Node<T> *BinarySearchTree<T>::maximum() {
    return this->maximum(root);
}

/**
 * trova il nodo con la chiave minima nell'albero binario di ricerca.
 * @param node nodo in ingresso
 * @return un puntatore al nodo con la chiave minima nel sottoalbero radicato nel nodo dato.
*/
template <typename T>
Node<T> *BinarySearchTree<T>::minimum(Node<T>* node) {
    while(node->getLeft() != nullptr) {     //fin quando non trova il nodo con chiave minima
        node = node->getLeft();
    }
    return node;
}

/**
 * Esemplificazione del metodo Node<T> *BinarySearchTree<T>::minimum(Node<T>* node)
*/
template <typename T>
Node<T> *BinarySearchTree<T>::minimum() {
    return this->minimum(root);
}

/**
 * Metodo che restituisce il nodo che contiene il valore del predecessore di un dato valore key all'interno dell'albero.
 * @param key valore key per il quale stai cercando il predecessore nell'albero binario di ricerca.
 * @return y, predecessore del nodo con chiave key
*/
template <typename T>
Node<T> *BinarySearchTree<T>::predecessor(T key) {
    Node<T>* nodeTmp = this->search(key, this->getRoot());  //nodo di partenza con valore key per la ricerca del predecessore

    if(nodeTmp->getLeft() != nullptr)   //se nodo corrente ha un sottolabero sinistro
        return maximum(nodeTmp->getLeft());     //se si, trova il max del sottoalbero sinistro
    
    //se il nodo non ha figlio sinistro, allora si crea un nuovo nodo y che viene inizializzato come genitore del nodo
    Node<T>* y = nodeTmp->getParent();

    //Questo ciclo risale l'albero lungo i figli sinistri finché non si trova un genitore il cui figlio sinistro non è il nodo corrente.
    while(y != nullptr && nodeTmp == nodeTmp->getLeft()) {      //fin quando y non è nullo e nodeTmp è figlio sx di y
        nodeTmp = y;
        y = y->getParent();
    }

    return y;
}

/**
 * Metodo che restituisce il nodo che contiene il valore del successore di un dato valore key all'interno dell'albero.
 * @param key valore key per il quale stai cercando il successore nell'albero binario di ricerca.
 * @return y, successore del nodo con chiave key
*/
template <typename T>
Node<T> *BinarySearchTree<T>::successor(T key) {
    Node<T>* nodeTmp = this->search(key, this->getRoot());   //nodo di partenza con valore key per la ricerca del predecessore

    if(nodeTmp->getRight() != nullptr)      //se nodo corrente ha un sottolabero destro
        return minimum(nodeTmp->getRight());    //se si, trova il min del sottoalbero destro
    
    //se il nodo non ha figlio destro, allora si crea un nuovo nodo y che viene inizializzato come genitore del nodo
    Node<T>* y = nodeTmp->getParent();

    //Questo ciclo risale l'albero lungo i figli destri finché non si trova un genitore il cui figlio destro non è il nodo corrente.
    while(y != nullptr && nodeTmp == nodeTmp->getRight()) {     //fin quando y non è nullo e nodeTmp è figlio dx di y
        nodeTmp = y;
        y = y->getParent();
    }

    return y;
}

/**
 * Metodo che inserisce un nuovo nodo con un valore key all'interno di un albero binario di ricerca.
 * @param key valore key del nodo che si vuole inserire
 * @param prev nodo genitore al quale si vuole aggiungere il nuovo nodo
 * @param curr rappresenta il nuovo nodo che si crea e si inserisce.
*/
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

/**
 * Metodo per la sostituzione di un sottoalbero con un altro all'interno di un albero binario di ricerca.
 * @param u puntatore a nodo u che rappresenta il sottoalbero che viene rimosso
 * @param v puntatore a nodo v che rappresenta il sottoalbero che verrà messo al posto di u
*/
template <typename T>
void BinarySearchTree<T>::transplant(Node<T>* u, Node<T>* v) {
    if(u->getParent() == nullptr)   //verifico se u è radice dell'albero
        this->root = v;     //intero albero viene sostituito con quello radicato in v
    else if (u == u->getParent()->getLeft())    //verifico se u è figlio sinistro del genitore
        u->getParent()->setLeft(v);     //il figlio sx del genitore lo imposto a v
    else    //u sarà figlio dx del genitore
        u->getParent()->setRight(v);        //il figlio dx del genitore lo imposto a v

    if(v != nullptr)        //se v non è nullo
        v->setParent(u->getParent());       //il genitore di v viene impostato come genitore di u
        //Questo collega correttamente il sottoalbero radicato in v al genitore che stava originariamente 
        //sopra al sottoalbero radicato in u.
}

/**
 * Metodo che inserisce un nuovo nodo con un valore key all'interno di un albero binario di ricerca.
 * @param key valore key del nodo che si vuole inserire
 * @param prev nodo genitore al quale si vuole aggiungere il nuovo nodo
 * @param curr rappresenta il nuovo nodo che si crea e si inserisce.
*/
template <typename T>
void BinarySearchTree<T>::insert(T key, Node<T>* prev, Node<T>* curr) {
    if(this->root == nullptr)   //se albero è vuoto
        this->root = new Node<T>(key);      //key sarà la radice dell'albero
    
    if(curr == nullptr)     //se curr è nullo
        insNode(key, prev, curr);   //inserisco il nuovo nodo con valore key come figlio di prev
    else if(key > curr->getKey())       //se key è > di curr
        insert(key, curr, curr->getRight());       //inserisco il nuovo nodo nel sottolabero destro
    else 
        insert(key, curr, curr->getLeft());     //sottoalbero sinistro
}

/**
 * Esemplificazione del metodo void BinarySearchTree<T>::insert(T key, Node<T>* prev, Node<T>* curr)
*/
template <typename T>
void BinarySearchTree<T>::insert(T key) {
    this->insert(key, nullptr, this->root);
}

/**
 * Metodo che rimuove un nodo con un valore key da un albero binario di ricerca
 * @param key chiave del nodo da voler rimuovere
*/
template <typename T>
void BinarySearchTree<T>::deleteNode(T key) {
    Node<T>* nodeTmp = this->search(key, root);     //viene cercato il nodo con valore key

    if(nodeTmp != nullptr) {    //se esiste il nodo
        if(nodeTmp->getLeft() == nullptr)   //se il nodo ha un figlio sinistro nullo
            this->transplant(nodeTmp, nodeTmp->getRight());    //sostituisco il nodo con il suo figlio destro
        else if(nodeTmp->getRight() == nullptr)     //se il nodo ha un figlio destro nullo
            this->transplant(nodeTmp, nodeTmp->getLeft());  //sostituisco il nodo con il suo figlio sinistro
        else {      //se il nodo ha entrambi i figli
            Node<T>* y = this->minimum(nodeTmp->getRight());    //trovo il successore del nodo
            if(y->getParent() != nodeTmp) {     //se il genitore di y non è nodeTmp
                this->transplant(y, y->getRight());     //sostituisco y con il suo sottoalbero destro
                y->setRight(nodeTmp->getRight());   //il sottoalbero destro di y lo assegno come sottoalbero destro di nodeTmp
                y->getRight()->setParent(y);
            }

            this->transplant(nodeTmp, y);
            y->setLeft(nodeTmp->getLeft());
            y->getLeft()->setParent(y);
        }
    }
}

/**
 * Esemplificazione del metodo void BinarySearchTree<T>::preOrderView(Node<T>* node)
*/
template <typename T>
void BinarySearchTree<T>::preOrder() {
    cout << endl << "***preOrder***" << endl;
    this->preOrderView(root);
}

/**
 * Metodo che esegue una visita preOrder di un albero binario di ricerca
 * @param node puntatore al nodo dal quale far partire la ricerca
*/
template <typename T>
void BinarySearchTree<T>::preOrderView(Node<T>* node) {
    if(node == nullptr)     //se node è nullo non esisste niente da visitare
        return;
    cout << node->getKey() << " ";      //stampa del nodo corrente  
    preOrderView(node->getLeft());  //ricorsione su sottoalbero sinistro
    preOrderView(node->getRight());     //ricorsione su sottoalbero destro
}

/**
 * Esemplificazione del metodo void BinarySearchTree<T>::inOrderView(Node<T>* node)
*/
template <typename T>
void BinarySearchTree<T>::inOrder() {
    cout << endl << "***inOrder***" << endl;
    this->inOrderView(root);
}

/**
 * Metodo che esegue una visita inOrder di un albero binario di ricerca
 * @param node puntatore al nodo dal quale far partire la ricerca
*/
template <typename T>
void BinarySearchTree<T>::inOrderView(Node<T>* node) {
    if(node == nullptr)
        return;
    preOrderView(node->getLeft());
    cout << node->getKey() << " ";
    preOrderView(node->getRight());
}

/**
 * Esemplificazione del metodo void BinarySearchTree<T>::postOrderView(Node<T>* node)
*/
template <typename T>
void BinarySearchTree<T>::postOrder() {
    cout << endl << "***postOrder***" << endl;
    this->postOrderView(root);
}

/**
 * Metodo che esegue una visita inOrder di un albero binario di ricerca
 * @param node puntatore al nodo dal quale far partire la ricerca
*/
template <typename T>
void BinarySearchTree<T>::postOrderView(Node<T>* node) {
    if(node == nullptr)
        return;
    preOrderView(node->getLeft());
    preOrderView(node->getRight());
    cout << node->getKey() << " ";
}

/**
 * Metodo per la stampa grafica dell'albero
*/
template <typename T>
void BinarySearchTree<T>::printAsciiTree() {
    cout << endl << "***Binary Search Tree***" << endl;
    inOrderAscii(root,0);
}




#endif //BINARYSEARCHTREE_H