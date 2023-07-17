/**
 * La blockchain è una struttura dati composta da una lista di
 * blocchi all'interno dei quali è memorizzato un insieme di
 * transazioni.
*/

#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include "list.h"
#include "transaction.h"

using namespace std;

class Block {
    private:
        int id;
        List<Transaction> *list;
    public:
        Block(int id);
        //~Block();

        void setId(int id);
        int getId();

        void setList(List<Transaction> *list);
        List<Transaction> *getList();

        void insertList(int ntrans);

        int printList(string );
};

Block::Block(int id) {
    this->id = id;
    this->list = new List<Transaction>;
}

void Block::setId(int id) {
    this->id = id;
}

int Block::getId() {
    return id;
}

void Block::setList(List<Transaction> *list) {
    this->list = list;
}

List<Transaction> *Block::getList() {
    return list;
}

void Block::insertList(int ntrans) {
    string from;
    string to;
    double qt;

    for (int i = 1; i <= ntrans; i++)
        {
            cout<<"----------------------------------------------------------"<<endl;
            cout<<"Inserisci la transazione n. "<< i << "per il blocco n." << getId() << endl;
            cout<<"Inserire il mittente:"<<endl;
            cin>>from;
            cout<<"Inserire il destinatario:"<<endl;
            cin>>to;
            cout<<"Inserire la quantità:"<<endl;
            cin>>qt;
            cout<<"----------------------------------------------------------"<<endl;

            Transaction *test = new Transaction(from,to,qt);
            list->insNode(test);
        }
}

int Block::printList(string ind) {
    Node<Transaction> *stampa = list->getHead();
    int bilancio = 0;

    while (stampa != nullptr){
        if (ind == stampa->getInfo()->getFrom()){

            stampa->getInfo()->printTransaction();
            bilancio -= stampa->getInfo()->getQt(); //Toglie la quantità
        }
        else if(ind == stampa->getInfo()->getTo()){

            stampa->getInfo()->printTransaction();
            bilancio += stampa->getInfo()->getQt();  //Aggiunge la quantità
        }
        stampa = stampa->getNext();
    }
    
    return bilancio;
}


#endif