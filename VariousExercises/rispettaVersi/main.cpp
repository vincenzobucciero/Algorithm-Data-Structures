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

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "controllo.h"

int main() {
    string p = "Problema.txt";
    string s = "Soluzione.txt";
    string e = "Esito.txt";

    ControlloGioco controlloGioco(p,s,e);

    controlloGioco.checkSoluzione();
}