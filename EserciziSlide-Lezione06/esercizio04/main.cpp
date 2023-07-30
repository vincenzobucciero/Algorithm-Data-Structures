/**
 * Dato un insieme di N numeri, trovare quello più frequente
*/

#include <iostream>
#include <time.h>

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

pair<int, int> mostFrequentNumber(int *arr, int n) {
    int countmax = 1;
    int currentCount = 1;
    int mostFrequentNum = arr[0]; // Assume che il primo numero sia il più frequente

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > countmax) {
                countmax = currentCount;
                mostFrequentNum = arr[i - 1]; // Aggiorna il numero più frequente
            }
            currentCount = 1;
        }
    }

    // Controlla l'ultimo gruppo di numeri consecutivi
    if (currentCount > countmax) {
        countmax = currentCount;
        mostFrequentNum = arr[n - 1]; // Aggiorna il numero più frequente
    }

    return make_pair(mostFrequentNum, countmax);
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

    pair<int, int> mostFrequent = mostFrequentNumber(arr, n);

    cout << "Il carattere piu frequente è " << mostFrequent.first << " e compare " << mostFrequent.second << " volte." << endl;

    return 0;
}