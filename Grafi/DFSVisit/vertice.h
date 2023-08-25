/**
 * Implementazione della visità in profondità DFS in un grafo orientato
*/

#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>

using namespace std;

/**
 * Classe enumerazione per indicare i colori che posso assumere i vertici durante la visita DFS
*/
enum class Color {
    WHITE, GRAY, BLACK
};

template <typename T>
class Vertice {
    private:
        T value;        //valore del vertice
        Color colore;       //colore che assume
        Vertice<T>* predecessore;       //puntatore al predecessore del vertice
        int distanza;       //distanza del vertice dalla sorgente

        int t_inizio;       //tempo di inizio visita
        int t_fine;         //tempo di fine visita

    public:
        Vertice(T value);

        //metodi setter
        void setValue(T value) { this->value = value; }
        void setColor(Color colore) { this->colore = colore; }
        void setPredecessore(Vertice<T>* predecessore) { this->predecessore = predecessore; }
        void setDistanza(int distanza) { this->distanza = distanza; }

        //metodi getter
        T getValue() { return this->value; }
        Color getColor() { return this->colore; }
        Vertice<T>* getPredecessore() { return this->predecessore; }
        int getDistanza() { return this->distanza; }

        void setT_inizio(int t_inizio) { this->t_inizio = t_inizio; }
        void setT_fine(int t_fine) { this->t_fine = t_fine; }
        int getT_inizio() { return this->t_inizio; }
        int getT_fine() { return this->t_fine; }

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

            out << "Valore -> " << obj.value << ", Colore -> " << c;

            return out;
        }

        friend bool operator== (const Vertice<T>& a, const Vertice<T>& b) {
            return a.value == b.value;
        }
};

template <typename T>
Vertice<T>::Vertice(T value) {
    this->value = value;
    colore = Color::WHITE;
    this->predecessore = nullptr;
    this->distanza = UINT16_MAX;
    
    this->t_inizio = 0;
    this->t_fine = 0;
}



#endif //VERTICE_H