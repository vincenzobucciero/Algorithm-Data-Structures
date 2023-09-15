#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>

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
        int tempoInizioVisita;
        int tempoFineVisita;
    public:
        Vertice(T value);

        void setValue(T value) {this->value = value;}
        void setColor(Color color) {this->color = color;}
        void setPredecessore(Vertice<T>* vertice) {this->predecessore = predecessore;}
        void setDistanza(int distanza) {this->distanza = distanza;}
        void setTempoInizioVisita(int tempoInizioVisita) {this->tempoInizioVisita = tempoInizioVisita;}
        void setTempoFineVisita (int tempoFineVisita) {this->tempoFineVisita = tempoFineVisita;}

        T getValue() {return this->value;}
        Color getColor() {return this->color;}
        Vertice<T>* getPredecessore() {return this->predecessore;}
        int getDistanza() {return this->distanza;}
        int getTempoInizioVisita() {return this->tempoInizioVisita;}
        int getTempoFineVisita() {return this->tempoFineVisita;}

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
    this->predecessore = nullptr;
    this->color = Color::white;
    this->distanza = UINT16_MAX;
    this->tempoInizioVisita = 0;
    this->tempoFineVisita = 0;
}


#endif