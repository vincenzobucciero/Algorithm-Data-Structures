#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>

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
    int tInizioVis;
    int tFineVis;
public:
    Vertice(T value);

    void setValue(T value) {this->value = value;}
    T getValue() {return this->value;}

    void setColor(Color color) {this->color = color;}
    Color getColor() {return this->color;}

    void setPredecessore(Vertice<T>* predecessore) {this->predecessore = predecessore;}
    Vertice<T>* getPredecessore() {return this->predecessore;}

    void setDistanza(int distanza) {this->distanza = distanza;}
    int getDistanza() {return this->distanza;}

    void setTInizioVis(int tInizioVis) {this->tInizioVis = tInizioVis;}
    int getTInizioVis() {return this->tInizioVis;}

    void setTFineVis(int tFineVis) {this->tFineVis = tFineVis;}
    int getTFineVis() {return this->tFineVis;}

    friend ostream& operator<<(ostream& out, const Vertice<T>& obj) {
        string c;
        switch(obj.color) {
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
    this->tInizioVis = 0;
    this->tFineVis = 0;
}



#endif