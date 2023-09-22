//
// Created by vincenzo on 22/09/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_VERTICE_H
#define ALGORITHM_DATA_STRUCTURES_VERTICE_H

#include <iostream>
#include <vector>
#include <list>
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
    int distanza{};
public:
    Vertice(T value);
    void setValue(T value) {this->value = value;}
    void setColor(Color color) {this->color = color;}
    void setPredecessore(Vertice<T>* predecessore) {this->predecessore = predecessore;}
    void setDistanza(int distanza) {this->distanza = distanza;}
    T getValue() {return this->value;}
    Color getColor() {return this->color;}
    Vertice<T>* getPredecessore() {return this->predecessore;}
    int getDistanza() {return this->distanza;}

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

    friend bool operator==(const Vertice<T>& a, const Vertice<T>& b) {
        return a.value == b.value;
    }
};

template <typename T>
Vertice<T>::Vertice(T value) {
    this->value = value;
    this->color = Color::white;
    this->predecessore = nullptr;
    this->distanza = UINT16_MAX;
}

#endif //ALGORITHM_DATA_STRUCTURES_VERTICE_H
