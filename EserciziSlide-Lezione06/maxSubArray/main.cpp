//Sia dato un vettore A di n elementi, determina il sottoarray contiguo e non vuoto di A tale che la somma 
//dei suoi elementi sia massima?


#include <iostream>
#include <time.h>
#include <vector>
#include <tuple>

/**
 * Algoritmo divide et impera:
 * -> Divide: si suddivide il problema in vari sottoproblemi, simili al problema originale ma di dimensioni più
                piccole:
   -> Impera: si risolvono i sottoproblemi in maniera RICORSIVA;
   -> Combina: si combinano le soluzioni dei sottoproblemi per costruire una soluzione del problema originale.

   Caso ricorsivo: quando i sottoproblemi effettuano ancora chiamate ricorsive
   Caso base: quando il sottoproblema è sufficientemente piccolo da non richiedere ulteriori ricorsioni
*/

//Funzione max per trovare il massimo tra n numeri
int max(int a, int b, int c) {
    return std::max(a, std::max(b, c));
}



/**
 *  Per questo esercizio vengono utilizzate le tuple. 
 *  In C++, le tuple sono strutture dati che possono contenere più elementi di diversi tipi. 
 *  Gli elementi nella tupla sono numerati a partire da zero.
    
    #include <iostream>
    #include <tuple>

    int main() {
        std::tuple<int, double, char> myTuple = std::make_tuple(42, 3.14, 'A');

        int firstElement = std::get<0>(myTuple);
        double secondElement = std::get<1>(myTuple);
        char thirdElement = std::get<2>(myTuple);

        std::cout << "First element: " << firstElement << std::endl;
        std::cout << "Second element: " << secondElement << std::endl;
        std::cout << "Third element: " << thirdElement << std::endl;

        return 0;
}

*/

std::tuple<int, int, int> findMaxCrossingSubArray(std::vector<int> &A, int low, int mid, int high) {
    int leftSum = INT32_MIN;
    int rightSum = INT32_MIN;
    int sum = 0;
    int maxLeft;
    int maxRight;

    // Trova la somma massima a sinistra del mediano
    for (int i = mid; i >= low; --i) {
        sum += A[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;

    // Trova la somma massima a destra del mediano
    for (int i = mid + 1; i <= high; ++i) {
        sum += A[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    // Restituisci l'indice iniziale, l'indice finale e la somma massima attraverso il mezzo
    return std::make_tuple(maxLeft, maxRight, leftSum + rightSum);
}

// Funzione ricorsiva per trovare il massimo sottoarray contiguo
std::tuple<int, int, int> findMaxSubarray(std::vector<int>& A, int low, int high) {
    // Caso base: se il vettore contiene un solo elemento, restituisci questo elemento
    if (low == high) {
        return std::make_tuple(low, high, A[low]);
    }

    // Trova l'indice di mezzo
    int mid = (low + high) / 2;

    // Trova il massimo sottoarray contiguo nei tre sottovettori: a sinistra, a destra e che attraversa il mezzo
    auto leftSubarray = findMaxSubarray(A, low, mid);
    auto rightSubarray = findMaxSubarray(A, mid + 1, high);
    auto crossingSubarray = findMaxCrossingSubArray(A, low, mid, high);

    // Calcola la somma dei sottovettori trovati
    int leftSum = std::get<2>(leftSubarray);
    int rightSum = std::get<2>(rightSubarray);
    int crossingSum = std::get<2>(crossingSubarray);

    // Restituisci il sottovettore con la somma massima tra i tre
    if (leftSum >= rightSum && leftSum >= crossingSum) {
        return leftSubarray;
    } else if (rightSum >= leftSum && rightSum >= crossingSum) {
        return rightSubarray;
    } else {
        return crossingSubarray;
    }
}


int main() {
    std::vector<int> A = { 10, 1, -20, 4, -1, 2, 1, -5, 4 }; // Esempio di input
    int n = A.size();

    // Trova il massimo sottoarray contiguo utilizzando la funzione ricorsiva
    auto result = findMaxSubarray(A, 0, n - 1);

    int startIndex = std::get<0>(result);
    int endIndex = std::get<1>(result);
    int maxSum = std::get<2>(result);

    std::cout << "Il massimo sottoarray contiguo ha somma: " << maxSum << std::endl;
    std::cout << "Indici iniziale e finale del sottoarray: " << startIndex << " " << endIndex << std::endl;

    return 0;
}
