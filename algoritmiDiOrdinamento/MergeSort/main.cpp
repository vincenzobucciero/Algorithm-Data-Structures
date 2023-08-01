/**
 * MergeSort's complexity is O(nlog(n))
 * It is an example of divide-et-conquer algorithm
 * 
 * It is a stable sorting algorithm, i.e. maintains the initial (input) order of elements equal in the sorted output array.
 * 
 * - DIVIDE: Divide the input array into two sublists of (approximately) half the length
 * - IMPOSE: Sort, by recursive calls to the function itself, each of the two sub-arrays
 * - COMBINE: Merge the two sorted subarrays
 * 
 * Merge-Sort(A,p,q)
    if p < q
    r←[(p+q)/2]
    Merge-Sort(A,p,r)
    Merge-Sort(A,r+1,q)
    Merge(A,p,q,r)
*/

#include <iostream>
#include <time.h>

using namespace std;

typedef int Item;

/**
 * Two-way merge procedure
 *  
 * Two input ordered sets, we can combine them into a single ordered set by simply
 * keeping track of the smallest element of each set and entering a loop in which the smaller of the
 * two elements is moved to an output set, continuing until both are exhausted.
 * 
 * The execution time is linear in the number of elements in the output file, as long as we are able
 * to find the next minimum in the input files in constant time.
*/

void mergeTwoWay(int c[], int a[], int n, int b[], int m) {
    for(int i = 0, j = 0, k = 0; k < n+m; k++) {
        if(i == n) {
            c[k] = b[j++];
            continue;
        }
        if(j == m) {
            c[k] = a[i++];
            continue;
        }

        c[k] = (a[i] < b[j]) ? a[i++] : b[j++];
    }
}

void mergeSortTwoWay(Item a[], int left, int right) {
    if(left < right) {
        int mid = (left+right)/2;
        mergeSortTwoWay(a, left, mid);
        mergeSortTwoWay(a, mid+1, right);
        int dimSx = mid-left+1;
        int dimDx = right-mid;
        int dimOut = right-left+1;

        Item *out = new Item[dimOut];

        mergeTwoWay(out, a+left, dimSx, a+(mid+1), dimDx);

        //Ricopia il vettore di appoggio nel vettore originale
        for(int index = 0; index < right-left+1; index++)
            a[left+index] = out[index];
        delete [] out;
    }
}

/**
 * Abstract merge in place
 * 
 * The merge procedure in this case stores the result of combining a[1], ...a[m] with
 * a[m+1],...a[r] in a single ordered set, keeping the result in a[1]...a[r]
*/

void abstractMerge(int a[], int left, int mid, int right) {
    int leftEnd = mid;
    int rightStart = mid+1;

    while(left <= leftEnd && rightStart <= right) {
        if(a[left] < a[rightStart]) {
            left++;
        } else {
            Item tmp = a[rightStart];
            for(int i = rightStart; i > left; i--) {
                a[i] = a[i-1];
            }
            a[left] = tmp;
            left++;
            leftEnd++;
            rightStart++;
        }
    }
}

void mergeSortAbstract(Item a[], int left, int right) {
    if(left < right) {
        int mid = (left+right)/2;
        mergeSortAbstract(a, left, mid);
        mergeSortAbstract(a, mid+1, right);
        abstractMerge(a, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Inserisci il numero di elementi del vettore:  ";
    cin >> n;

    int *a = new Item[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        a[i] = rand()%10;
    }

    cout << "Vettore disordinato" << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    mergeSortTwoWay(a, 0, n-1);
    cout << "Vettore ordinato con MergeSort (Procedura Merge a due vie)" << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    mergeSortAbstract(a, 0, n-1);
    cout << "Vettore ordinato con MergeSort (Procedura Merge astratto sul posto)" << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;    

    return 0;
}




