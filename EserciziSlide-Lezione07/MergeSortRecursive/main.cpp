/**
 * Progetta e implementa una versione ricorsiva del mergeSort
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void merge(vector<T>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L(n1);
    vector<T> R(n2);

    for(int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(L[i] < R[j]) {
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

template <typename T>
void mergeSortRecursive(vector<T>& a, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSortRecursive(a, left, mid);
        mergeSortRecursive(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    vector<int> a = {38, 27, 43, 3, 9, 82, 10};

    cout << "Vector non ordinato" << endl;
    for(auto num : a) {
        cout << num << " ";
    }

    mergeSortRecursive(a, 0, a.size()-1);

    cout << "\nVector ordinato con MergeSort Ricorsivo" << endl;
    for(auto num : a) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}