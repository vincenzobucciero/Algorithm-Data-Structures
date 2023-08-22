/**
 * Implementare l'algoritmo per il calcolo della distanza di editing
    – Valore della soluzione ottima
    – Soluzione ottima
*/

#include <iostream>

using namespace std;

int min(int x, int y, int z) {
    return min(min(x,y), z);
}

int editingDistance(string str1, string str2, int m, int n) {
    //caso base: str1 vuota
    if(m == 0)
        return n;
    
    //caso base: str2 vuota
    if(n == 0)
        return m;
    
    //se l'ultimo carattere delle stringhe è uguale
    //si conta la parte rimanente delle stringhe
    if(str1[m-1] == str2[n-1])
        return editingDistance(str1, str2, m-1, n-1);
    
    //se l'ultimo carattere non è uguale
    return 1 + min(editingDistance(str1, str2, m, n-1), editingDistance(str1, str2, m-1, n), 
                        editingDistance(str1, str2, m-1, n-1));

}

int main() {
    string str1 = "ATCTGAT";
    string str2 = "TGCATA";

    cout << editingDistance(str1, str2, str1.length(), str2.length()) << endl;

    return 0;
}