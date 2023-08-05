/**
 * Progetta e implementa quicksort con doppio pivot
 * 
 * Questa variante utilizza un pivot per la parte sinistra dell'array ed un pivot per la parte destra con il vincolo 
 * che il pivot sinistro sia minore del pivot destro
 * 
 * Al termine della procedura di partition, l'array sarà diviso in tre parti:
 *      La prima in cui gli elementi sono minori del pivot sinistro
 *      La seconda in cui gli elementi sono maggiori o uguali del pivot sinistro e minori uguali del pivot destro
 *      La terza in cui gli elementi sono maggiori del pivot destro
 * 
 * L'algoritmo viene richiamato ricorsivamente sulle tre parti dell'array.
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
    if (a > b) {
        swap(a, b);
    }
}

int partition(int *arr, int p, int r) {
    int pivot1 = arr[p];
    int pivot2 = arr[r];
    int i = p-1;
    int j = r+1;

    if(pivot1 > pivot2) {
        return j-1;
    } else {
        do {
            do {
                j = j-1;
            } while(arr[j] > pivot2);
            do {
                i = i+1;
            } while(arr[i] < pivot1);
            if(i < j) {
                swap(arr[i], arr[j]);
            }
        } while(i < j);
    } 
    swap(arr[p], arr[i-1]);
    swap(arr[r], arr[j]);

    return j;
}

void quicksort(int *arr, int p, int r) {
    if(p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q);
        quicksort(arr, q+1, r);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Errore: Almeno un argomento è richiesto." << endl;
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

    quicksort(vettore, 0, n-1);

    cout << "Vettore ordinato con QuickSort: " << endl;
    for(int i = 0; i < n; i++) {
        cout << vettore[i] << " ";
    }

    cout << endl;

    delete [] vettore;
    return 0;
}

