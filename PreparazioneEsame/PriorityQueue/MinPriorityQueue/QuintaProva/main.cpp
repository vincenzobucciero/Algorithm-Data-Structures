//
// Created by vincenzo on 03/10/23.
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
    MinPriorityQueue<int> myPriority;

    ifstream file;
    string myFileInput = "fileInput.txt";
    file.open(myFileInput);

    int num;
    while(file >> num) {
        myPriority.queueInsert(num);
    }
    file.close();

    ofstream file2;
    string myFileOutput = "fileOutput.txt";
    file2.open(myFileOutput);

    // Reindirizza l'output su outputFile invece della console
    streambuf *consoleBuffer = cout.rdbuf();     // Salva il buffer di output della console
    cout.rdbuf(file2.rdbuf());  // Reindirizza l'output su file2

    myPriority.printTree();
    myPriority.printAsciiTree();

    cout << "\nMINIMUM -> [ " << myPriority.queueMinimum() << " ]" << endl;

    myPriority.queueDecreakeKey(3, 12);
    cout << "\n..DECREASE-KEY OF ELEMENT AT INDEX 3 TO NEW KEY OF 12 [ 54 -> 12 ]" << endl;

    myPriority.printTree();
    myPriority.printAsciiTree();

    cout << "\nEXTRACT-MIN -> [ " << myPriority.queueExtractMin() << " ]" << endl;

    myPriority.printTree();
    myPriority.printAsciiTree();

    // Ripristina l'output sulla console
    cout.rdbuf(consoleBuffer);

    file2.close();

    return 0;
}
