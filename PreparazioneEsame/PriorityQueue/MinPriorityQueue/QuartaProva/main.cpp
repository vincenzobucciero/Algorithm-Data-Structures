//
// Created by vincenzo on 26/09/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include "minHeap.h"
#include "minPriorityQueue.h"

using namespace std;

int main() {
    minPriorityQueue<int> myQueue;
    ifstream myFile("fileInput.txt");
    if(!myFile) {
        cerr << "Errore apertura file" << endl;
        return -1;
    }
    int num;
    while(myFile >> num) {
        myQueue.queueInsert(num);
    }
    myFile.close();
    myQueue.printTree();
    cout << endl;
    myQueue.printAsciiTree();
}