//
// Created by vincenzo on 05/10/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <string>

#include "heap.h"

using namespace std;

int main() {
    ifstream file;
    string myFileInput = "fileInput.txt";
    file.open(myFileInput);

    vector<int> numbers;
    int num;
    while(file >> num) {
        numbers.push_back(num);
    }
    file.close();

    Heap<int> myHeap(&numbers);

    myHeap.heapSort();

    myHeap.printTree();

    return 0;
}
