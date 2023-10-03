//
// Created by vincenzo on 03/10/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/PriorityQueue/MaxPriorityQueue/QuintaProva/maxHeap.h"
#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/PriorityQueue/MaxPriorityQueue/QuintaProva/maxPriorityQueue.h"

using namespace std;

int main() {
    MaxPriorityQueue<int> myQueue;
    ifstream input;
    string myFileInput = "fileInput.txt";
    input.open(myFileInput);

    int num;
    while(input >> num) {
        myQueue.queueInsert(num);
    }
    input.close();

    myQueue.printTree();
    //myQueue.printAsciiTree();

    cout << endl << "Max Element: -> " << myQueue.queueMaximum() << endl;
    cout << "Max Extract: -> " << myQueue.queueExtractMax() << endl;

    myQueue.printTree();

    myQueue.queueIncreaseKey(2, 41);
    cout << endl << "\n..IncreaseKey Element at index 2 with key at 41.." << endl;

    myQueue.printTree();
    myQueue.printAsciiTree();

    return 0;
}
