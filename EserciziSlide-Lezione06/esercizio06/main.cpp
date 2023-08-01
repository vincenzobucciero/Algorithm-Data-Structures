/**
 * A company is listed on the stock exchange. Suppose we have an array
 * A[1...N] containing the share price in a period of
 * N days and that A[1]<A[N]. It can be shown that there exists
 * at least one pair of consecutive days i, i+1 such that A[i]<A[i+1].
 * Design and implement a divide-and-conquer algorithm that
 * finds an index i that verifies the given condition.
 * 
 * Example:
                |20|15|13|12|21| --> the pair to be returned is |12|21|
*/


#include <iostream>

using namespace std;

int findIndex(int arr[], int start, int end) {
    int mid;
    int index;

    /**
     * Basic Case:
     * The base case is when we only have two numbers 
     * and which fulfil the condition A[i]<A[i+1].
     * 
     * Otherwise it will return -1
    */
    if(end+1-start == 1) {
        if(arr[start] < arr[end]) {
            return start;
        } else 
            return -1;
    } else {
        /**
            * Not Basic Case:
            *  If we are not in the base case then we should operate recursively.
                -> We find the median;
                -> The first check to be made is whether the median is < its subsequence (median+1);
                -> If this condition is not verified then we must examine the SX portion;
                -> If it is not present on the left we should necessarily find it in the DX portion;
                -> Of course we always return the index of the minor position;
        */
        mid = (start+end)/2;
        if(arr[mid] < arr[mid+1]) {
            return mid;
        } else {
            index = findIndex(arr, start, mid);
            if(index = -1) {
                return findIndex(arr, mid+1, end);
            } else 
                return index;
        }
    }
}

int main() {
    int a[]={20,11,13,22,21};

    int ind = findIndex(a,0,4);
    cout<<"L'indice è: "<< ind<<endl;
    cout<<"La coppia è: "<< a[ind] <<" "<< a[ind+1] <<endl<<endl;

    return 0;
}

