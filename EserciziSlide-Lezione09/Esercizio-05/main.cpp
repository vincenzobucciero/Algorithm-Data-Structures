/**
 * Progettare ed implementare un algoritmo ricorsivo che dato 
 * un array verifichi se rappresenta un [min, max]-heap binario
*/

#include <iostream>
#include <vector>

#include "isHeap.h"

using namespace std;

int main() {
    vector<int> tree {1,2,3,4,5,6,7,8,9};       //is MinHeap
    IsHeap<int> myTree;

    myTree.print(tree, tree.size(), 0);

    return 0;
}