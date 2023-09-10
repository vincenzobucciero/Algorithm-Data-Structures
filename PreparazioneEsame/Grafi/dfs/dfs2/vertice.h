#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

enum class Color {
    WHITE, GRAY, BLACK
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

        void setValue(T Value) {this->value = value;}
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
            switch(obj.color) {
                case Color::WHITE: c = "WHITE"; break;
                case Color::GRAY: c = "GRAY"; break;
                case Color::BLACK: c = "BLACK"; break;
                default: break;
            }
            out << "Value -> " << obj.value << ", Color -> " << c << endl;
            return out;
        }

        friend bool operator==(const Vertice<T>& a, const Vertice<T>& b) {
            return a.value == b.value;
        }
};

template <typename T>
Vertice<T>::Vertice (T value) {
    this->value = value;
    this->color = Color::WHITE;
    this->predecessore = nullptr;
    this->distanza = UINT16_MAX;
    this->tInizio = 0;
    this->tFine = 0;
}


#endif 