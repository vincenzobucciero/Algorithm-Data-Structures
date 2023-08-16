/**
 * Il Radix Sort è un algoritmo di ordinamento usato per ordinare record con chiavi multiple
 * 
 * Un esempio di record con chiavi multiple è dato dalla data gg/mm/aaaa
 *      Per ordinare per data si deve ordinare l’anno
 *          a parità di anno si deve ordinare per mese
 *          a parità di mese per giorno
 * 
 * Un altro esempio di record a chiave multipla è dato dal considerare le cifre di un intero come chiavi separate
 * 
 * Il Radix Sort opera in modo contro intuitivo ordinando prima le cifre meno significative e poi quelle
 * via via più significative
 * 
 * Supponiamo di dover ordinare una sequenza di numeri a 3 cifre
 * Utilizzando un ordinamento di tipo stabile possiamo procedere ordinando prima per le unità, poi le decine 
 * e in ultimo le centinaia
 * 
 * Ad ogni passo la stabilità ci garantisce che le cifre precedenti sono già ordinate
*/


/*
    Radix Sort   
*/

#include <iostream>
#include <string>

using namespace std;

void visualizza(int array[], int n){
    for (int i=0; i<n; i++)
        cout << "Array[" << i << "]: " << array[i] << endl;
}

void visualizza(string array[], int n){
    for (int i=0; i<n; i++)
        cout << "Array[" << i << "]: " << array[i] << endl;
}

void radixsortS(string[],int);
int getMaxS(string[],int);
void insertion_sort(string[],int);
void radixsort(int[],int);
int getMax(int[],int);
void countSort(int[],int,int);
int main(){

    // RADIX SORT
    int array[] = {566,435,123,765,948,686,827,642,761,980};

    cout << "*** ARRAY DISORDINATO ***" << endl;
    visualizza(array,10);

    radixsort(array,10);

    cout << "*** ARRAY ORDINATO ***" << endl;
    visualizza(array,10);

    // Implementare radix sort su un array di parole di 4 caratteri
    string arr[] = {"Alba","Logo","Face","Song","Lato"};

    cout << "*** ARRAY DISORDINATO ***" << endl;
    visualizza(arr,5);

    radixsortS(arr,5);

    cout << "*** ARRAY ORDINATO ***" << endl;
    visualizza(arr,5);
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n) {

    int m = getMax(arr, n);
 
    // Esegui il conteggio per ogni cifra. Nota che invece
    // del numero di cifra che passa, exp è passato. exp è 10^i
    // dove i è il numero della cifra corrente
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp);
}

// Radix sort string
void radixsortS(string arr[], int n) {

    int m = getMaxS(arr,n);

    for ( int i=0; i<m; i++ )
        insertion_sort(arr,n);

}

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n) {

    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// max per stringa
int getMaxS(string arr[], int n) {

    int mx = arr[0].length();
    for ( int i=1; i<n; i++ )
        if ( arr[i].length() > mx )
            mx = arr[i].length();
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp) {
 
    int *output = new int[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Utilizzo insertion perchè il counting può essere utilizzato solo per numeri interi
void insertion_sort(string arr[], int n) {

    int i, j;
    string key;
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 
    } 
}