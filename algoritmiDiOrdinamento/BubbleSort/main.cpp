/**
 * è l’algoritmo di ordinamento più semplice da implementare
 * 
 * I valori vengono spostati all'interno dell'array con una dinamica che ricorda 
 * il movimento delle bollicine in un bicchiere di champagne
 * 
 * In particolare, alcuni elementi attraversano l'array velocemente mentre altri più lentamente.
 * 
 * Il Bubble sort effettua all’ incirca n²/2 confronti ed n²/2 scambi sia in media che nel caso peggiore
 * Pertanto la sua complessità computazionale è sempre O(n²) ove n è il numero degli elementi da ordinare
 * 
 * Muovendoci nell’array da destra a sinistra, nel momento in cui si incontra l’elemento più piccolo,
 * questo viene scambiato con ogni elemento che si trovi alla sua sinistra, fino a quando non si 
 * raggiunge la posizione di estrema sinistra dell’ array
 * 
 * Quindi durante il secondo passaggio, il secondo elemento più piccolo viene spinto nella giusta 
 * posizione, e così via.
 * 
 * Perciò n passaggi sono sufficienti per ordinare l’ array
*/

#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void compswap(int &a, int &b) {
    if (b < a)
        swap(a, b);
}

void bubbleSort(int a[], int l, int r) {
    for(int i = l; i < r; i++) {
        for(int j = r; j > i; j--){
            compswap(a[j-1], a[j]);
        }
    }
}

int main() {
    int arr[6] = {64, 34, 25, 12, 1, 38};
    cout << "\nArray disordinato di partenza:  " << endl;
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;

    bubbleSort(arr, 0, 5);

    cout << "\nArray ordinato dopo bubbleSort:  " << endl;
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;

    return 0;
}