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

#include <iostream>
#include <fstream>
#include "countingSort.h"

int main() {
    std::ifstream inputFile("fileInput.txt");  // Apri il file di input
    if (!inputFile.is_open()) {
        std::cerr << "Impossibile aprire il file di input." << std::endl;
        return 1;
    }

    std::vector<int> arr;  // Crea un vettore per memorizzare i numeri dal file

    int num;
    while (inputFile >> num) {
        arr.push_back(num);  // Leggi i numeri dal file e inseriscili nel vettore
    }

    inputFile.close();  // Chiudi il file di input

    std::cout << "Array non ordinato: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Usa countingSort
    std::vector<int> arr1 = arr;  // Copia l'array per conservare l'originale
    CountingSort::countingSort(&arr1);
    std::cout << "Array ordinato usando countingSort: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Usa countingSortCormen
    std::vector<int> arr2 = arr;  // Copia l'array per conservare l'originale
    CountingSort::countingSortCormen(&arr2);
    std::cout << "Array ordinato usando countingSortCormen: ";
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
