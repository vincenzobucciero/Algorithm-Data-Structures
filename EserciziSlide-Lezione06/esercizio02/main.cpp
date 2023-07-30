/**
 * Dato un insieme di N numeri, trovare la coppia di numeri che
 * hanno la più piccola differenza tra di loro.
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

//function che ritorna solo la differenza minima
int findMinDifference(int *arr, int n) {
    int minDifference = 100;     //metto 100 poiche i numeri generati vanno fino a 99
    for(int i = 0; i < n; i++) {
        int diff = arr[i] - arr[i-1];
        if(diff < minDifference) {
            minDifference = diff;
        }
    }
    return minDifference;
}

//function che ritorna oltre che la differenza minima anche i numeri interessati
pair<int, int> findPairMinDifference(int *arr, int n) {
    int minDifference = 100;    //metto 100 poiche i numeri generati vanno fino a 99
    pair<int, int> minDifferencePair;

    for(int i = 0; i < n; i++) {
        int diff = arr[i] - arr[i-1];
        if(diff < minDifference) {
            minDifference = diff;
            minDifferencePair = make_pair(arr[i-1], arr[i]);
        }    
    }
    return minDifferencePair;
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

    /*
        Versione con numeri interessati nella differenza
    */
    pair<int, int> minDifferencePair = findPairMinDifference(arr, n);

    cout << "La minima differenza tra due numeri consecutivi è: " << findMinDifference(arr, n) << endl;
    cout << "-> I numeri interessati nell'operazione sono: " << minDifferencePair.first << " e " << minDifferencePair.second << endl;

    return 0;
}

