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

#include "binarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree<int>* myTree = new BinarySearchTree<int>;

    myTree->insert(10);
    myTree->insert(20);
    myTree->insert(2);
    myTree->insert(4);
    myTree->insert(60);
    myTree->insert(222);
    myTree->insert(40);
    myTree->insert(62);

    myTree->printAsciiTree();

    myTree->search(40);
    myTree->search(2);
    myTree->search(600);

    cout << "Minimo: " << myTree->minimum()->getKey() << endl;
    cout << "Massimo: " << myTree->maximum()->getKey() << endl;
    cout << "Predecessor di 4: " << myTree->predecessor(4)->getKey() << endl;
    cout << "Successor di 40: " << myTree->successor(40)->getKey() << endl;

    myTree->inOrder();
    myTree->preOrder();
    myTree->postOrder();

    myTree->deleteNode(40);
    myTree->deleteNode(62);
    myTree->deleteNode(222);
    myTree->deleteNode(10);
    myTree->printAsciiTree();

    return 0;
}