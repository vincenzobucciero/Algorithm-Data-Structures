/**
 * Implementazione della visita in Ampiezza (BFS) di un Grafo Orientato
*/

#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>

using namespace std;

//Classe enumerazione per rappresentare i colori che assumeranno i vertici del grafo durante la visita BFS
enum class Color {
    WHITE, GRAY, BLACK
};

/**
 * Rappresenta un vertice all'interno del grafo orientato
*/
template <typename T>
class Vertice {
    private:
        T value;    //valore del vertice
        Color colore;   //colore vertice durante la visita
        Vertice<T>* predecessore;   //puntatore al predecessore di un vertice nell'albero BF che viene costruito

        int distanza;   //distanza del vertice dalla sorgente durante la visita 
    public:
        Vertice(T value);

        //metodi setter
        void setValue(T value) { this->value = value; }
        void setColore(Color colore) { this->colore = colore; }
        void setPredecessore(Vertice<T>* predecessore) { this->predecessore = predecessore; }
        void setDistanza(int distanza) { this->distanza = distanza; }

        //metodi getter
        T getValue() { return this->value; }
        Color getColore() { return this->colore; }
        Vertice<T>* getPredecessore() { return this->predecessore; }
        int getDistanza() { return this->distanza; }

        //Overload ell'operatore di sovraccarico <<
        //Dichiarata come funzione friend, in questo modo permette alla funzione di accedere 
        //ai membri privati della classe "Vertice"
        friend ostream& operator<<(ostream& out, const Vertice<T>& obj) {

            string c;

            //switch-case per determinare il colore del vertice. A seconda del colore del vertice, 
            //viene assegnato un valore corrispondente alla stringa c.
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

            cout << "Valore -> " << obj.value << " , Colore -> " << c << endl;

            return out;
        }

        //Overload ell'operatore di confronto ==
        //Dichiarata come funzione friend, in questo modo permette alla funzione di accedere 
        //ai membri privati della classe "Vertice"
        friend bool operator==(const Vertice<T>& a, const Vertice<T>& b) {

            //confronto tra due valori oggetti Vertice
            return a.value == b.value;
        }
};

/**
 * Costruttore che inizializza un vertice con il valore specificato
 * @param value valore del vertice
*/
template <typename T>
Vertice<T>::Vertice(T value) {
    this->value = value;
    this->colore = Color::WHITE;
    this->predecessore = nullptr;
    this->distanza = UINT16_MAX;
}

#endif //VERTICE_H