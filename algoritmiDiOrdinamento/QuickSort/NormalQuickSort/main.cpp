/**
 * QuickSort - VANTAGGI
 * 
 * generalmente ha prestazioni migliori tra gli algoritmo di ordinamento basati su confronto;
 * 
 * general purpose;
 * 
 * in molti casi richiede meno risorse di qualsiasi altro algoritmo;
 * 
 * vantaggio di operare direttamente sul file da ordinare e per effettuare l'ordinamento di N elementi richiede 
 * solo operazioni e ha un ciclo interno estremamente breve.
 * 
 * QuickSort - SVANTAGGI
 * 
 * non è un algoritmo stabile;
 * 
 * nel peggiore dei casi ha un comportamento quadratico.
*/

/**
 * Algoritmo DIVIDE-ET-IMPERA
 * 
 * DIVIDE -> il vettore di ingresso A(p,r) viene suddiviso in due sottovettori A(p,q) e A(q+1,r) tali che ogni elemento
 *              del primo risulta essere minore uguale di ogni elemento del secondo 
 *              (il valore q è prodotto dalla funzione PARTITION);
 * 
 * IMPERA -> i due sottovettori vengono ordinati con chiamate ricorsive all’ algoritmo quicksort;
 * 
 * COMBINA -> i due sottovettori ordinati vengono fusi producendo l’output desiderato
*/


#include <iostream>
#include <time.h>

using namespace std;

/**
 * Function per swappare elementi confrontati
 * 
 * @param a primo elemento
 * @param b secondo elemento
*/
void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

/**
 * Poichè il QuickSort è un algoritmo di ordinamento basato su algoritmi divide-et-impera,
 * si va a suddividere il vettore di partenza in due sottovettori e così via fino a quando non si raggiunge il caso base,
 * cioè ove non è piu possibile suddividere il vettore. Al termine della partition verrà ritornato un indice j
 * che indica l'elemento cui termina il primo sottovettore.
 * 
 * @param a vettore da ordinare
 * @param p elemento start del vettore
 * @param r elemento end del vettore 
*/
int quickSortPartition(int a[], int p, int r) {
    int pivot = a[p];   //primo elemento del vettore
    int i = p - 1;      //indice per scorrere il vettore (viene incrementato)
    int j = r + 1;      //indice per scorrere il vettore (viene decrementato)

    do {
        do {
            j = j - 1;
        } while (a[j] > pivot);

        do {
            i = i + 1;
        } while (a[i] < pivot);

        if (i < j) {
            swap(a[i], a[j]);    //scambio elementi
        }
    } while (i < j);

    return j;
}

void quickSort(int a[], int p, int r) {
    if (p < r) {
        int q = quickSortPartition(a, p, r);
        quickSort(a, p, q);
        quickSort(a, q+1, r);
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

    for(int i = 0; i < n; i++) {
        vettore[i] = rand()%10;
    }

    cout << "Vettore NON ordinato: " << endl;
    for(int i = 0; i < n; i++) {
        cout << vettore[i] << " ";
    }

    cout << endl;

    quickSort(vettore, 0, n-1);

    cout << "Vettore ordinato con QuickSort: " << endl;
    for(int i = 0; i < n; i++) {
        cout << vettore[i] << " ";
    }

    cout << endl;

    delete [] vettore;
    return 0;
}