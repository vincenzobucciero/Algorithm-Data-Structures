/**
 * Implementare quickSort con utilizzo di Vector e iteratori
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator partition(vector<int>& a, vector<int>::iterator p, vector<int>::iterator r) {
    int pivot = a[*r];
    vector<int>::iterator i = p-1;
    vector<int>::iterator j = r+1;

    do {
        do {
            j = j - 1;
        } while(*j > pivot);
        do {
            i = i + 1;
        } while(*i < pivot);

        if(i < j) {
            swap(*i, *j);
        }
    } while(i < j);

    return j;
}

void quicksort(vector<int>& a, vector<int>::iterator p, vector<int>::iterator r) {
    if(p < r) {
        vector<int>::iterator q = partition(a, p, r);
        quicksort(a, p, q);
        quicksort(a, q+1, r);
    }
}

int main() {
    vector<int> vec = {8, 4, 10, 2, 6, 5, 21, 20};

    cout << "Vettore NON ordinato: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    quicksort(vec, vec.begin(), vec.end() - 1);

    cout << "Vettore ordinato con QuickSort: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}