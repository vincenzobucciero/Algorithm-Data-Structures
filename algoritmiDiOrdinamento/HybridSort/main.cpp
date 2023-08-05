/**
 * Hybrid Sort
 * 
 * Se combiniamo due miglioramenti ossia usare insertionSort per trattare gli array piccoli ed il
 * metodo della mediana per evitare le partizioni sfavorevoli otteniamo un miglioramento
 * complessivo che si aggira tra il 25-30%.
 * 
 * Il metodo della mediana consiste nel cercare un partizionamento migliore (ossia evitando il caso peggiore), 
 * prelevando tre elementi ed utilizzando il mediano dei tre. Se i tre elementi prescelti sono prelevati dalla sinistra, dal
 * centro e dalla destra dell’ array allora ordiniamo i tre elementi, scambiamo quello di mezzo con a[r-1] e
 * applichiamo l’algoritmo di partizionamento alla sequenza a[l+1], ….a[r-2]. Il procedimento aiuta il Quicksort
 * facendo sì che il caso peggiore sia estremamente improbabile. Riduce il tempo medio di esecuzione di circa il 5% (in media).
*/

#include <iostream>
#include <time.h>

using namespace std;

void swap(int &a, int &b) {
    int tmp; 
    tmp = a;
    a = b;
    b = tmp;
}

void compswap(int &a, int &b) {
    if(b < a) {
        swap(a, b);
    }     
}

void insertionSort(int *a, int n) {
    for(int j = 0; j < n; j++) {
        int key = a[j];
        int i = j-1;
        while(i >= 0 && a[i] > key) {
            swap(a[i+1], a[i]);
            i = i-1;
        }
        a[i+1] = key;
    }
}

int partition(int *a, int p, int r) {
    int pivot = a[p];
    int i = p-1;
    int j = r+1;

    do {
        do {
            j = j-1;
        } while(a[j] > pivot);
        do {
            i = i+1;
        } while(a[i] < pivot);
        if(i < j) {
            swap(a[i], a[j]);
        }
    } while(i < j);

    return j;
}

void hybridSort(int *a, int n, int p, int r) {
    if(r-1 > n) {
        swap(a[(p+r)/2], a[r-1]);
        compswap(a[r-1], a[p]);
        compswap(a[r], a[p]);
        compswap(a[r], a[r-1]);
        int q = partition(a, p+1, r-1);
        hybridSort(a, n, p, q-1);
        hybridSort(a, n, q+1, r);
    }
    insertionSort(a, n);
}

int main(int argc, char *argv[]) {
if (argc < 2) {
        cerr << "Errore: Strunz e merd almeno un argomento è richiesto." << endl;
        return 1; // Termina il programma con un codice di errore
    }

    //int vettore[] = {8,4,10,2,6,5,21,20};
    int n = atoi(argv[1]);

    //cout << "Inserisci dimensione vettore: ";
    //cin >> n;

    int *vettore = new int[n];

    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        vettore[i] = rand()%10;
    }

    cout << "Vettore NON ordinato: " << endl;
    for(int i = 0; i < n; i++) {
        cout << vettore[i] << " ";
    }

    cout << endl;

    hybridSort(vettore, n, 0, n-1);

    cout << "Vettore ordinato con HybridSort: " << endl;
    for(int i = 0; i < n; i++) {
        cout << vettore[i] << " ";
    }

    cout << endl;

    delete [] vettore;
    return 0;
}