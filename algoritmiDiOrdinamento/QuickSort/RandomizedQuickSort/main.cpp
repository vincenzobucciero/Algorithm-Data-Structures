/**
 * RandomizedQuickSort
 * 
 * Le prestazioni di Quicksort dipendono dal primo elemento (poichè x=A[p]).
 * 
 * Una buona pratica può essere quella di scambiare, prima di eseguire la PARTITION, il primo elemento con uno scelto a caso.
 * 
 * In questo caso si ha il RANDOMIZED_QUICKSORT.
*/

#include <iostream>
#include <time.h>
#include <cstdlib>

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b; 
    b = tmp;
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
            std::swap(a[i], a[j]);
        }
    } while(i < j);

    return j;
}

int randomizedPartition(int *a, int p, int r) {
    int randomizedPivot = p + rand()%(r-p+1);
    std::swap(a[randomizedPivot], a[p]);
    return partition(a, p, r);
}

void randomizedQuickSort(int *a, int p, int r) {
    if(p < r) {
        int q = randomizedPartition(a, p, r);
        randomizedQuickSort(a, p, q);
        randomizedQuickSort(a, q+1, r);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Errore: Almeno un argomento è richiesto." << std::endl;
        return 1; // Termina il programma con un codice di errore
    }

    int n = atoi(argv[1]);

    int *vettore = new int[n];

    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        vettore[i] = rand()%10;
    }

    std::cout << "Vettore NON ordinato: " << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << vettore[i] << " ";
    }

    std::cout << std::endl;

    randomizedQuickSort(vettore, 0, n-1);

    std::cout << "Vettore ordinato con QuickSort: " << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << vettore[i] << " ";
    }

    std::cout << std::endl;

    delete [] vettore;
    return 0;
}