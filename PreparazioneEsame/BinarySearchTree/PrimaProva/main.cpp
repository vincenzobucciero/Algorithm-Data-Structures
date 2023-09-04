#include <iostream>
#include <vector>

#include "nodo.h"
#include "abr.h"

using namespace std;

int main() {
    Abr<int> myAbr;

    myAbr.insert(13);
    myAbr.insert(12);
    myAbr.insert(16);
    myAbr.insert(10);
    myAbr.insert(11);
    myAbr.insert(14);
    myAbr.insert(17);

    myAbr.printAsciiTree();

    cout << endl;

    cout << "La radice è:  " << myAbr.getRoot()->getInfo() << endl;
    cout << "Il massimo è:  " << myAbr.getMaximum(myAbr.getRoot())->getInfo() << endl;
    cout << "Il minimo è:  " << myAbr.getMinimum(myAbr.getRoot())->getInfo() << endl;

    cout << endl;
    cout << "Visita PRE-ORDER: " << endl;
    myAbr.visitPreOrder(myAbr.getRoot());

    cout << endl;
    cout << "Visita IN-ORDER: " << endl;
    myAbr.visitInOrder(myAbr.getRoot());

    cout << endl;
    cout << "Visita POST-ORDER: " << endl;
    myAbr.visitPostOrder(myAbr.getRoot());

    cout << endl << endl;

    Nodo<int>* nodo = myAbr.treeSearch(myAbr.getRoot(), 13);

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
    myAbr.visitPreOrder(myAbr.getRoot());

    cout << endl;
    cout << "Visita IN-ORDER: " << endl;
    myAbr.visitInOrder(myAbr.getRoot());

    cout << endl;
    cout << "Visita POST-ORDER: " << endl;
    myAbr.visitPostOrder(myAbr.getRoot());    

    return 0;
}