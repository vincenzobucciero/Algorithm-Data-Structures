//INSERTION SORT

/**
 * Algoritmo di ordinamento piu semplice
 * 
 * Ottimale se la quantità di numeri da ordinare è sufficientemente piccola
 * 
*/

#include <iostream>

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

int main() {
    int n;

    cout <<"Inserisci dimensione array:  ";
    cin >> n;
    
    int arr[n];

    for(int i=0 ;i<n; ++i) {
        arr[i] = rand()%10;
    }

    cout << "Aray disordinato originale:  " << endl;
    for(int i=0 ;i<n; ++i) {
        cout << arr[i] << "  ";
    }

    insertionSort(arr, n);

    cout << endl;
    cout << "Aray ordinato dopo insertionSort:  " << endl;
    for(int i=0 ;i<n; ++i) {
        cout << arr[i] << "  ";
    }
    cout << endl;

    return 0;
}