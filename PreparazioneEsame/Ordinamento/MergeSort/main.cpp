//
// Created by vincenzo on 09/10/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

#include "mergeSort.h"

using namespace std;

int main() {
    ifstream input;
    string myFileInput = "fileInput.txt";
    ofstream output;
    string myFileOutput = "fileOutput.txt";

    input.open(myFileInput);
    output.open(myFileOutput);

    vector<int> numbers;
    int num;
    while(input >> num) {
        numbers.push_back(num);
    }
    input.close();

    MergeSort<int> vec;
    vec.mergeSortCormen(numbers, 0, numbers.size()-1);

    for(int number : numbers) {
        output << number << "  ";
    }
    output.close();

    cout << "Vettore ordinato su fileOutput.txt" << endl;

    return 0;
}
