#ifndef CHECKERSOLUTION_H
#define CHECKERSOLUTION_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Checker {
    private:
        //Dichiaro file solo in lettura
        fstream myFile;
        //Utilizzo del vector come contenitore per rappresentare una matrice (STL)
        vector<int> myMatrix;

        void getMyMatrix();

    public:
        Checker(string myFile);
        ~Checker();

        //metodo che controlla se ci siano i numeri
        bool isValid();
};

Checker::Checker(string myStringFile) {
    myStringFile.open(myFile.c_str(), ios::in);
}

#endif