#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[] = {10,20,30,40,50,60,70,80,90};
    vector<int> v = {1,2,3,4,5};
    /**
     * A For loop is a repetition control structure that allows us to write a loop that 
     * is executed a specific number of times. 
     * The loop enables us to perform n number of steps together in one line. 
    */

    for(int i = 0; i < 5; i++) {
        cout << "HelloWorld by Vincenzo!!" << endl;
    }

    for(auto element: arr) {
        cout << element << endl;
    }

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "\t";
    }

    return 0;
}