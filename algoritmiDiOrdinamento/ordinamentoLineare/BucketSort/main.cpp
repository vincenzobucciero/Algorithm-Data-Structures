/**
 * Bucket sort o bin sort è un algoritmo di ordinamento il cui funzionamento consiste nel suddividere 
 * un array in un numero finito di buckets
 * 
 * Ciascun bucket è ordinato individualmente o utilizzando un algoritmo di ordinamento differente od applicando
 * ricorsivamente il bucket sort
 * 
 * La sua complessità media è Q(n)
 * 
 * Il funzionamento del Bucket sort è il seguente:
 *      Definisce un array di "buckets" inizialmente vuoti
 *      Mette ogni elemento dell’array nel suo bucket
 *      Ordina ogni bucket non-vuoto
 *      Sposta gli elementi dai buckets all’array originale
*/


/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void bucketSort(vector<T> arr) {
    int n = arr.size();
    
    // Creazione di un vettore di secchi (bucket) vuoti
    vector<int> buckets(n);

    // Distribuzione degli elementi nei secchi
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr.at(i);
        buckets[bucketIndex].push_back(arr.at(i));
    }

    // Ordinamento dei secchi e concatenazione degli elementi ordinati
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
        
    }
}

int main() {
    vector<int> arr = {42, 32, 33, 52, 37, 47, 51};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    bucketSort(&arr); // Imposta il numero di secchi (buckets)

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


 */