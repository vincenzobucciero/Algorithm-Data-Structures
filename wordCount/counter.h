/**
 *  Progettare ed implementare un programma che utilizzando una Map, conti il
 *  numero di occorrenze di ogni parola contenuta in un file.
*/

#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class Counter {
    private:
        map<string, int> amap;
        fstream myFile;
    public:
        Counter(string myFile);
        ~Counter();

        void counterWord();
};

Counter::Counter(string myStringFile) {
    myFile.open(myStringFile, ios::in);
}
Counter::~Counter() {
    myFile.clear();
    myFile.close();
}

void Counter::counterWord() {
    map<string, int>::iterator it;
    string word;

    while (myFile>>word)
    {
        it = amap.find(word);

        if (it == amap.end()){
            amap.insert(make_pair(word,1));
        }
        else{
            amap.at(word)++;      
        }  
    }
    
     for(it = amap.begin(); it != amap.end(); it++)
        cout << (*it).first << " => " << (*it).second << endl;
}


#endif