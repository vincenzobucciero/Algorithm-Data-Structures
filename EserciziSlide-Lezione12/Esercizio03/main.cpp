/**
 * Progettare un algoritmo ricorsivo che dato un ABR sommi le chiavi di tutte le foglie
*/


#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main() {

    BinarySearchTree<int> myABR;

    myABR.insert(26);
    myABR.insert(33);
    myABR.insert(42);
    myABR.insert(46);
    myABR.insert(10);
    myABR.insert(1);
    myABR.insert(6);
    myABR.insert(9);
    myABR.insert(16);
    myABR.insert(7);
    myABR.insert(89);
    myABR.insert(10);

    myABR.printAsciiTree();

    cout << endl;
    cout << "La somma delle k foglie è: [ " << myABR.sommaKFoglie(myABR.getRoot()) << " ]" << endl;

    return 0;
}