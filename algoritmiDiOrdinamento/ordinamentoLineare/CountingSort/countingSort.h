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

#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <iostream>
#include <vector>

using namespace std;

class CountingSort {
    public:
        static void countingSort(vector<int>* arr);  //static cosi non bisogna creare un oggetto countingsort
        static void countingSortCormen(vector<int>* arr);
};

void CountingSort::countingSort(vector<int>* arr) {
    int min = arr->at(0);   //definisco minimo
    int max = arr->at(0);   //definisco massimo

    for(int i = 1; i < arr->size(); i++) {
        if(arr->at(i) > max) {
            max = arr->at(i);
        } else if (arr->at(i) < min) {
            min = arr->at(i);
        }
    }

    int *arrC = new int[max-min+1];

    for(int i = 0; i < max-min+1; i++) {
        arrC[i] = 0;
    }

    for(int i : *arr) {
        arrC[i - min] = arrC[i - min] + 1;
    }

    int k = 0;

    for(int i = 0; i < max-min+1; i++) {
        while(arrC[i] > 0) {
            arr->at(k) = i + min;
            k++;
            arrC[i] = arrC[i] - 1;
        }
    }

    delete [] arrC;
}

void CountingSort::countingSortCormen(vector<int>* arr) {
    int min = arr->at(0);   //definisco minimo
    int max = arr->at(0);   //definisco massimo

    for(int i = 1; i < arr->size(); i++) {
        if(arr->at(i) > max) {
            max = arr->at(i);
        } else if (arr->at(i) < min) {
            min = arr->at(i);
        }
    }

    int *arrC = new int[max-min+1];

    for(int i = 0; i < max-min+1; i++) {
        arrC[i] = 0;
    }

    for(int i : *arr) {
        arrC[i - min]++;
    }    

    for (int i = 1; i < max-min+1; i++) {
        arrC[i] += arrC[i-1];
    }

    int *arrB = new int[arr->size()];

    for (int i = arr->size()-1; i >= 0; i--){
        arrB[arrC[arr->at(i) - min] - 1] = arr->at(i);
        arrC[arr->at(i) - min]--;
    }

    for (int i = 0; i < arr->size(); i++)
        arr->at(i) = arrB[i];
}



#endif //COUNTINGSORT_H