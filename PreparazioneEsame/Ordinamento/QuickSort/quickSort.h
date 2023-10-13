#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T>
class QuickSort {
public:
    QuickSort() = default;

    void swap(T& a, T& b);
    int quickSortPartition(vector<T>& a, int p, int r);
    void quickSort(vector<T>& a, int p, int r);
};

template <typename T>
void QuickSort<T>::swap(T& a, T& b) {
    T tmp; tmp = a; a = b; b = tmp;
}

template <typename T>
int QuickSort<T>::quickSortPartition(vector<T>& a, int p, int r) {
    int pivot = a[p];
    int i = p -1;
    int j = r + 1;

    do {
        do {
            j = j - 1;
        } while (a[j] > pivot);
        do {
            i = i + 1;
        } while (a[i] < pivot);
        if (i < j) {
            swap(a[i], a[j]);
        }
    } while (i < j);

    return j;
}

template <typename T>
void QuickSort<T>::quickSort(vector<T>& a, int p, int r) {
    if(p < r) {
        int q = quickSortPartition(a, p, r);
        quickSort(a, p, q);
        quickSort(a, q+1, r);
    }
}


#endif //