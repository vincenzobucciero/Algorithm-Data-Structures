//
// Created by vincenzo on 22/09/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/PriorityQueue/MinPriorityQueue/TerzaProva/minHeap.h"
#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/PriorityQueue/MinPriorityQueue/TerzaProva/minPriorityQueue.h"

#define vuoto 5

using namespace std;

int main () {
    minPriorityQueue<int> myQueue;
    ifstream file;
    file.open("fileInput.txt");
    if(!file) {
        cerr << "Errore apertura file" << endl;
        return -1;
    }
    int num;
    while(file >> num) {
        myQueue.queueInsert(num);
    }
    file.close();
    myQueue.printTree();
    myQueue.printAsciiTree();

    return 0;
}
