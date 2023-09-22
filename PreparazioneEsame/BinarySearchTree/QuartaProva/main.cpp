//
// Created by vincenzo on 22/09/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

#define vuoto 5

#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/BinarySearchTree/QuartaProva/nodo.h"
#include "/home/vincenzo/CLionProjects/Algorithm-Data-Structures/PreparazioneEsame/BinarySearchTree/QuartaProva/abr.h"

using namespace std;

int main() {
    Abr<int> myAbr;

    ifstream file;
    file.open("fileInput.txt");

    if(!file) {
        cerr << "Impossibile aprire file" << endl;
        return -1;
    }

    int num;

    while(file >> num) {
        myAbr.insert(num);
    }

    file.close();

    myAbr.printAsciitree();
}
