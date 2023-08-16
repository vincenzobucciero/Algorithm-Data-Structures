//Counting Sort

/**
 * Il Counting sort è un algoritmo di ordinamento per valori numerici interi con complessità O(n+m), dove n è la
 * lunghezza dell'array e m è pari a max(A)-min(A)+1
 * 
 * I valori max(A) e min(A) sono rispettivamente l'elemento più grande e l'elemento più piccolo dell'array
 * 
 * Counting sort non è basato su confronti e scambi e conviene utilizzarlo quando il valore di m è piccolo rispetto a n,
 * altrimenti risulterebbero più veloci altri algoritmi
*/

/**
 * L'algoritmo conta il numero di occorrenze di ciascun valore presente nell'array da ordinare, memorizzando questa
 * informazione in un array temporaneo di dimensione pari all'intervallo di valori
 * 
 * Il numero di ripetizioni dei valori precedenti indica la posizione del valore immediatamente successivo
 * 
 * Si calcolano i valori massimo, max(A), e minimo, min(A), dell'array e si prepara un array ausiliario C di dimensione pari
 * all'intervallo dei valori con C[i] che rappresenta la frequenza dell'elemento i + min(A) nell'array di partenza A
 * 
 * Si visita l'array A aumentando l'elemento di C corrispondente
 * 
 * Infine si visita l'array C in ordine e si scrivono su A, C[i] copie del valore i + min(A)
*/


#include "countingSort.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numvar = 8;
    vector<int> vec = {100,20,40,20,12,120,220,10};

    cout << "Vettore disordinato " << endl;
    for (auto i:vec)
        cout << i << " ";
    cout << endl;
    //CountingSort::countingSort(&vec, numvar);

    CountingSort::countingSortCormen(&vec, numvar);

    /*
    cout << "Vettore ordinato con CountingSort " << endl;
    for (auto i:vec)
        cout << i << " ";
    cout << endl;
    */

    cout << "Vettore ordinato con CountingSort (versione Cormen) " << endl;
    for (auto i:vec)
        cout << i << " ";
    cout << endl;

    return 0;
}
