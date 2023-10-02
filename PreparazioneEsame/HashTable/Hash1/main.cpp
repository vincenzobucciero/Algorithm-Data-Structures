//
// Created by vincenzo on 02/10/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class hashElement {
public:
    char key;
    int value;
    hashElement(char k, int v) : key(k), value(v) { }
};

class hashTable {
private:
    vector<list<hashElement>> table;
    int size;
    int hash(char key) const {return static_cast<int>(key) % size;}
public:
    explicit hashTable(int s) : size(s) {table.resize(size);}
    void insert(char key, int value) {
        int index = hash(key);
        table[index].emplace_back(key, value);
    }
    void increment(char key) {
        int index = hash(key);
        for(auto& element : table[index]) {
            if(element.key == key) {
                element.value++;
                return;
            }
        }
        insert(key, 1);
    }
    void printToFile(const string& filename) {
        ofstream outputFile(filename);
        for(const auto& bucket : table) {
            for(const auto element : bucket) {
                outputFile << "Carattere: " << element.key << " Occorrenza: " << element.value << endl;
            }
        }
        outputFile.close();
    }
    int searchCharacter(char keyToFind) {
        int index = hash(keyToFind);
        for(const auto& element : table[index]) {
            if(element.key == keyToFind) {
                return element.value;
            }
        }
        return 0;
    }
    void removeCharacter(char keyToRemove) {
        int index = hash(keyToRemove);
        auto& bucket = table[index];
        for(auto it = bucket.begin(); it != bucket.end(); ++it) {
            if(it->key == keyToRemove) {
                bucket.erase(it);
                return;
            }
        }
    }
    vector<list<hashElement>> getTable() {
        return table;
    }
};

int main() {
    hashTable myHash(256);
    ifstream inputFile("IN.txt");

    char ch;
    while(inputFile.get(ch)) {
        myHash.increment(ch);
    }
    inputFile.close();

    myHash.printToFile("OUT.txt");

    cout << "Tabella hash:" << endl;
    for (const auto& bucket : myHash.getTable()) {
        for (const auto& element : bucket) {
            cout << "Carattere: " << element.key << " Occorrenza: " << element.value << endl;
        }
    }

    char searchChar;
    cout << "Inserisci il carattere da cercare: ";
    cin >> searchChar;

    // Chiamiamo il metodo searchCharacter e stampiamo il risultato
    int occurrence = myHash.searchCharacter(searchChar);
    cout << "Occorrenza del carattere '" << searchChar << "': " << occurrence << endl;

    char charToRemove;
    cout << "Inserisci il carattere da rimuovere: ";
    cin >> charToRemove;

    // Chiamiamo il metodo removeCharacter per rimuovere il carattere
    myHash.removeCharacter(charToRemove);

    // Ora puoi chiamare il metodo searchCharacter per verificare se il carattere è stato rimosso
    int occurrence1 = myHash.searchCharacter(charToRemove);
    if (occurrence1 == 0) {
        cout << "Il carattere '" << charToRemove << "' è stato rimosso dalla tabella hash." << endl;
    } else {
        cout << "Il carattere '" << charToRemove << "' è ancora presente nella tabella hash con " << occurrence1 << " occorrenza(e)." << endl;
    }

    cout << "Tabella hash:" << endl;
    for (const auto& bucket : myHash.getTable()) {
        for (const auto& element : bucket) {
            cout << "Carattere: " << element.key << " Occorrenza: " << element.value << endl;
        }
    }

    return 0;
}
