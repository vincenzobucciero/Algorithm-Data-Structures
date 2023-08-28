/**
 * • Implementare una struttura per insiemi disgiunti
 * • Implementare l'algoritmo per trovare le componenti connesse
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
        Vertice<T>* rappresentante;

        int key;
        int rank;
        int tempoInizioVisita;
        int tempoFineVisita;
    public:
        Vertice(T value);
        //~Vertice();
        void setValue(T value) { this->value = value; }
        void setColor(Color colore) { this->colore = colore; }
        void setPredecessore(Vertice<T>* predecessore) { this->predecessore = predecessore; }
        void setRappresentante(Vertice<T>* rappresentante) { this->rappresentante = rappresentante; }
        void setKey(int key) { this->key = key; }
        void setRank(int rank) { this->rank = rank; }
        void setTempoInizioVisita(int tempoInizioVisita) { this->tempoInizioVisita = tempoInizioVisita; }
        void setTempoFineVisita(int tempoFineVisita) { this->tempoFineVisita = tempoFineVisita; }

        T getValue() { return this->value; }
        Color getColor() { return this->colore; }
        Vertice<T>* getPredecessore() { return this->predecessore; }
        Vertice<T>* getRappresentante() { return this->rappresentante; }
        int getKey() { return this->key; }
        int getRank() { return this->rank; }
        int getTempoInizioVisita() { return this->tempoInizioVisita; }
        int getTempoFineVisita() { return this->tempoFineVisita; }

        friend ostream& operator<<(ostream& out, const Vertice<T>& obj) {
            string c;
            switch(obj.colore) {
                case Color::WHITE:
                    c = "WHITE";
                    break;
                case Color::GRAY:
                    c = "GRAY";
                    break;
                case Color::BLACK:
                    c = "BLACK";
                    break;
                default:
                    break;
            }
            out << "Valore -> " << obj.value << " Colore -> " << c;

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
    this->key = UINT16_MAX;
    this->rank = 0;
    this->rappresentante = nullptr;
}


#endif //VERTICE_H