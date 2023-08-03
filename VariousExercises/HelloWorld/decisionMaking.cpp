#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int i = 20;
    int var = 2;
    /**
    if (i == 20)
        if (i < 15) {
            cout << "I'm smaller than 15" << endl;
        } 
        if (i < 12) {
            cout << "I'm smaller than 15" << endl;
        } else {
            cout << "I'm greater or equal to 20" << endl;
        }
    */

    switch (var) {
    case 1:
        cout << "Case 1 is executed\n";
        break;
    case 2:
        cout << "Case 2 is executed\n";
        break;
    default:
        cout << "Default Case is executed\n";
        break;
    }
    
    return 0;
}