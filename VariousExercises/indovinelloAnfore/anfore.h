/**
 * È un Contenitore: ha un attributo capacita che definisce la
 * capienza dell'anfora, un metodo getCapacita() che restituisce
 * questo valore, un metodo riempi() per riempirla, un metodo
 * svuota() per svuotarla, due metodi isVuota() e isPiena() che
 * restituiscono lo stato dell'anfora ed un metodo
 * spostaContenuto(Anfora) che sposta l'acqua nell'anfora passata come argomento.
*/

#ifndef Anfore_h
#define Anfore_h
#include <iostream>
#include "contenitore.h"

using namespace std;

class Anfora : public Contenitore {
    private:
        int capacita;
        bool isPiena();
        bool isVuota();
    public: 
        Anfora(int capacita, int qt);
        void riempiAnfora();
        void svuotaAnfora();
        void setCapacita(int capacita);
        int getCapacita();
        void spostaContenuto(Anfora &a);
};

Anfora::Anfora(int capacita, int qt) : Contenitore(qt) {
    this->capacita = capacita;
}

void Anfora::riempiAnfora() {
    this->versaAcqua(this->capacita - this->getQt());
}
void Anfora::svuotaAnfora() {
    this->togliAcqua(this->getQt());
}
void Anfora::setCapacita(int capacita) {
    this->capacita = capacita;
}
int Anfora::getCapacita() {
    return capacita;
}
void Anfora::spostaContenuto(Anfora &a) {
    if(this->getQt() > a.getCapacita() - a.getQt()) {
        this->togliAcqua(a.getCapacita() - a.getQt());
        a.versaAcqua(a.getCapacita() - a.getQt());
    } else if(this->getQt() <= a.getCapacita() - a.getQt()) {
        a.versaAcqua(this->getQt());
        this->togliAcqua(this->getQt());
    }
}

bool Anfora::isPiena() {
    if(this->getQt() == this->getCapacita())
        return true;
    else
        return false;
}
bool Anfora::isVuota() {
    if(this->getQt() == 0)
        return true;
    else
        return false;
}


#endif