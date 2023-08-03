/**
 * QuickSort - VANTAGGI
 * 
 * generalmente ha prestazioni migliori tra gli algoritmo di ordinamento basati su confronto;
 * 
 * general purpose;
 * 
 * in molti casi richiede meno risorse di qualsiasi altro algoritmo;
 * 
 * vantaggio di operare direttamente sul file da ordinare e per effettuare l'ordinamento di N elementi richiede 
 * solo operazioni e ha un ciclo interno estremamente breve.
 * 
 * QuickSort - SVANTAGGI
 * 
 * non è un algoritmo stabile;
 * 
 * nel peggiore dei casi ha un comportamento quadratico.
*/

/**
 * Algoritmo DIVIDE-ET-IMPERA
 * 
 * DIVIDE -> il vettore di ingresso A(p,r) viene suddiviso in due sottovettori A(p,q) e A(q+1,r) tali che ogni elemento
 *              del primo risulta essere minore uguale di ogni elemento del secondo 
 *              (il valore q è prodotto dalla funzione PARTITION);
 * 
 * IMPERA -> i due sottovettori vengono ordinati con chiamate ricorsive all’ algoritmo quicksort;
 * 
 * COMBINA -> i due sottovettori ordinati vengono fusi producendo l’output desiderato
*/