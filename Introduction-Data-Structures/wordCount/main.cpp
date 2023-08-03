/**
 *  Progettare ed implementare un programma che utilizzando una Map, conti il
 *  numero di occorrenze di ogni parola contenuta in un file.
*/

#include <iostream>
#include "counter.h"

int main() {
    Counter testCounter("text.txt");
    testCounter.counterWord();

    return 0;
}