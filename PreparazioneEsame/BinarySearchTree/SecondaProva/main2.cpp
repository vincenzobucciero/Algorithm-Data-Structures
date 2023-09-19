#include <iostream>
#include <vector>

#include "abr2.h"
#include "nodo2.h"

using namespace std;

int main() {
    Abr2<int> myAbr;

    myAbr.insert(10); // Nodo radice
    myAbr.insert(5);  // Nodo 5
    myAbr.insert(15); // Nodo 15
    myAbr.insert(3);  // Nodo 3
    myAbr.insert(7);  // Nodo 7

    myAbr.printAsciiTree();

    if (myAbr.isRedBlackTree(myAbr.getRoot())) {
        cout << "L'albero è un albero rosso-nero." << endl;
    } else {
        cout << "L'albero non è un albero rosso-nero." << endl;
    }

    cout << "L'elemento radice è:  " << myAbr.getRoot()->getInfo() << endl;
    cout << "L'elemento massimo è:  " << myAbr.getMaximum(myAbr.getRoot())->getInfo() << endl;
    cout << "L'elemento minimo è:  " << myAbr.getMinimum(myAbr.getRoot())->getInfo() << endl;

    cout << "VISITA PRE-ORDER" << endl;
    myAbr.preOrderVisit(myAbr.getRoot());

    cout << endl;
    cout << "VISITA IN-ORDER" << endl;
    myAbr.inOrderVisit(myAbr.getRoot());

    cout << endl;
    cout << "VISITA POST-ORDER" << endl;
    myAbr.postOrderVisit(myAbr.getRoot());

    cout << endl;
    Nodo2<int>* nodo = myAbr.treeSearch(myAbr.getRoot(), 7);

    cout << "Il successore nell'ABR di [" << nodo->getInfo() << "] è:  " << myAbr.successor(nodo)->getInfo() << endl;
    cout << "Il predecessore nell'ABR di [" << nodo->getInfo() << "] è:  " << myAbr.predecessor(nodo)->getInfo() << endl;

    cout << "Elimino il nodo [" << nodo->getInfo() << "] .. " << endl;
    
    myAbr.treeDelete(nodo);

    myAbr.printAsciiTree();

    cout << "La radice è:  " << myAbr.getRoot()->getInfo() << endl;
    cout << "Il massimo è:  " << myAbr.getMaximum(myAbr.getRoot())->getInfo() << endl;
    cout << "Il minimo è:  " << myAbr.getMinimum(myAbr.getRoot())->getInfo() << endl;

    cout << endl;
    cout << "Visita PRE-ORDER: " << endl;
    myAbr.preOrderVisit(myAbr.getRoot());

    cout << endl;
    cout << "Visita IN-ORDER: " << endl;
    myAbr.inOrderVisit(myAbr.getRoot());

    cout << endl;
    cout << "Visita POST-ORDER: " << endl;
    myAbr.postOrderVisit(myAbr.getRoot());

    return 0;
}