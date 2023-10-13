#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

#include "quickSort.h"

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

    QuickSort<int> myVec;
    myVec.quickSort(numbers, 0, numbers.size()-1);

    for(int i = 0; i < numbers.size()-1; i++) {
        output << numbers[i] << "  ";
    }
    output.close();

    cout << "Vettore ordinato su fileOutput.txt" << endl;

    return 0;
}