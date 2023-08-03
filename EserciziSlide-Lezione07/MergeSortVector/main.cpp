/**
 * Riscrivi il MergeSort utilizzando i vector e gli iteratori
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Merge a due vie
 * Funzione template, può funzionare con qualsiasi tipo di dato e qualsiasi tipo di iteratore.
 *  
 * Prende in input tre iteratori: it -> inizio primo sottovettore, mid -> inizio secondo sottovettore, 
 *                                  end -> ultimo elemento secondo sottovettore + 1
*/
template <typename Iterator>
void merge(Iterator it, Iterator mid, Iterator end) {
    vector<typename Iterator::value_type> tmp;  //vector temporaneo di appoggio
    //left | right sono iteratori per scorrere rispettivamente i due sottovettori
    Iterator left = it;
    Iterator right = mid;

    /**
     * ciclo while finché né left né right hanno raggiunto l'iteratore mid o end. Durante questo ciclo, 
     * si confronta gli elementi puntati da left e right e inserisce l'elemento più piccolo nel vettore temporaneo temp. 
     * Dopodiché, sposta l'iteratore corrispondente (left o right) avanti di una posizione.
    */
    while(left != mid && right != end) {
        if(*left <= *right) {
            tmp.push_back(*left);
            ++left;
        } else {
            tmp.push_back(*right);
            ++right;
        }
    }

    /**
     * Terminato il ciclo while, se sono rimasti degli elementi in uno dei due sottovettori ancora non inseriti, 
     * vengono copiati nel vector temporaneo
    */
    tmp.insert(tmp.end(), left, mid);
    tmp.insert(tmp.end(), right, end);

    /**
     *  copia tutti gli elementi del vettore temporaneo temp nel sottovettore originale
     *  utilizzando la function copy, con l'iteratore it come destinazione.
    */
    copy(tmp.begin(), tmp.end(), it);
}

template <typename Iterator>
void mergeSort(Iterator begin, Iterator end) {
    //calcola la distanza tra inizio e fine vettore
    int size = distance(begin, end);

    if(size <= 1) 
        return;
    
    //mid punta all'elemento a metà dell'intervallo (o un elemento a sinistra se la dimensione è dispari)
    Iterator mid = begin + size /2;

    mergeSort(begin, mid);
    mergeSort(mid, end);
    merge(begin, mid, end);
}

int main() {
    vector<int> container = {10,5,7,8,1,1,0};

    cout << "Array non ordinato:" << endl;
    for(auto num : container) { 
        cout << num << "  ";
    }

    mergeSort(container.begin(), container.end());

    cout << "\nArray ordinato (MergeSort Vector & Iterator):" << endl;
    for(auto num : container) { 
        cout << num << "  ";
    }

    cout << endl;

    return 0;
}