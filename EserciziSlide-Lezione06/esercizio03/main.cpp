/**
 * Dato un insieme di N numeri, rimuovere gli elementi duplicati
*/

#include <iostream>
#include <time.h>

#include <unordered_set>

using namespace std;

void allocateFillArray(int **arr, int n) {
    *arr = (int*)calloc(n, sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        (*arr)[i] = rand()%100;
    }
}

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int tmp;
    tmp = a; 
    a = b;
    b = tmp;
}

void insertionSort(int *arr, int n) {
    int key;
    int i;
    for(int j = 1; j < n; j++) {
        key = arr[j];
        i = j - 1;
        while( i >= 0 && arr[i] > key) {
            swap(arr[i+1], arr[i]);
            i = i - 1;
        }
        arr[i+1] = key;
    }
}

/**
 * Per rimuovere gli elementi duplicati da un insieme di numeri in C++, 
 * puoi utilizzare l'approccio dell'hash set. Un hash set è una struttura dati che mantiene 
 * solo valori unici, quindi puoi scorrere l'insieme di numeri e inserirli nell'hash set. 
 * Gli elementi duplicati verranno automaticamente eliminati. 
 * Dopo di che, puoi copiare i valori unici dall'hash set in un nuovo array 
 * (se desideri ottenere un array con gli elementi unici) 
 * o semplicemente stampare i valori unici direttamente dal set.
*/
void removeDuplicates(int *arr, int &n) {
    unordered_set<int> uniqueElements;
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (uniqueElements.find(arr[i]) == uniqueElements.end()) {
            // Se l'elemento non è presente nell'hash set, aggiungilo
            uniqueElements.insert(arr[i]);
            arr[index] = arr[i];
            index++;
        }
    }

    // Riduci la dimensione dell'array al numero di elementi unici trovati
    n = index;
}

int main() {
    int n;

    cout << "Inserisci dimensione dell'array:  ";
    cin >> n;

    int *arr;

    allocateFillArray(&arr, n);
    printArray(arr, n);

    insertionSort(arr, n);

    printArray(arr, n);

    removeDuplicates(arr, n);

    printArray(arr, n);

    return 0;
}