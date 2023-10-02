/**
 * Bucket sort o bin sort è un algoritmo di ordinamento il cui funzionamento consiste nel suddividere 
 * un array in un numero finito di buckets
 * 
 * Ciascun bucket è ordinato individualmente o utilizzando un algoritmo di ordinamento differente od applicando
 * ricorsivamente il bucket sort
 * 
 * La sua complessità media è Q(n)
 * 
 * Il funzionamento del Bucket sort è il seguente:
 *      Definisce un array di "buckets" inizialmente vuoti
 *      Mette ogni elemento dell’array nel suo bucket
 *      Ordina ogni bucket non-vuoto
 *      Sposta gli elementi dai buckets all’array originale
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
void bucketSort(vector<T>& arr) {
    int n = arr.size();
    vector<vector<T>> buckets(n);

    for(int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<int> arr;

    ifstream input;
    string myFileInput = "fileInput.txt";
    input.open(myFileInput);

    int num;
    while(input >> num) {
        arr.push_back(num);
    }

    input.close();

    cout << "Array non ordinato:" << endl;
    for(auto i : arr) {
        cout << i << "  ";
    }

    bucketSort(arr);

    cout << "Array ordinato con bucketSort:" << endl;
    for(auto i : arr) {
        cout << i << "  ";
    }

    return 0;
}
