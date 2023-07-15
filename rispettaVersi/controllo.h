/**
 * “Rispetta i versi” è un solitario giocato su una griglia
 * formata da N caselle separate da un simbolo di
 * disuguaglianza.
 * 
 * L’obiettivo del gioco è quello di riempire le celle vuote con
 * tutti i numeri da 1 a N (ogni numero deve comparire
 * esattamente una volta), in modo da rispettare le disuguaglianze tra caselle adiacenti. 
 * Per la griglia della figura, una delle possibili soluzioni al rompicapo è la seguente: 
 *
 *                  2 < 5 > 1 < 3 < 6 > 4
 * 
 * Progettare ed implementare una classe che, dati
 *      -> un file Problema.txt contenente diverse istanze del problema (una per ogni riga)
 *      -> un file Soluzione.txt contenente una soluzione per ogni istanza di problema (una per ogni riga)
 * verifichi se ognuna delle soluzione è corretta rispetto al problema e scriva l'esito su un file Esito.txt
 * 
 * Esempio:
 * <><<         1<4>2<3<5           Corretta
 * ><>><<       3>2<7>4>1<5<6       Corretta
 * >><          2>1>3<4             Sbagliata
 * <><>>        4<6>1<5>2<3         Sbagliata
*/

#ifndef controllo_h
#define controllo_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ControlloGioco {
    private:
        fstream fileProblema;
        fstream fileSoluzione;
        fstream fileEsito;

        bool simboliCorretti(string, string);
        bool numeriCorretti(string, string);
        bool checkLogica(string, string);
    public:
        ControlloGioco(string fileStringProblema, string fileStringSoluzione, string fileStringEsito);
        ~ControlloGioco();
        void checkSoluzione();
};

ControlloGioco::ControlloGioco(string fileStringProblema, string fileStringSoluzione, string fileStringEsito) {
    fileProblema.open(fileStringProblema.c_str(), ios::in);
    fileSoluzione.open(fileStringSoluzione.c_str(), ios::in);
    fileEsito.open(fileStringEsito.c_str(), ios::out);
}

ControlloGioco::~ControlloGioco() {
    fileProblema.close();
    fileSoluzione.close();
    fileEsito.close();
}

//metodo che controlla se i simboli all'interno della soluzione siano '<' o '>'
bool ControlloGioco::simboliCorretti(string problema, string soluzione) {
    string sol;
    for (int i = 0 ; i < (int)soluzione.size() ; i++) {
        if(soluzione[i] == '<' || soluzione[i] == '>')
            sol += soluzione[i];
    }
    if(sol != problema)
        return false;
    return true;
}

bool ControlloGioco::numeriCorretti(string problema, string soluzione) {
    vector<int> numeri;
    int numero;
    size_t size = 0;

    for(int i = 0; i < (int)soluzione.size(); i += size+1 ) {
        numero = stoi(soluzione.substr(i), &size);
        numeri.push_back(numero);
    }

    sort(numeri.begin(), numeri.end());

    for(int i = 0; i < (int)problema.size(); i++) {
        if(numeri.at(i) != (i+1))
            return false;
    }
    return true;
}

bool ControlloGioco::checkLogica(string problema, string soluzione){
    int num1, num2, j = 0;
    size_t size;

        num1 = stoi(soluzione.substr(0),&size);

        for(int i = 0; i < (int)problema.size(); i++) {
            j += size +1;
            num2 = stoi(soluzione.substr(j),&size);

            if((problema[i] == '>' && num1 > num2) || (problema[i] == '<' && num1 < num2)) {
                    num1 = num2;
                    continue;
                }
            return false;
        }

        return  true;
}


void ControlloGioco::checkSoluzione() {
    string p_riga, s_riga;

    while(getline(fileSoluzione, s_riga) && getline(fileProblema, p_riga)) {
        if (simboliCorretti(s_riga, p_riga)  && numeriCorretti(s_riga, p_riga) && checkLogica(s_riga, p_riga)) {
            fileEsito << "corretto" << endl; 
        } else {
            fileEsito << "falso" << endl;
        }
    }
}

#endif