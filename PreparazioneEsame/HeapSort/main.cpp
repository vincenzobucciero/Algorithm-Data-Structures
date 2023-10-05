/*
    • Utilizzando il paradigma della programmazione ad oggetti ed il linguaggio C++ 11, progettare ed
    implementare, come classe, una struttura dati max-heap che consenta di ordinare, mediante algoritmo heapsort,
    un insieme di valori numerici letti dal file heap.txt
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "heapSort.h"

using namespace std;

int main() {
    string heap = "heap.txt";
    fstream myFile;
    string file;
    vector<int> vec;

    myFile.open(heap.c_str(), ios::in);

    while(getline(myFile, file)) {
        vec.push_back(stof(file));  //stof converte stringhe in numeri
    }

    for(auto i : vec)
        cout << i << endl;
    
    cout<<endl<<"File ordinato: "<<endl;
    HeapSort<int> tree = HeapSort<int>(vec);
    tree.heapSortMethod();
    tree.printTree();
    //tree.printAsciiTree();

    myFile.close();


    return 0;
}