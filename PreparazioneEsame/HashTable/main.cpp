//
// Created by vincenzo on 27/09/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class HashElement {
public:
    char key;
    int value;
    HashElement(char k, int v) : key(k), value(v) { }
};

class HashTable {
private:
    vector<list<HashElement>> table;
    int size;

    int hash(char key) {
        return static_cast<int>(key) % size;
    }
public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }

    void insert(char key, int value) {
        int index = hash(key);
        table[index].push_back(HashElement(key, value));
    }

    // Metodo per incrementare l'occorrenza di un carattere
    void increment(char key) {
        int index = hash(key);
        for (auto& element : table[index]) {
            if (element.key == key) {
                element.value++;
                return;
            }
        }
        // Se il carattere non è stato trovato, lo inseriamo con valore 1
        insert(key, 1);
    }

    // Metodo per stampare la tabella hash su un file
    void printToFile(const string& filename) {
        ofstream outputFile(filename);
        if (!outputFile) {
            cerr << "Impossibile aprire il file " << filename << " per la scrittura" << endl;
            return;
        }

        for (const auto& bucket : table) {
            for (const auto& element : bucket) {
                outputFile << "Carattere: " << element.key << " Occorrenza: " << element.value << endl;
            }
        }

        outputFile.close();
    }

    int searchCharacter(char keyToFind) {
        int index = hash(keyToFind);
        for (const auto& element : table[index]) {
            if (element.key == keyToFind) {
                return element.value;
            }
        }
        return 0; // Ritorna 0 se il carattere non è stato trovato
    }

    void removeCharacter(char keyToRemove) {
        int index = hash(keyToRemove);
        auto& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == keyToRemove) {
                bucket.erase(it);
                return; // Rimuovi il carattere e termina
            }
        }
    }

    // Metodo pubblico per ottenere il contenuto della tabella hash
    vector<list<HashElement>> getTable() {
        return table;
    }
};

int main() {
    HashTable hashTable(256); // Usiamo una dimensione di 256 per coprire tutti i possibili caratteri ASCII

    ifstream inputFile("IN.txt");
    if (!inputFile) {
        cerr << "Impossibile aprire il file 'IN.txt'" << endl;
        return 1;
    }

    char character;
    while (inputFile.get(character)) {
        // Per ogni carattere letto dal file, incrementiamo l'occorrenza nella tabella hash
        hashTable.increment(character);
    }

    inputFile.close();

    // Scriviamo la tabella hash su un file di output
    hashTable.printToFile("OUT.txt");

    cout << "Tabella hash scritta su 'OUT.txt'" << endl;

    // Richiedi all'utente di inserire il carattere da cercare
    char searchChar;
    cout << "Inserisci il carattere da cercare: ";
    cin >> searchChar;

    // Chiamiamo il metodo searchCharacter e stampiamo il risultato
    int occurrence = hashTable.searchCharacter(searchChar);
    cout << "Occorrenza del carattere '" << searchChar << "': " << occurrence << endl;

    char charToRemove;
    cout << "Inserisci il carattere da rimuovere: ";
    cin >> charToRemove;

    // Chiamiamo il metodo removeCharacter per rimuovere il carattere
    hashTable.removeCharacter(charToRemove);

    // Ora puoi chiamare il metodo searchCharacter per verificare se il carattere è stato rimosso
    int occurrence1 = hashTable.searchCharacter(charToRemove);
    if (occurrence1 == 0) {
        cout << "Il carattere '" << charToRemove << "' è stato rimosso dalla tabella hash." << endl;
    } else {
        cout << "Il carattere '" << charToRemove << "' è ancora presente nella tabella hash con " << occurrence1 << " occorrenza(e)." << endl;
    }

    // Stampiamo la tabella hash aggiornata
    vector<list<HashElement>> updatedTable = hashTable.getTable();

    cout << "Tabella hash aggiornata:" << endl;
    for (const auto& bucket : updatedTable) {
        for (const auto& element : bucket) {
            cout << "Carattere: " << element.key << " Occorrenza: " << element.value << endl;
        }
    }

    return 0;
}

