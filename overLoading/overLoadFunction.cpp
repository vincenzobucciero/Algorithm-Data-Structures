#include <iostream>
#include <cmath>
using namespace std;

int radQuadrata(int x) {
    return int(sqrt(x));
}

double radQuadrata(double x) {
    return sqrt(x);
}

int dividiNumeri(int x, int y) {
    return x / y;
}

double dividiNumeri(double x, double y) {
    return x / y;
}

int main() {
    /*
    int a = 25;
    double b = 56.0332;

    cout << "Radice quadrata di " << a << " è : " << radQuadrata(a) << endl;
    cout << "Radice quadrata di " << b << " è : " << radQuadrata(b) << endl;
    */

   /**
    * In C++ è possibile definire un riferimento ad una variabile. 
    * Un riferimento va considerato come un secondo nome per la variabile. 
    * Ogni volta che si accede ad un riferimento o alias si
    * accede all’area di memoria associata alla variabile.
   */
    int x = 5, y = 2;
    int &rx = x;    //rx fa riferimento al valore di x
    double a = 5.0, b = 2.0;

    cout << "La divisione con l'alias 'rx' di 'x' è : " << dividiNumeri(rx, y) << endl;
    cout << "Valore di rx : " << rx << endl;

    //cambio valore a rx, cosa succede a x?
    rx = 2;
    cout << "Valore di x : " << x << endl;

    return 0;
}