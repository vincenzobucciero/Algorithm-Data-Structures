/**
 * Implemenatre un algoritmo per effettuare l'ordinamento topologico
*/

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
        Color colore;
        Vertice<T>* predecessore;

        //per ordinamento topologico, uso dfs()
        int tempoInizioVisita;
        int tempoFineVisita;
    public:
        Vertice(T value);

        void setValue(T value) { this->value = value; }
        void setColor(Color colore) { this->colore = colore; }
        void setPredecessore(Vertice<T>* predecessore) { this->predecessore = predecessore; }
        void setTempoInizioVisita(int tempoInizioVisita) { this->tempoInizioVisita = tempoInizioVisita; }
        void setTempoFineVisita(int tempoFineVisita) { this->tempoFineVisita= tempoFineVisita; }

        T getValue() { return this->value; }
        Color getColore() { return this->colore; }
        Vertice<T>* getPredecessore() { return this->predecessore; }
        int getTempoInizioVisita() { return this->tempoInizioVisita; }
        int getTempoFineVisita() { return this->tempoFineVisita; }

        friend ostream& operator<<(ostream& out, const Vertice<T>& obj) {
            string c;
            switch(obj.colore) {
                case Color::WHITE: c = "WHITE"; break;
                case Color::GRAY: c = "GRAY"; break;
                case Color::BLACK: c = "BLACK"; break;
            }
            out << "Valore ->  " << obj.value << ", Colore ->  " << c;
            return out;
        }

        friend bool operator==(const Vertice<T>& a, const Vertice<T>& b) {
            return a.value == b.value;
        }
};

template <typename T>
Vertice<T>::Vertice(T value) {
    this->value = value;
    colore = Color::WHITE;
    this->predecessore = nullptr;
    this->tempoInizioVisita = 0;
    this->tempoFineVisita = 0;
}

#endif