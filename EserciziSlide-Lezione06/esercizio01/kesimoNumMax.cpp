/**
 * Dato un insieme di N numeri, trovare il k-esimo numero più grande
*/

#include <iostream>
#include <ctime>

using namespace std;

/**
 * idea 1:
 * non ordinare il vettore, confrontare gli elementi per trovare massimo
*/

void allocationArr(int **arr, int n) {
    *arr = (int*)calloc(n, sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        (*arr)[i] = rand()%10;
    }
}

void printArr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int findMax(int *arr, int n) {
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

/**
 * idea 2:
 * ordinale l'array in modo crescente e ritornare l'ultimo elemento
*/

void swap(int &a, int &b) {
    int tmp; 
    tmp = a;
    a = b; 
    b = tmp;
}

int insertionSort(int *arr, int n) {
    int key;
    int i;
    for(int j = 1; j < n; j++) {
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key) {
            swap(arr[i+1], arr[i]);
            i = i - 1;
        }
        arr[i + 1] = key;
    }

    return arr[i+1];
}

int main() {
    int n;

    cout << "Inserisci dimensione dell'array:  ";
    cin >> n;

    int *arr;
    
    //srand(time(NULL));
    allocationArr(&arr, n);

    cout << "Array disordinato:" <<  endl;
    printArr(arr, n);

    //versione 2
    insertionSort(arr, n);
    cout << "Array ordinato dopo insertion:" <<  endl;
    printArr(arr, n);

    cout << "L'ultimo elemento dell'array cioè il massimo è:  " << insertionSort(arr, n) << endl; 

    cout << "L'elemento massimo del vettore è:  " << findMax(arr, n) << endl;

}