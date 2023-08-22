/**
 * Bisogna pianificare un viaggio in autostrada entrando al km 0 ed uscendo al km N.
    • L'auto con serbatoio pieno ha un'autonomia di m km.
    • Esistono n stazioni di servizio ai km d[1...n] in cui è possibile fare il pieno.
    
    • Progettare un algoritmo greedy che consenta di minimizzare il numero di soste.
*/

#include <iostream>
#include <vector>

#include "minheap.h"
#include "minPriorityQueue.h"

using namespace std;


int km = 0;
int N = 16; // km totali
int m = 2;

void soluzioneOttimale(MinPriorityQueue<int>& queue, int kmPercorsi) {

    int temp = 0;
    while (kmPercorsi > queue.queueMinimum()) // θ(logn) * d dove d è il numero di extract che devo fare
        temp = queue.queueExtractMin(); // θ(logn)

    if (kmPercorsi < queue.queueMinimum()) // θ(logn)
        queue.queueInsert(temp);
}

int main(){

    vector<int> stazioni = { 6, 4, 10, 2, 14, 12, 8 };
    MinPriorityQueue<int> minStazioni(&stazioni);
    minStazioni.printingAsciiTree();

    int kmPercorsi = km + m;

    while (kmPercorsi < N){ // N/m * ( d * logn )
        soluzioneOttimale(minStazioni,kmPercorsi);
        km = minStazioni.queueExtractMin();
        cout << "km percorsi: " << kmPercorsi << " Stazione: " << km << endl;
        kmPercorsi += m;
    }
    cout << "km percorsi: " << kmPercorsi << endl;

    return 0;
}