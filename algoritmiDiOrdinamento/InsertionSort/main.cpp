//INSERTION SORT

/**
 * Algoritmo di ordinamento piu semplice
 * 
 * Ottimale se la quantità di numeri da ordinare è sufficientemente piccola
 * 
*/

#include <iostream>
#include <ctime>

using namespace std;

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void insertionSort(int arr[], int n) {
    //scorro tutto l'array a partire dal secondo elemento poichè il primo già è ordinato
    for(int j = 1; j < n; j++) {
        //assegno l'elemento corrente a key
        int key = arr[j];
        //indice i = all'elemento precedente a j
        int i = j - 1;
        //il vettore arr[1..j-1] indica gli elementi del vettore già ordinati
        //il vettore arr[1..n] indica gli elementi da ordinare
        //fin quando i >= 0 e arr[i] é maggiore dell'elemento corrente
        while(i >= 0 && arr[i] > key) {
            //scambia
            swap(arr[i+1], arr[i]);
            //decrementa l'indice
            i = i - 1;
        }
        //aggiorna il valore di key
        arr[i+1] = key;
    }
}

void allocationVector(int **vector, int n) {
    *vector = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) {
        srand(time(NULL));
        (*vector)[i] = rand()%10;
    }
}

void printVector(int *vector, int n) {
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << vector[i] << "  ";
    }
}

int main() {
    int n;

    cout <<"Inserisci dimensione array:  ";
    cin >> n;
    
    int *arr;

    /*
    for(int i=0 ;i<n; ++i) {
        arr[i] = rand()%10;
    }
    */
   
    allocationVector(&arr, n);

    cout << "Aray disordinato originale:  " << endl;
    /*
    for(int i=0 ;i<n; ++i) {
        cout << arr[i] << "  ";
    }
    */

    printVector(arr, n);
    insertionSort(arr, n);

    cout << endl;
    cout << "Aray ordinato dopo insertionSort:  " << endl;
    /*
    for(int i=0 ;i<n; ++i) {
        cout << arr[i] << "  ";
    }
    */
    printVector(arr, n);
    cout << endl;

    return 0;
}