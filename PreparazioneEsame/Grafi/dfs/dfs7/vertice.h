//
// Created by vincenzo on 01/10/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_VERTICE_H
#define ALGORITHM_DATA_STRUCTURES_VERTICE_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

enum class Color {
    white, gray, black
};

template <typename T>
class Vertice {
private:
    T value;
    Color color;
    Vertice<T>* predecessore;
    int distanza;
    int tInizio;
    int tFine;
public:
    Vertice(T value);

    void setValue(T value) {this->value = value;}
    void setColor(Color color) {this->color = color;}
    void setPredecessore(Vertice<T>* predecessore) {this->predecessore = predecessore;}
    void setDistanza(int distanza) {this->distanza = distanza;}
    void setTInizio(int tInizio) {this->tInizio = tInizio;}
    void setTFine(int tFine) {this->tFine = tFine;}

    T getValue() {return this->value;}
    Color getColor() {return this->color;}
    Vertice<T>* getPredecessore() {return this->predecessore;}
    int getDistanza() {return this->distanza;}
    int getTInizio() {return this->tInizio;}
    int getTFine() {return this->tFine;}

    friend ostream& operator<<(ostream& out, const Vertice<T>& obj) {
        string c;
        switch (obj.color) {
            case Color::white: c = "white"; break;
            case Color::gray: c = "gray"; break;
            case Color::black: c = "black"; break;
            default: break;
        }
        out << "value -> " << obj.value << ", color -> " << c << endl;
        return out;
    }
    friend bool operator==(const Vertice<T>& v1, const Vertice<T>& v2) {
        return v1.value == v2.value;
    }
};

template <typename T>
Vertice<T>::Vertice(T value) {
    this->value = value;
    this->color = Color::white;
    this->predecessore = nullptr;
    this->distanza = UINT16_MAX;
    this->tInizio = 0;
    this->tFine = 0;
}

#endif //ALGORITHM_DATA_STRUCTURES_VERTICE_H
