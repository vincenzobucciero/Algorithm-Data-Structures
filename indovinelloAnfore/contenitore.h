/**
 * Generico contenitore d'acqua: ha un attributo qt che memorizza 
 * la quantità d'acqua, un metodo versa(lt) per versare acqua, un
 * metodo togli(lt) per togliere acqua ed un metodo getQt() che
 * restituisce il valore di qt.
*/

#ifndef Contenitore_h
#define Contenitore_h
#include <iostream>
using namespace std;

class Contenitore {
    private:
        int qt;
    public:
        Contenitore(int qt);
        //~Contenitore();   invocazione del distruttore
        void versaAcqua(int lt);
        void togliAcqua(int lt);
        void setQt(int qt);
        int getQt();
};

Contenitore::Contenitore(int qt) {
    this->qt = qt;
}

void Contenitore::versaAcqua(int lt) {
    this->qt = qt + lt;
}
void Contenitore::togliAcqua(int lt) {
    this->qt = qt - lt;
}

void Contenitore::setQt(int qt) {
    this->qt = qt;
}

int Contenitore::getQt() {
    return qt;
}


#endif