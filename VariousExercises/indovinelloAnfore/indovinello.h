/**
 * Risolve l'indovinello: ha due attributi anfora una da 3 lt ed una
 * da 5 lt ed un metodo risolvi() che risolve l'indovinello mostrando
 * a video il contenuto delle due anfore ad ogni passo della risoluzione.
    – Es.: Riempi anfora A -> A=3 B=0
*/

#ifndef indovinello_h
#define indovinello_h
#include <iostream>
#include "contenitore.h"
#include "anfore.h"

using namespace std;

class Indovinello {
    private:
        Anfora tre, cinque;
        void printInfo();   //metodo per stampare info dell'anfora
    public:
        Indovinello();
        void risolvi();
};

Indovinello::Indovinello() : tre(3,0), cinque(5,0) {
    
}

void Indovinello::risolvi() {
    cout << "\n***1- Riempi l'Anfora da 5 litri***" << endl;
    cinque.riempiAnfora();

    printInfo();

    cout << "***2- Svuota Anfora da 5 in quella da 3***" << endl;
    cinque.spostaContenuto(tre);

    printInfo();
    
    cout << "***3- Svuota l'Anfora da 3 litri***" << endl;
    tre.svuotaAnfora();

    printInfo();

    cout << "***4- Metti i due litri rimanenti dell'Anfora da 5 in quella da 3***" << endl;
    cinque.spostaContenuto(tre);

    printInfo();

    cout << "***5- Riempi l'Anfora da 5***" << endl;
    cinque.riempiAnfora();

    printInfo();

    cout << "***6- Sposta il conenuto dell'Anfora di 5 in quella da tre***" << endl;
    cinque.spostaContenuto(tre);

    printInfo();

    cout << "Fine... Indovinello risolto!" << endl;
}

void Indovinello::printInfo() {
    cout << "Nell'Anfora Cinque ci sono " << cinque.getQt() << " litri" << endl;
    cout << "Nell'Anfora Tre ci sono " << tre.getQt() << " litri" << endl << endl;
}



#endif