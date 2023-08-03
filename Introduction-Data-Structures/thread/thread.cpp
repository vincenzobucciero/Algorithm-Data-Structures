/**
 * Concorrenza
 * 
 * Un task è un calcolo potenzialmente eseguibile in concorrenza con altri; esempio una funzione f()
 * Un thread è la rappresentazione system-level di un task in un programma
 * 
 * Possiamo generare altri thread, costruendo un oggetto thread con il task da eseguire come argomento.
 * 
 * 
*/

/**
 * Senza alcuna forma di sincronizzazione tra i thread, l'ordine di esecuzione
 * delle istruzioni nei due task è indefinita
*/

#include <iostream>
#include <thread>
#include <mutex> //per l'accesso in maniera esclusiva a dati condivisi

using namespace std;

mutex myMutex;  //dichiarazione del mutex

void routine1() {
    myMutex.lock();
    cout << "Sono il primo thread  ";
    myMutex.unlock();
}
void routine2() {
    myMutex.lock();
    cout << "Sono il secondo thread  ";
    myMutex.unlock();
}

int main() {
    thread th1 { routine1 };
    thread th2 { routine2 };

    th1.join();
    th2.join();

    return 0;
}
