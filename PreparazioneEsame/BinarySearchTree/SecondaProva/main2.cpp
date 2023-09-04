#include <iostream>
#include <vector>

#include "abr2.h"
#include "nodo2.h"

using namespace std;

int main() {
    Abr2<int> myAbr;

    myAbr.insert(10);
    myAbr.insert(8);
    myAbr.insert(47);
    myAbr.insert(1);
    myAbr.insert(32);
    myAbr.insert(6);
    myAbr.insert(14);
    myAbr.insert(18);
    myAbr.insert(2);
    myAbr.insert(9);

    myAbr.printAsciiTree();

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
    Nodo2<int>* nodo = myAbr.treeSearch(myAbr.getRoot(), 14);

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