/**
 * La blockchain è una struttura dati composta da una lista di
 * blocchi all'interno dei quali è memorizzato un insieme di
 * transazioni. Una transazione è costituita da un indirizzo
 * FROM, un indirizzo TO ed un valore intero QT.
 *      1. Progettare ed implementare una struttura dati 
 *              LinkedList mediante template ed utilizzarla per
 *              realizzare una blockchain
 *      2. Dato un indirizzo A, stampare a video/salvare su file
 *              tutte le transazioni in cui compare A ed il suo 
 *              bilancio finale.
 * 
*/

#include <iostream>
#include <string>
#include "list.h"
#include "transaction.h"
#include "block.h"

using namespace std;

int main() {
    List<Block> *blockchain = new List<Block>();

    Block *trans1 = new Block(1);
    //Block *trans2 = new Block(2);
    trans1->insertList(2);
    //trans2->insNode(3);

    string indirizzo;

    blockchain->insNode(trans1);
    //blockchain->insNode(trans2);

    Node<Block> *prova = blockchain->getHead();
    
    cout<<"Inserisci il tuo indirizzo: "<<endl;
    cin>>indirizzo;

    while (prova != nullptr) {
        int saldo = 0;

        cout<<"Blocco: "<<prova->getInfo()->getId()<<endl;
        saldo += prova->getInfo()->printList(indirizzo);
        cout<<"Bilancio per questo blocco: "<<saldo<<endl;
        prova = prova->getNext();
    }
    return 0;
}