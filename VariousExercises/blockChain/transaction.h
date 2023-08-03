/**
 * La blockchain è una struttura dati composta da una lista di
 * blocchi all'interno dei quali è memorizzato un insieme di
 * transazioni. Una transazione è costituita da un indirizzo
 * FROM, un indirizzo TO ed un valore intero QT.
*/


#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

using namespace std;

class Transaction {
    private:
        string from;
        string to;
        int qt;
    public:
        Transaction(string from, string to, int qt) {this->from = from; this->to = to; this->qt = qt;}

        void setFrom(string from) {this->from = from;}
        string getFrom() {return from;}

        void setTo(string to) {this->to = to;}
        string getTo() {return to;}

        void setQt(int qt) {this->qt = qt;}
        int getQt() {return qt;}

        void printTransaction() {
            cout << "Transaction:  " << endl;
            cout << "\tTransaction from:  " << this->getFrom() << endl;
            cout << "\tTransaction to:  " << this->getTo() << endl;
            cout << "\tQuantity of coins transferred:  " << this->getQt() << endl;
        }
};

#endif