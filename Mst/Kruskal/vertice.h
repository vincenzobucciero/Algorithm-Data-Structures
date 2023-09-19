/**
 * Implementazione dell'algoritmo di Kruskal (Minimum Spanning Tree)
*/

#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>

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
        int rank;

        int peso; //per implementazione kruskal

    public:
        Vertice(T value) { this->value = value; color = Color::WHITE; this->predecessore = nullptr; this->peso = 0; }

        void setValue(T value) { this->value = value; }
        void setColor(Color color) { this->color = color; }
        void setPredecessor(Vertice<T>* predecessore) { this->predecessore = predecessore; }
        void setPeso(int peso) {this->peso = peso;}
        void setRank(int rank) { this->rank = rank; }

        T getValue() { return this->value; }
        Color getColor() { return this->color; }
        Vertice<T>* getPredecessore() { return this->predecessore; }
        int getPeso() {return this->peso;}
        int getRank() { return this->rank; }

        friend ostream& operator<<(ostream& out, const Vertice<T>& obj) {
            string c;
            switch(obj.color) {
                case Color::WHITE: c = "WHITE"; break;
                case Color::GRAY: c = "GRAY"; break;
                case Color::BLACK: c = "BLACK"; break;
                default: break;
            }
            out << "Valore -> " << obj.value << ", Colore -> " << c;
            return out;
        }

        friend bool operator==(const Vertice<T>& a, const Vertice<T>& b) {
            return a.value == b.value;
        }
};



#endif //VERTICE_H