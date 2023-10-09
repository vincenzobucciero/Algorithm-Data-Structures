//
// Created by vincenzo on 09/10/23.
//

#ifndef ALGORITHM_DATA_STRUCTURES_MERGESORT_H
#define ALGORITHM_DATA_STRUCTURES_MERGESORT_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T>
class MergeSort {
public:
    MergeSort() = default;
    MergeSort(vector<T>& a, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[n1];
        int R[n2];
        for(int i = 0; i < n1; i++) {
            L[i] = a[left+i];
        }
        for(int j = 0; j < n2; j++) {
            R[j] = a[mid + j + 1];
        }
        L[n1 + 1];
        R[n2 + 2];
        int i = 0;
        int j = 0;
        int k = left;
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                a[k] = L[i];
                i++;
            } else {
                a[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n1) {
            a[k] = L[i];
            i++;
            k++;
        }
        while(j < n2) {
            a[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSortCormen(vector<T>& a, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSortCormen(a, left, mid);
            mergeSortCormen(a, mid + 1, right);
            MergeSort<T>(a, left, mid, right);
        }
    }
};

#endif //ALGORITHM_DATA_STRUCTURES_MERGESORT_H
